from qiskit import QuantumCircuit
import numpy as np
import matplotlib.pyplot as plt

# Function to perform modular exponentiation
def modular_exponentiation(base, exponent, modulus):
    return pow(base, exponent, modulus)

# Function to demonstrate modular exponentiation and plot the results
def visualize_modular_exponentiation(base, max_exponent, modulus):
    # Initialize a sample quantum circuit (for illustration only, no quantum operations)
    quantum_circuit = QuantumCircuit(4)
    
    # Compute modular exponentiation for each exponent value from 0 to max_exponent
    results = [modular_exponentiation(base, exp, modulus) for exp in range(max_exponent + 1)]
    print(f"Results of modular exponentiation (base={base}, modulus={modulus}): {results}")
    
    # Visualize results with a plot
    plt.figure(figsize=(10, 6))
    plt.plot(range(max_exponent + 1), results, marker='o', linestyle='-', color='blue', 
             label=f"Mod Exp (base^x mod {modulus})")
    plt.xlabel("Exponent")
    plt.ylabel(f"Result of base^x mod {modulus}")
    plt.legend()
    plt.grid()
    
    # Show the plot
    plt.show()
    
    # Adding title below the plot
    plt.figtext(0.5, -0.05, f"Modular Exponentiation for base = {base}, modulus = {modulus}", 
                wrap=True, horizontalalignment='center', fontsize=12)

# Example usage
visualize_modular_exponentiation(base=2, max_exponent=10, modulus=15)
