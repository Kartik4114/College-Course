import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

class BFR:
    def __init__(self, n_clusters, threshold, merge_threshold, batch_size=100):
        self.n_clusters = n_clusters
        self.threshold = threshold
        self.merge_threshold = merge_threshold
        self.batch_size = batch_size
        self.cluster_summaries = {}
        self.discard_set = []    # Discard set (DS)
        self.compression_set = [] # Compression set (CS)
        self.retained_set = []    # Retained set (RS)
        self.centroids = []       # Store centroids for visualization
        self.iteration = 0        # Track iterations

    def initialize_clusters(self, data):
        centroids = data[np.random.choice(data.shape[0], self.n_clusters, replace=False)]
        for i in range(self.n_clusters):
            self.cluster_summaries[i] = {
                "N": 0,
                "SUM": np.zeros(data.shape[1]),
                "SUMSQ": np.zeros(data.shape[1]),
                "centroid": centroids[i]
            }
        self.centroids = centroids

    def update_cluster_summary(self, cluster_id, point):
        summary = self.cluster_summaries[cluster_id]
        summary["N"] += 1
        summary["SUM"] += point
        summary["SUMSQ"] += point ** 2
        summary["centroid"] = summary["SUM"] / summary["N"]

    def mahalanobis_distance(self, point, centroid, cluster_id):
        summary = self.cluster_summaries[cluster_id]
        if summary["N"] > 1:
            variance = summary["SUMSQ"] / summary["N"] - (summary["SUM"] / summary["N"]) ** 2
            variance[variance == 0] = 1e-10  # Avoid division by zero
            distance = np.sum((point - centroid) ** 2 / variance)
            return np.sqrt(distance)
        else:
            return float("inf")

    def assign_point_to_cluster(self, point):
        min_dist = float("inf")
        best_cluster = None
        for cluster_id in self.cluster_summaries.keys():
            dist = self.mahalanobis_distance(point, self.cluster_summaries[cluster_id]["centroid"], cluster_id)
            if dist < min_dist and dist < self.threshold:
                min_dist = dist
                best_cluster = cluster_id
        return best_cluster

    def merge_clusters(self):
        cluster_ids = list(self.cluster_summaries.keys())
        merged = set()
        for i in range(len(cluster_ids)):
            if cluster_ids[i] in merged:
                continue
            for j in range(i + 1, len(cluster_ids)):
                id1, id2 = cluster_ids[i], cluster_ids[j]
                if id2 in merged:
                    continue
                centroid1 = self.cluster_summaries[id1]["centroid"]
                centroid2 = self.cluster_summaries[id2]["centroid"]
                dist = np.linalg.norm(centroid1 - centroid2)
                if dist < self.merge_threshold:
                    # Merge clusters
                    self.cluster_summaries[id1]["N"] += self.cluster_summaries[id2]["N"]
                    self.cluster_summaries[id1]["SUM"] += self.cluster_summaries[id2]["SUM"]
                    self.cluster_summaries[id1]["SUMSQ"] += self.cluster_summaries[id2]["SUMSQ"]
                    self.cluster_summaries[id1]["centroid"] = self.cluster_summaries[id1]["SUM"] / self.cluster_summaries[id1]["N"]
                    del self.cluster_summaries[id2]
                    merged.add(id2)

    def fit(self, data):
        self.initialize_clusters(data[:self.batch_size])
        for batch_start in range(0, data.shape[0], self.batch_size):
            batch = data[batch_start: batch_start + self.batch_size]
            for point in batch:
                cluster_id = self.assign_point_to_cluster(point)
                if cluster_id is not None:
                    self.update_cluster_summary(cluster_id, point)
                    self.discard_set.append(point)  # Assign to Discard Set
                else:
                    # If no cluster is assigned, check for Compression Set or Retained Set
                    if len(self.compression_set) < self.n_clusters:
                        self.compression_set.append(point)  # Assign to Compression Set
                    else:
                        self.retained_set.append(point)  # Assign to Retained Set
            self.merge_clusters()
            self.centroids = self.get_cluster_centroids()  # Update centroids after merging
            
            # Increment iteration and visualize the state
            self.iteration += 1
            self.visualize_state(self.iteration)

    def get_cluster_centroids(self):
        return np.array([summary["centroid"] for summary in self.cluster_summaries.values()])

    def visualize_state(self, iteration):
        plt.figure(figsize=(10, 6))
        # Plot Discard Set
        if self.discard_set:
            discarded_points = np.array(self.discard_set)
            plt.scatter(discarded_points[:, 0], discarded_points[:, 1], color='blue', s=10, label='Discard Set (DS)')
        # Plot Compression Set
        if self.compression_set:
            compressed_points = np.array(self.compression_set)
            plt.scatter(compressed_points[:, 0], compressed_points[:, 1], color='green', s=10, label='Compression Set (CS)')
        # Plot Retained Set
        if self.retained_set:
            retained_points = np.array(self.retained_set)
            plt.scatter(retained_points[:, 0], retained_points[:, 1], color='red', s=10, label='Retained Set (RS)')
        # Plot Centroids
        plt.scatter(self.centroids[:, 0], self.centroids[:, 1], color='black', marker='X', s=100, label='Centroids')
        
        plt.title(f"BFR Clustering Iteration {iteration}")
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.legend()
        plt.grid()
        plt.show()

# Generate synthetic data for BFR clustering
def generate_data(n_samples=1000, n_clusters=3, cluster_std=1.0, outlier_ratio=0.1):
    # Create clustered data
    X, _ = make_blobs(n_samples=int(n_samples * (1 - outlier_ratio)), centers=n_clusters, cluster_std=cluster_std, random_state=42)

    # Generate outliers (far away points)
    outliers = np.random.uniform(low=-10, high=10, size=(int(n_samples * outlier_ratio), 2))

    # Combine the two sets
    data = np.vstack((X, outliers))
    np.random.shuffle(data)  # Shuffle the dataset
    return data

# Parameters
n_samples = 1000
n_clusters = 3
cluster_std = 1.0
outlier_ratio = 0.1  # 10% of points will be outliers

# Generate data
data = generate_data(n_samples, n_clusters, cluster_std, outlier_ratio)

# Save the data to a text file for use in the BFR algorithm
np.savetxt('test.txt', data, delimiter=',')

# Create and fit the BFR model
bfr = BFR(n_clusters=3, threshold=3.0, merge_threshold=1.5, batch_size=100)
bfr.fit(data)
