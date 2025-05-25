from qiskit import QuantumCircuit, transpile
from qiskit_aer import AerSimulator
import numpy as np
import matplotlib.pyplot as plt

# Define the unitary operator (e.g., Pauli-Z gate with phase)
phi = 0.25  # Known phase to estimate (should be between 0 and 1)
unitary = QuantumCircuit(1)
unitary.p(2 * np.pi * phi, 0)  # Phase gate with known phase

# Iterative Quantum Phase Estimation
def iqpe(unitary, num_iterations):
    phase_estimate = 0
    estimated_phases = []  # List to track phase estimates across iterations
    actual_phase_fraction = phi / (2 * np.pi)  # Actual phase as a fraction of π
    
    for k in range(num_iterations):
        qc = QuantumCircuit(1, 1)
        
        # Step 1: Apply Hadamard to prepare superposition
        qc.h(0)
        
        # Step 2: Apply controlled unitary (U^(2^k))
        power_unitary = unitary.power(2 ** k)
        qc.append(power_unitary.to_instruction(), [0])
        
        # Step 3: Rotate ancilla qubit by phase angle and measure
        qc.p(-2 * np.pi * phase_estimate * (2 ** k), 0)
        qc.h(0)
        qc.measure(0, 0)
        
        # Transpile the circuit before running (optimizing for the simulator backend)
        qc_transpiled = transpile(qc, backend=AerSimulator())

        # Run the transpiled circuit on the simulator
        simulator = AerSimulator()
        result = simulator.run(qc_transpiled, shots=1024).result()  # Manual run without execute
        counts = result.get_counts()
        
        # Update phase estimate based on measurement result
        if '1' in counts and counts['1'] > counts.get('0', 0):
            phase_estimate += 1 / (2 ** (k + 1))
        
        # Append the estimated phase for this iteration
        estimated_phases.append(phase_estimate)

    return estimated_phases, actual_phase_fraction

# Run IQPE with 3 iterations to estimate phase
estimated_phases, actual_phase = iqpe(unitary, 3)

# Plotting the results
iterations = range(1, len(estimated_phases) + 1)
plt.figure(figsize=(8, 5))

# Plot the estimated phases
plt.plot(iterations, estimated_phases, marker='o', label="Estimated Phase", color='b')

# Plot the actual phase (constant line)
plt.axhline(y=actual_phase, color='r', linestyle='--', label="Actual Phase (φ=0.25)")

# Formatting the plot
plt.xlabel("Iteration")
plt.ylabel("Phase Estimate (fraction of π)")

plt.subplots_adjust(top=0.85, bottom=0.2)  # Adjust to make space for the title
plt.figtext(0.5, 0.05, "Convergence of Phase Estimate in IQPE", ha="center", fontsize=14)

plt.legend()
plt.grid(True)
plt.show() # Show the plot

# Print the final results
print(f"Estimated Phase after {len(estimated_phases)} iterations: {estimated_phases[-1]}")
print(f"Actual Phase (as fraction of π): {actual_phase}")