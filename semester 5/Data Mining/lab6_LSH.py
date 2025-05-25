import numpy as np
from collections import defaultdict
import matplotlib.pyplot as plt

# Provided signature matrix
signature_matrix = np.array([
    [1, 0, 9, 5],
    [1, 0, 2, 0],
    [1, 0, 7, 3],
    [3, 0, 4, 0],
    [0, 1, 8, 4],
    [0, 2, 6, 2]
])

# Function to calculate Jaccard similarity from MinHash signatures
def calculate_jaccard_similarity(sig1, sig2):
    matching_hashes = np.sum(sig1 == sig2)
    return matching_hashes / len(sig1)

# Locality-Sensitive Hashing (LSH) function
def apply_lsh(signatures, bands, rows):
    num_sets = signatures.shape[1]
    buckets = defaultdict(list)

    for b in range(bands):
        for i in range(num_sets):
            # Extract band signature
            band_signature = tuple(signatures[b * rows:(b + 1) * rows, i])
            # Append set index to the corresponding bucket
            buckets[band_signature].append(i)

    return buckets

# Function to calculate probability of sharing a bucket
def calc_probability(jaccard_similarity, r, b):
    return 1 - (1 - jaccard_similarity**r)**b

# Function to plot relationship between Jaccard similarity and LSH probability
def plot_similarity_vs_probability(jaccard_similarities, r, b):
    probabilities = [calc_probability(s, r, b) for s in jaccard_similarities]
    plt.plot(jaccard_similarities, probabilities, label='Probability of Sharing a Bucket', marker='o')
    plt.xlabel('Jaccard Similarity')
    plt.ylabel('Probability of Sharing a Bucket')
    plt.title(f'Relationship between Jaccard Similarity and LSH Probability (r={r}, b={b})')
    plt.axhline(y=0.5, color='r', linestyle='--', label='Threshold = 0.5')
    plt.grid(True)
    plt.legend()
    plt.show()

# Main logic
if __name__ == "__main__":
    rows = 2   # Rows per band
    bands = rows  # Set number of bands equal to rows

    # Step 1: Apply LSH to the signature matrix
    buckets = apply_lsh(signature_matrix, bands, rows)
    print("LSH Buckets:")
    for k, v in buckets.items():
        print(f"Bucket {k}: {v}")

    # Step 2: Calculate Jaccard similarities for all unique pairs
    num_sets = signature_matrix.shape[1]
    jaccard_similarities = []

    for i in range(num_sets):
        for j in range(i + 1, num_sets):
            jaccard_similarity = calculate_jaccard_similarity(signature_matrix[:, i], signature_matrix[:, j])
            jaccard_similarities.append(jaccard_similarity)

    # Print calculated Jaccard similarities
    print("Calculated Jaccard Similarities:", jaccard_similarities)

    # Step 3: Plot the relationship between Jaccard similarity and probability
    if jaccard_similarities:
        plot_similarity_vs_probability(sorted(set(jaccard_similarities)), r=rows, b=bands)
    else:
        print("No Jaccard similarities calculated.")
