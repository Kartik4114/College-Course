from qiskit import QuantumCircuit, transpile
from qiskit_aer import Aer
from qiskit.visualization import plot_histogram
import matplotlib.pyplot as plt

# Create a circuit for the three-qubit bit-flip code
qc = QuantumCircuit(5, 2)  # 3 data qubits + 2 ancilla for syndrome measurement

# Encode |0⟩ state with redundancy: |0_L⟩ = |000⟩
qc.h(0)  # Prepare superposition state to test error correction
qc.cx(0, 1)
qc.cx(0, 2)

# Introduce an artificial bit-flip error on one qubit
qc.x(1)  # Flipping the second qubit to simulate an error

# Syndrome measurement to detect the error
qc.cx(0, 3)
qc.cx(1, 3)
qc.cx(0, 4)
qc.cx(2, 4)
qc.measure(3, 0)
qc.measure(4, 1)

# Visualize the circuit
qc.draw('mpl')
plt.show()

# Simulate and get results
backend = Aer.get_backend('aer_simulator')
transpiled_qc = transpile(qc, backend)
result = backend.run(transpiled_qc).result()
counts = result.get_counts()
plot_histogram(counts)
plt.show()