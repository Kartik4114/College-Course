from qiskit import QuantumCircuit , execute
from qiskit_aer  import Aer 
from qiskit.visualization import plot_histogram, circuit_drawer
from qiskit.circuit.library import MCXGate
import matplotlib.pyplot as plt

# Create a 3-qubit quantum circuit for Grover's search
n = 3  # Number of qubits
qc = QuantumCircuit(n)

# Apply Hadamard gates to create a superposition
qc.h(range(n))

# Example oracle for marking the state |101>
qc.cz(0, 2)

# Apply the diffusion operator (inversion about the mean)
qc.h(range(n))
qc.x(range(n))
qc.h(n - 1)

# Add a multi-controlled Toffoli gate using MCXGate
mct_gate = MCXGate(num_ctrl_qubits=n-1)  # Create an MCX gate with (n-1) control qubits
qc.append(mct_gate, range(n))  # Append the gate to the circuit

qc.h(n - 1)
qc.x(range(n))
qc.h(range(n))

# Measure the qubits
qc.measure_all()

# Visualize the quantum circuit
circuit_diagram = circuit_drawer(qc, output='mpl')
plt.show()  # Display the circuit diagram

# Use Aer simulator to simulate and get results
simulator = Aer.get_backend('qasm_simulator')
job = execute(qc, backend=simulator, shots=1024)
result = job.result()
counts = result.get_counts()

# Plot and visualize the result
plot_histogram(counts)
plt.show()
