from qiskit import QuantumCircuit
from qiskit.primitives import Sampler
import numpy as np
import matplotlib.pyplot as plt

# Define the Quantum Fourier Transform (QFT)
def qft(circuit, n):
    for j in range(n):
        circuit.h(j)
        for k in range(j + 1, n):
            circuit.cp(np.pi / 2 ** (k - j), k, j)
    circuit.barrier()

# Quantum period finding circuit
def quantum_period_finding():
    n = 3
    qc = QuantumCircuit(n)
    
    # Apply Hadamard to each qubit
    qc.h(range(n))
    
    # Quantum Fourier Transform for period finding
    qft(qc, n)
    
    # Measure all qubits
    qc.measure_all()
    
    # Use the Sampler to run the circuit and get results
    sampler = Sampler()
    job = sampler.run(qc)
    result = job.result()
    counts = result.quasi_dists[0]  # Get the measurement distribution
    
    return counts

# Run the quantum period finding example
counts = quantum_period_finding()
print("Measurement counts from period finding:", counts)

# Plot the measurement results
plt.figure(figsize=(8, 5))
plt.bar(counts.keys(), counts.values(), color='blue')
plt.xlabel("Measured State")
plt.ylabel("Probability")
plt.subplots_adjust(top=0.85, bottom=0.2)  # Adjust to make space for the title
plt.figtext(0.5, 0.05, "Measurement Results for Quantum Period Finding", ha="center", fontsize=14)
plt.xticks(rotation=45)
plt.grid(axis='y')
plt.show()