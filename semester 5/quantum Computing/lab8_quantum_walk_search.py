from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt
import numpy as np

# Function to create the Grover diffusion operator
def diffusion_operator(n_qubits):
    qc = QuantumCircuit(n_qubits)
    qc.h(range(n_qubits))
    qc.x(range(n_qubits))
    qc.h(n_qubits - 1)
    qc.mcx(list(range(n_qubits - 1)), n_qubits - 1)  # Multi-controlled Toffoli
    qc.h(n_qubits - 1)
    qc.x(range(n_qubits))
    qc.h(range(n_qubits))
    return qc.to_gate(label="Diffusion")

# Function to create the oracle (marks the solution state)
def oracle(n_qubits, marked_state):
    qc = QuantumCircuit(n_qubits)
    marked_state_bin = format(marked_state, f'0{n_qubits}b')
    for i, bit in enumerate(marked_state_bin):
        if bit == '0':
            qc.x(i)
    qc.h(n_qubits - 1)
    qc.mcx(list(range(n_qubits - 1)), n_qubits - 1)  # Multi-controlled Toffoli
    qc.h(n_qubits - 1)
    for i, bit in enumerate(marked_state_bin):
        if bit == '0':
            qc.x(i)
    return qc.to_gate(label="Oracle")

# Number of qubits and target state
n_qubits = 3  # Number of qubits
marked_state = 3  # Target state (e.g., |011⟩ -> decimal 3)

# Quantum Circuit for Quantum Walk Search
qc = QuantumCircuit(n_qubits)

# Initial superposition
qc.h(range(n_qubits))

# Visualize the quantum circuit after initial Hadamard gates
print("Quantum Circuit After Initial Superposition:")

# Render the quantum circuit in a matplotlib figure and display
fig = qc.draw(output='mpl')

# Display the circuit plot
plt.show()  # This will display the quantum circuit

# Number of Grover iterations
num_iterations = int(np.pi / 4 * np.sqrt(2 ** n_qubits))

for _ in range(num_iterations):
    # Apply oracle
    qc.append(oracle(n_qubits, marked_state), range(n_qubits))
    # Apply diffusion operator
    qc.append(diffusion_operator(n_qubits), range(n_qubits))

# Measurement
qc.measure_all()

# Simulate the circuit using AerSimulator
simulator = Aer.get_backend('aer_simulator')
transpiled_qc = transpile(qc, simulator)
result = simulator.run(transpiled_qc, shots=1024).result()
counts = result.get_counts()

# Plot the measurement results (final state probabilities)
print("Measurement Results:", counts)
plot_histogram(counts)
plt.show()
