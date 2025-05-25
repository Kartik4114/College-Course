from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from qiskit.primitives import Sampler
from qiskit.circuit.library import GroverOperator
from qiskit.visualization import plot_histogram, circuit_drawer
import matplotlib.pyplot as plt

# Define a custom oracle for multiple solutions
def custom_oracle(n):
    oracle = QuantumCircuit(n)
    # Mark states |001> and |110> as solutions
    oracle.cz(0, 2)
    oracle.cz(1, 2)
    oracle.name = "Oracle"
    return oracle

# Set up the circuit for 3 qubits
n = 3
oracle = custom_oracle(n)

# Create the Grover diffusion operator
grover_operator = GroverOperator(oracle)

# Initialize Grover's search circuit
iterations = 3  # Number of iterations for Grover's algorithm
qc = QuantumCircuit(n)
qc.h(range(n))  # Initial Hadamard gates for superposition

# Apply Grover iterations
for _ in range(iterations):
    qc.append(oracle, range(n))
    qc.append(grover_operator, range(n))

# Measure all qubits
qc.measure_all()

# Visualize the quantum circuit
circuit_diagram = circuit_drawer(qc, output='mpl')
plt.show()

# Use Sampler to simulate and get results
sampler = Sampler()
backend = Aer.get_backend('aer_simulator')
transpiled_qc = transpile(qc, backend)
result = sampler.run(transpiled_qc).result()
counts = result.quasi_dists[0].binary_probabilities()

# Display the results
plot_histogram(counts)
plt.show()