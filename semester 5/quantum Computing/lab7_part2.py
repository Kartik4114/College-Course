from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

# Create a phase-flip code circuit (five qubits: 3 data qubits + 2 ancilla qubits)
qc = QuantumCircuit(5, 2)  # 3 data qubits + 2 ancilla qubits

# Encode the logical |0⟩ using a phase code: |0_L⟩ = (|000⟩ + |111⟩) / √2
qc.h(0)  # Apply Hadamard gate on qubit 0
qc.cx(0, 1)  # Apply CNOT gate between qubit 0 and qubit 1
qc.cx(0, 2)  # Apply CNOT gate between qubit 0 and qubit 2

# Introduce a phase-flip error on the third qubit (qubit 2)
qc.z(2)

# Syndrome measurement for phase-flip error detection
qc.h(0)
qc.h(1)
qc.h(2)
qc.cx(0, 3)
qc.cx(1, 3)
qc.cx(0, 4)
qc.cx(2, 4)
qc.h(0)
qc.h(1)
qc.h(2)

# Correct measurement of ancilla qubits
qc.measure(3, 0)  # Measure the ancilla qubit 3 to classical bit 0
qc.measure(4, 1)  # Measure the ancilla qubit 4 to classical bit 1

# Draw and display the circuit
qc.draw('mpl')
plt.show()

# Run simulation on the Aer simulator
backend = Aer.get_backend('aer_simulator')
transpiled_qc = transpile(qc, backend)
result = backend.run(transpiled_qc).result()
counts = result.get_counts()

# Plot the histogram of the results
plot_histogram(counts)
plt.show()
