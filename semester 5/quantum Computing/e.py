# Import required libraries
from qiskit import QuantumCircuit, transpile, assemble
from qiskit_aer import Aer
from numpy import pi
from qiskit.visualization import plot_histogram, plot_circuit_layout
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

# Assemble and run the simulation
qobj = assemble(transpiled_circuit)
result = simulator.run(qobj).result()

# Get the measurement results
counts = result.get_counts()

# Create a figure with subplots using matplotlib
fig, axs = plt.subplots(3, 1, figsize=(10, 15))

# Plot the quantum circuit
qpe_circuit.draw(output='mpl', ax=axs[0])
axs[0].set_title('Quantum Circuit Diagram')

# Plot the layout of the transpiled circuit
plot_circuit_layout(transpiled_circuit, simulator, ax=axs[1])
axs[1].set_title('Transpiled Circuit Layout')

# Plot the measurement histogram
plot_histogram(counts, ax=axs[2])
axs[2].set_title('Measurement Results')

# Display the full plot
plt.tight_layout()
plt.show()
