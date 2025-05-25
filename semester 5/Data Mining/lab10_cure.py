import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.cluster import AgglomerativeClustering
from scipy.spatial.distance import cdist
import time

# Function to generate unorganized random points
def generate_data(n_samples=500, n_features=2, n_clusters=4, cluster_std=3.0):
    # Unorganized data using random points with noise
    np.random.seed(42)
    X = np.random.randn(n_samples, n_features) * cluster_std + np.random.randn(n_samples, n_features) * 2
    return X

# CURE algorithm with dynamic visualization
class CURE:
    def __init__(self, n_clusters=3, representative_points=5, shrink_factor=0.1, outlier_threshold=2.5):
        self.n_clusters = n_clusters
        self.representative_points = representative_points
        self.shrink_factor = shrink_factor  # Increased shrink factor
        self.outlier_threshold = outlier_threshold
        self.iterations = []
    
    def fit(self, X):
        # Step 1: Apply Agglomerative Clustering initially
        clustering = AgglomerativeClustering(n_clusters=self.n_clusters).fit(X)
        self.labels = clustering.labels_
        self.representatives = []
        self.centroids = []
        
        # Find the centroid of each cluster
        for i in range(self.n_clusters):
            cluster_points = X[self.labels == i]
            centroid = np.mean(cluster_points, axis=0)
            self.centroids.append(centroid)
            
            # Step 2: Select representative points progressively
            representatives = []
            
            # 1st representative point - farthest from centroid
            distances = cdist(cluster_points, [centroid], 'euclidean').flatten()
            first_rep_idx = np.argmax(distances)
            representatives.append(cluster_points[first_rep_idx])
            
            # 2nd representative point - farthest from the already selected representative point
            distances = cdist(cluster_points, [representatives[0]], 'euclidean').flatten()
            second_rep_idx = np.argmax(distances)
            representatives.append(cluster_points[second_rep_idx])
            
            # 3rd representative point - farthest from the centroid of the first two points
            avg_centroid = np.mean(representatives, axis=0)
            distances = cdist(cluster_points, [avg_centroid], 'euclidean').flatten()
            third_rep_idx = np.argmax(distances)
            representatives.append(cluster_points[third_rep_idx])
            
            # 4th representative point - farthest from the average of the first three
            avg_centroid = np.mean(representatives, axis=0)
            distances = cdist(cluster_points, [avg_centroid], 'euclidean').flatten()
            fourth_rep_idx = np.argmax(distances)
            representatives.append(cluster_points[fourth_rep_idx])
            
            # 5th representative point - farthest from the average of the first four
            avg_centroid = np.mean(representatives, axis=0)
            distances = cdist(cluster_points, [avg_centroid], 'euclidean').flatten()
            fifth_rep_idx = np.argmax(distances)
            representatives.append(cluster_points[fifth_rep_idx])
            
            # Add representatives to the list
            self.representatives.append(representatives)
        
        # Plot all clusters' representatives and shrinking simultaneously
        self.plot_initial_representatives(X)
        
        # Shrink representatives progressively across all clusters
        self.shrink_representatives(X)
        
        # Plot the final clustering result
        self.plot_clusters(X, "Final Clustering with Shrunk Representative Points")
    
    def plot_initial_representatives(self, X):
        plt.figure(figsize=(8, 6))
        plt.scatter(X[:, 0], X[:, 1], c=self.labels, cmap='viridis', marker='o', alpha=0.4)
        
        # Plot initial representative points (before shrinking)
        for i, representatives in enumerate(self.representatives):
            for rep in representatives:
                plt.scatter(rep[0], rep[1], s=100, marker='*', color='red')  # Initial representative points
        
        plt.title("Initial Representative Points for All Clusters")
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.legend()
        plt.show()

    def shrink_representatives(self, X):
        for step in range(5):  # Reduced steps to 5 for faster shrinking
            plt.figure(figsize=(8, 6))
            plt.scatter(X[:, 0], X[:, 1], c=self.labels, cmap='viridis', marker='o', alpha=0.4)
            
            # Plot centroids
            for i, centroid in enumerate(self.centroids):
                plt.scatter(centroid[0], centroid[1], c='black', s=200, marker='x', label=f'Centroid {i + 1}')
            
            # Shrink all representative points across all clusters
            for i, representatives in enumerate(self.representatives):
                for j, point in enumerate(representatives):
                    # Gradual shrinking: Shrink by a fraction of the distance towards centroid
                    centroid = self.centroids[i]
                    representatives[j] = point + self.shrink_factor * (centroid - point)
                    
                    # Plot shrunk representative points
                    plt.scatter(representatives[j][0], representatives[j][1], s=100, marker='*', color='red')  # Shrunk points
            
            plt.title(f"Step {step + 1}: Shrunk Representative Points")
            plt.xlabel("Feature 1")
            plt.ylabel("Feature 2")
            plt.legend()
            plt.show()

    def plot_clusters(self, X, title):
        plt.figure(figsize=(8, 6))
        plt.scatter(X[:, 0], X[:, 1], c=self.labels, cmap='viridis', marker='o', alpha=0.4)
        
        # Plot centroids
        for i, centroid in enumerate(self.centroids):
            plt.scatter(centroid[0], centroid[1], c='black', s=200, marker='x', label=f'Centroid {i + 1}')
        
        # Plot all representative points with the same color (shrunk points)
        for i, representatives in enumerate(self.representatives):
            for rep in representatives:
                plt.scatter(rep[0], rep[1], s=100, marker='*', color='red')  # All representative points with same color
        
        plt.title(title)
        plt.xlabel("Feature 1")
        plt.ylabel("Feature 2")
        plt.legend()
        plt.show()

# Data generation: create a more unorganized 2D dataset
X = generate_data(n_samples=2000, n_features=2, n_clusters=4, cluster_std=2.0)

# Initialize and fit CURE algorithm
cure = CURE(n_clusters=4, representative_points=5, shrink_factor=0.1, outlier_threshold=2.5)
cure.fit(X)
