import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from scipy.spatial.distance import pdist, squareform
import seaborn as sns
from scipy.cluster.hierarchy import linkage, fcluster
import numpy as np

def plot_clusters(X, cluster_labels, title):
    colors = plt.cm.get_cmap('tab10', len(np.unique(cluster_labels)))  # Get distinct colors
    plt.figure(figsize=(8, 6))
    plt.scatter(X[:, 0], X[:, 1], c=[colors(label % len(np.unique(cluster_labels))) for label in cluster_labels], marker='o', s=50)
    plt.title(title)
    plt.xlabel('Feature 1')
    plt.ylabel('Feature 2')
    plt.show()

# Dataset Generation
n_samples = 100  # Number of data points
n_features = 2  # Number of features (2D)
centers = 5  # Initial number of clusters
cluster_std = 1.0  # Standard deviation of the clusters

# Generating synthetic dataset
X, _ = make_blobs(n_samples=n_samples, centers=centers, n_features=n_features, cluster_std=cluster_std, random_state=42)

# Get user input for the linkage method
print("Select the linkage method:")
print("1: Single Linkage")
print("2: Complete Linkage")
print("3: Average Linkage")
choice = int(input("Enter your choice (1/2/3): "))

# Step 1: Scatter Plot - Display the dataset
plt.figure(figsize=(8, 6))
plt.scatter(X[:, 0], X[:, 1], c='gray', marker='o', s=50)
plt.title('Initial Dataset')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.show()

# Step 2: Compute and display the Distance Matrix Heatmap
dist_matrix = squareform(pdist(X, metric='euclidean'))

plt.figure(figsize=(10, 8))
sns.heatmap(dist_matrix, cmap='hot', cbar=True)
plt.title('Distance Matrix Heatmap')
plt.xlabel('Point Index')
plt.ylabel('Point Index')
plt.show()

# Step 3: Select the linkage method based on user input
if choice == 1:
    method = 'single'
    linkage_title = "Single Linkage Clustering"
elif choice == 2:
    method = 'complete'
    linkage_title = "Complete Linkage Clustering"
elif choice == 3:
    method = 'average'
    linkage_title = "Average Linkage Clustering"
else:
    print("Invalid choice. Exiting.")
    exit()

# Step 4: Linkage matrix and iterative clustering visualization
linkage_matrix = linkage(X, method=method)

# Initial number of clusters
num_clusters = n_samples  # Start with each point as its own cluster
stop_clusters = 5  # User-defined final number of clusters

while num_clusters > stop_clusters:  # Continue until the number of clusters reaches the limit
    # Assign cluster labels
    cluster_labels = fcluster(linkage_matrix, num_clusters, criterion='maxclust')
    
    # Plot the clustering result
    plot_clusters(X, cluster_labels, f'{linkage_title} (Number of Clusters: {num_clusters})')

    # Halve the number of clusters for the next iteration
    num_clusters = max(stop_clusters, num_clusters // 2)  # Ensure at least stop_clusters is maintained

# Final clusters depiction at the user-defined number of clusters
cluster_labels = fcluster(linkage_matrix, stop_clusters, criterion='maxclust')
plot_clusters(X, cluster_labels, f'Final Clustering Result (Number of Clusters: {stop_clusters})')