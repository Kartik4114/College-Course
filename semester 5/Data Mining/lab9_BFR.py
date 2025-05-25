import random
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
from scipy.spatial.distance import mahalanobis

MAX_POINTS = 1000
points = np.random.rand(MAX_POINTS, 2)
num_clusters = 6

# Parameters for BFR
point_per_chunk = 200
compressed_set = []
discard_set = []
retained_set = []
discard_points = []  # To store actual discard points for visualization

# Function to run KMeans clustering and update sets
def bfr(points, num_clusters):
    kmeans = KMeans(n_clusters=num_clusters)
    kmeans.fit(points)

    # Get cluster centers and labels
    centers = kmeans.cluster_centers_
    labels = kmeans.labels_

    return centers, labels

# Process points in chunks
for i in range(0, len(points), point_per_chunk):
    points_processed = points[i:i + point_per_chunk]

    if i == 0:
        # First chunk, initialize the compressed set
        centers, labels = bfr(points_processed, num_clusters)
        compressed_set.extend(centers)
        retained_set.extend(points_processed)
    else:
        # Process subsequent chunks
        centers, labels = bfr(points_processed, num_clusters)
        # Initialize data structures for summarization
        discard_summary = {j: {'N': 0, 'SUM': np.zeros(2), 'SUMSQ': np.zeros(2)} for j in range(num_clusters)}

        for j in range(num_clusters):
            # Find points that belong to the current cluster
            cluster_points = points_processed[labels == j]
            if len(cluster_points) > 0:
                # Add to retained set
                retained_set.extend(cluster_points)
                # Add center to compressed set
                compressed_set.append(centers[j])

                # Calculate discard points
                for point in points_processed:
                    distance = mahalanobis(point, centers[j], np.linalg.inv(np.cov(points_processed.T)))
                    if distance < 0.5:  # Threshold for closeness
                        discard_summary[j]['N'] += 1
                        discard_summary[j]['SUM'] += point
                        discard_summary[j]['SUMSQ'] += point ** 2
                    else:
                        discard_points.append(point)  # Store actual discard points
            else:
                # If no points belong to this cluster, we might consider the center for discard
                discard_set.append(centers[j])

        # Update discard set based on summarization
        for j in range(num_clusters):
            N = discard_summary[j]['N']
            if N > 0:
                SUM = discard_summary[j]['SUM']
                SUMSQ = discard_summary[j]['SUMSQ']
                variance = (SUMSQ / N) - (SUM / N) ** 2
                stddev = np.sqrt(variance)

                # Store the summarized statistics for the discard set
                discard_set.append({
                    'center': centers[j],
                    'count': N,
                    'sum': SUM,
                    'sum_sq': SUMSQ,
                    'variance': variance,
                    'stddev': stddev
                })

# Convert to numpy arrays for ease of use
compressed_set = np.array(compressed_set)
retained_set = np.array(retained_set)
discard_points = np.array(discard_points)

# Visualizing each set sequentially

# Original Points
plt.figure(figsize=(8, 6))
plt.scatter(points[:, 0], points[:, 1], s=10, alpha=0.5)
plt.title('Original Points')
plt.show()

# Compressed Set (Cluster Centers)
plt.figure(figsize=(8, 6))
plt.scatter(compressed_set[:, 0], compressed_set[:, 1], s=100, alpha=0.5, color='red', marker='X')
plt.title('Compressed Set (Cluster Centers)')
plt.show()

# Discard Points
plt.figure(figsize=(8, 6))
plt.scatter(discard_points[:, 0], discard_points[:, 1], s=10, alpha=0.5, color='orange')
plt.title('Discard Points')
plt.show()

# Retained Points
plt.figure(figsize=(8, 6))
plt.scatter(retained_set[:, 0], retained_set[:, 1], s=10, alpha=0.5, color='blue')
plt.title('Retained Points')
plt.show()

# Visualizing all sets merged
plt.figure(figsize=(12, 8))
plt.scatter(points[:, 0], points[:, 1], s=10, alpha=0.3, label='Original Points', color='gray')
plt.scatter(retained_set[:, 0], retained_set[:, 1], s=10, alpha=0.5, color='blue', label='Retained Points')
plt.scatter(compressed_set[:, 0], compressed_set[:, 1], s=100, alpha=0.7, color='red', marker='X', label='Compressed Set (Centers)')
plt.scatter(discard_points[:, 0], discard_points[:, 1], s=10, alpha=0.5, color='orange', label='Discard Points')

plt.title('Merged Visualization of All Sets')
plt.legend()
plt.show()

# Display statistics for discard set
for cluster_info in discard_set:
    if isinstance(cluster_info, dict):  # Ensure we are processing a summarized discard set
        print(f"Cluster Center: {cluster_info['center']}, Count: {cluster_info['count']}, "
              f"Variance: {cluster_info['variance']}, Std Dev: {cluster_info['stddev']}")
