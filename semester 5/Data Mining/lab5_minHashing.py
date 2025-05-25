import numpy as np
import matplotlib.pyplot as plt

# Function to create a random hash function
def create_hash_function(num_hashes, num_elements):
    np.random.seed(42)  # For reproducibility
    a = np.random.randint(1, num_elements, num_hashes)
    b = np.random.randint(0, num_elements, num_hashes)
    return lambda x, i: (a[i] * x + b[i]) % num_elements

# Function to create the signature matrix
def generate_signature_matrix(sets, num_hashes):
    num_elements = max(max(s) for s in sets) + 1
    hash_func = create_hash_function(num_hashes, num_elements)
    
    signature_matrix = np.full((num_hashes, len(sets)), np.inf)
    
    for row in range(num_elements):
        for col, doc_set in enumerate(sets):
            if row in doc_set:
                for i in range(num_hashes):
                    hash_value = hash_func(row, i)
                    if hash_value < signature_matrix[i, col]:
                        signature_matrix[i, col] = hash_value
                        
    return signature_matrix

# Function to calculate MinHash similarity from signature matrix
def minhash_similarity(signature_matrix):
    num_docs = signature_matrix.shape[1]
    similarities = np.zeros((num_docs, num_docs))
    
    for i in range(num_docs):
        for j in range(i, num_docs):
            similarities[i, j] = np.mean(signature_matrix[:, i] == signature_matrix[:, j])
            similarities[j, i] = similarities[i, j]  # Symmetric matrix
    
    return similarities

# Example sets (documents represented as sets of integers)
sets = [
    {2, 4, 3},
    {3, 2, 4},
    {7, 1, 7},
    {6, 3, 2},
    {1, 6, 6},
    {5, 7, 1},
    {4, 5, 5}
]

# Parameters
num_hashes = 3  # Reduced number of hash functions

# Generate the signature matrix
signature_matrix = generate_signature_matrix(sets, num_hashes)

# Print the signature matrix
print("Signature Matrix:")
print(signature_matrix.astype(int))  # Cast to int for readability

# Compute MinHash similarity
similarities = minhash_similarity(signature_matrix)

# Plotting the similarity matrix
plt.figure(figsize=(8, 6))
plt.imshow(similarities, cmap='viridis', interpolation='nearest')
plt.colorbar(label='Similarity')
plt.title('MinHash Similarity Between Documents')
plt.xlabel('Document Index')
plt.ylabel('Document Index')
plt.show()
