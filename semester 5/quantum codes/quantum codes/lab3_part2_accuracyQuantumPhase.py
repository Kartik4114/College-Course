# Import required libraries
from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from numpy import pi
import matplotlib.pyplot as plt

# Define the phase theta we want to estimate
theta = 1/3  # Let's assume we want to estimate theta = 1/3

# Create quantum circuit for QPE with 3 qubits for estimation and 1 target qubit
qpe_circuit = QuantumCircuit(4, 3)

# Prepare the eigenvector |psi> (the last qubit)
qpe_circuit.h([0, 1, 2])  # Apply Hadamard gates to the first 3 qubits
qpe_circuit.x(3)          # Set the target qubit to |1>

# Apply controlled-U gates
qpe_circuit.cp(2 * pi * theta, 0, 3)  # Controlled-U with theta applied to qubit 0
qpe_circuit.cp(4 * pi * theta, 1, 3)  # Controlled-U^2 with theta applied to qubit 1
qpe_circuit.cp(8 * pi * theta, 2, 3)  # Controlled-U^4 with theta applied to qubit 2

# Inverse Quantum Fourier Transform (simplified for 3 qubits)
qpe_circuit.h(2)
qpe_circuit.cp(-pi/2, 1, 2)  # Controlled Phase shift between qubit 1 and qubit 2
qpe_circuit.h(1)
qpe_circuit.cp(-pi/4, 0, 2)  # Controlled Phase shift between qubit 0 and qubit 2
qpe_circuit.cp(-pi/2, 0, 1)  # Controlled Phase shift between qubit 0 and qubit 1
qpe_circuit.h(0)

# Measure the first three qubits
qpe_circuit.measure([0, 1, 2], [0, 1, 2])

# Transpile the circuit for the 'qasm_simulator' backend
simulator = Aer.get_backend('qasm_simulator')
transpiled_circuit = transpile(qpe_circuit, simulator)

# Plot the transpiled quantum circuit using matplotlib
fig, ax = plt.subplots(figsize=(12, 6))
qpe_circuit.draw(output='mpl', ax=ax)
plt.title('Quantum Phase Estimation Circuit (Transpiled)')
plt.show()
