# Import required libraries
from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from numpy import pi
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

# Define the unitary operator (U)
theta = 1/4  # The phase theta we want to estimate (e.g., 1/4)

# Create quantum circuit for QPE with 2 qubits for estimation and 1 target qubit
qpe_circuit = QuantumCircuit(3, 2)

# Prepare the eigenvector |psi> (the last qubit)
qpe_circuit.h([0, 1])  # Apply Hadamard gates to the first 2 qubits
qpe_circuit.x(2)       # Set the target qubit to |1>

# Apply controlled-U gates
qpe_circuit.cp(2 * pi * theta, 0, 2)  # Controlled-U with theta applied to qubit 0
qpe_circuit.cp(4 * pi * theta, 1, 2)  # Controlled-U^2 with theta applied to qubit 1

# Inverse Quantum Fourier Transform (simplified for 2 qubits)
qpe_circuit.h(1)
qpe_circuit.cp(-pi/2, 0, 1)  # Controlled Phase shift between qubit 0 and qubit 1
qpe_circuit.h(0)

# Measure the first two qubits
qpe_circuit.measure([0, 1], [0, 1])

# Transpile the circuit for the 'qasm_simulator' backend
simulator = Aer.get_backend('qasm_simulator')
transpiled_circuit = transpile(qpe_circuit, simulator)

# Plot the quantum circuit using matplotlib
fig, ax = plt.subplots(figsize=(10, 5))
qpe_circuit.draw(output='mpl', ax=ax)  # Draw the circuit on the specified axes
plt.title('Quantum Phase Estimation Circuit')
plt.show()
