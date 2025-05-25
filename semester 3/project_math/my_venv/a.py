import random
import matplotlib.pyplot as plt

def estimate_pi_with_simulation(num_samples):
    inside_circle = 0
    x_inside = []
    y_inside = []
    x_outside = []
    y_outside = []

    for _ in range(num_samples):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        distance = x**2 + y**2

        if distance <= 1:
            inside_circle += 1
            x_inside.append(x)
            y_inside.append(y)
        else:
            x_outside.append(x)
            y_outside.append(y)

    pi_estimate = (inside_circle / num_samples) * 4

    return pi_estimate, x_inside, y_inside, x_outside, y_outside

num_samples = 10000  # You can adjust the number of samples for better accuracy
estimated_pi, x_in, y_in, x_out, y_out = estimate_pi_with_simulation(num_samples)

# Plot the points inside and outside the circle
plt.figure(figsize=(6, 6))
plt.scatter(x_in, y_in, color='blue', s=1)
plt.scatter(x_out, y_out, color='red', s=1)

# Draw the unit circle
circle = plt.Circle((0, 0), fill=False)
plt.gca().add_patch(circle)

plt.xlim(-1, 1)
plt.ylim(-1, 1)
plt.gca().set_aspect('equal', adjustable='box')
plt.legend()
plt.title(f"Monte Carlo Simulation for π (Estimate: {estimated_pi})")
plt.show()
