import random
import matplotlib.pyplot as plt

# Function to estimate π using Monte Carlo simulation
def estimate_pi_with_simulation(num_samples):
    inside_circle = 0
    x_inside = []
    y_inside = []
    x_outside = []
    y_outside = []
    pi_estimates = []

    for i in range(num_samples):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        distance = x**2 + y**2

        if distance <= 1:
            inside_circle += 1
            x_inside.append(x)  # Store x coordinate of points inside the circle
            y_inside.append(y)  # Store y coordinate of points inside the circle
        else:
            x_outside.append(x)  # Store x coordinate of points outside the circle
            y_outside.append(y)  # Store y coordinate of points outside the circle

        if (i + 1) % 100 == 0:
            pi_estimate = (inside_circle / (i + 1)) * 4
            pi_estimates.append(pi_estimate)

    final_pi_estimate = (inside_circle / num_samples) * 4

    return final_pi_estimate, pi_estimates, x_inside, y_inside, x_outside, y_outside

num_samples = 10000
estimated_pi, pi_estimates, x_in, y_in, x_out, y_out = estimate_pi_with_simulation(num_samples)

# Create a figure with two subplots for visualization
plt.figure(figsize=(12, 6))

# Subplot 1: Scatter plot of points inside and outside the circle
plt.subplot(1, 2, 1)
plt.scatter(x_in, y_in, color='blue', s=1)
plt.scatter(x_out, y_out, color='red', s=1)
circle = plt.Circle((0, 0), 1, fill=False)
plt.gca().add_patch(circle)
plt.xlim(-1, 1)
plt.ylim(-1, 1)
plt.gca().set_aspect('equal', adjustable='box')
plt.title(f"Monte Carlo Simulation for π (Estimate: {estimated_pi})")

# Subplot 2: Line plot showing the change in π estimate
plt.subplot(1, 2, 2)
plt.plot(range(100, num_samples + 1, 100), pi_estimates)
plt.xlabel("Number of Samples")
plt.ylabel("π Estimate")
plt.title("Change in π Estimate")

# Adjust layout and display the figure
plt.tight_layout()
plt.show()
