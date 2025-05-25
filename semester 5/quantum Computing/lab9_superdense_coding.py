from qiskit import QuantumCircuit
from qiskit_aer import Aer
from qiskit.visualization import plot_histogram, plot_bloch_multivector
import matplotlib.pyplot as plt

# Step 1: Create a Bell State (entangled state)
def create_bell_pair():
    qc = QuantumCircuit(2)
    qc.h(0) # Apply Hadamard gate to qubit 0
    qc.cx(0, 1) # Apply CNOT gate (control: qubit 0, target: qubit 1)
    return qc

# Step 2: Encode the message (classical bits) onto the Bell pair
def encode_message(qc, message):
    if message == "00":
        pass # Do nothing
    elif message == "01":
        qc.x(0) # Apply X gate
    elif message == "10":
        qc.z(0) # Apply Z gate
    elif message == "11":
        qc.x(0)
        qc.z(0)
    else:
        raise ValueError("Message must be one of '00', '01', '10', or '11'")

# Step 3: Decode the message by reversing the entanglement
def decode_message(qc):
    qc.cx(0, 1) # Apply CNOT gate (control: qubit 0, target: qubit 1)
    qc.h(0) # Apply Hadamard gate to qubit 0

# Main function to demonstrate superdense coding
def superdense_coding(message):
    if message not in ["00", "01", "10", "11"]:
        raise ValueError("Message must be one of '00', '01', '10', or '11'")
    
    # Step 1: Create a Bell pair
    qc = create_bell_pair()
    
    # Visualize the initial state of the qubits in the Bell state
    print("Initial Bell state (before encoding):")
    backend = Aer.get_backend('statevector_simulator')
    job = backend.run(qc)
    result = job.result()
    statevector = result.get_statevector(qc)
    plot_bloch_multivector(statevector)
    plt.title("Initial Bell State (Before Encoding)")
    plt.show()

    # Step 2: Encode the message
    encode_message(qc, message)
    
    # Visualize the state after encoding the classical message
    job = backend.run(qc)
    result = job.result()
    statevector = result.get_statevector(qc)
    plot_bloch_multivector(statevector)
    plt.title(f"State After Encoding Message {message}")
    plt.show()

    # Step 3: Decode the message
    decode_message(qc)
    
    # Visualize the state after decoding (before measurement)
    job = backend.run(qc)
    result = job.result()
    statevector = result.get_statevector(qc)
    plot_bloch_multivector(statevector)
    plt.title(f"State After Decoding Message {message}")
    plt.show()

    # Step 4: Measure the qubits
    qc.measure_all()

    # Simulate the circuit and get the results
    simulator = Aer.get_backend('qasm_simulator')
    job = simulator.run(qc, shots=1024)
    result = job.result()
    counts = result.get_counts(qc)
    
    return qc, counts

# Test the superdense coding protocol
message = "10" # Replace with "00", "01", "10", or "11"
qc, counts = superdense_coding(message)

# Display the quantum circuit and the result
print(f"Message sent: {message}")
print(f"Measurement result: {counts}")
qc.draw("mpl")

# Plot histogram of results
plot_histogram(counts)
plt.show()