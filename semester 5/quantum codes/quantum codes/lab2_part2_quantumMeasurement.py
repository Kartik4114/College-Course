from qiskit import QuantumCircuit, transpile
from qiskit.visualization import plot_histogram
from qiskit_aer import AerSimulator,Aer
import matplotlib.pyplot as plt

# Create a quantum circuit with 1 qubit and 1 classical bit
qc = QuantumCircuit(1, 1)

# Apply Hadamard gate to create superposition
qc.h(0)

# Measure the qubit
qc.measure(0, 0)

# Draw the circuit
qc.draw('mpl')

# Simulate the circuit using AerSimulator
backend = AerSimulator() 
compiled_circuit = transpile(qc, backend)
result = backend.run(compiled_circuit, shots=1024).result()

# Get the measurement counts
counts = result.get_counts()

# Plot the measurement result
plot_histogram(counts)
plt.show()

