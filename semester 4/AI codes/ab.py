import random

# Define constants
BOARD_SIZE = 8
POPULATION_SIZE = 20
MUTATION_RATE = 0.1

# Generate initial population
def generate_population(population_size):
    population = []
    for _ in range(population_size):
        state = [random.randint(0, BOARD_SIZE - 1) for _ in range(BOARD_SIZE)]
        population.append(state)
    return population

# Fitness function
def fitness(state):
    conflicts = 0
    for i in range(BOARD_SIZE):
        for j in range(i + 1, BOARD_SIZE):
            if state[i] == state[j] or abs(state[i] - state[j]) == j - i:
                conflicts += 1
    return 1 / (conflicts + 1)  # Higher fitness for fewer conflicts

# Selection
def select(population, fitnesses):
    total_fitness = sum(fitnesses)
    probabilities = [f / total_fitness for f in fitnesses]
    return random.choices(population, weights=probabilities)[0]

# Crossover
def crossover(parent1, parent2):
    crossover_point = random.randint(1, BOARD_SIZE - 2)
    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]
    return child1, child2

# Mutation
def mutate(state):
    if random.random() < MUTATION_RATE:
        index = random.randint(0, BOARD_SIZE - 1)
        state[index] = random.randint(0, BOARD_SIZE - 1)
    return state

# Main genetic algorithm function
def genetic_algorithm():
    population = generate_population(POPULATION_SIZE)
    for _ in range(1000):  # Number of generations
        fitnesses = [fitness(state) for state in population]

        new_population = []
        for _ in range(POPULATION_SIZE // 2):
            parent1 = select(population, fitnesses)
            parent2 = select(population, fitnesses)
            child1, child2 = crossover(parent1, parent2)
            child1 = mutate(child1)
            child2 = mutate(child2)
            new_population.extend([child1, child2])

        population = new_population

        # Check if we found a solution
        if any(fitness(state) == 1 for state in population):
            return [state for state in population if fitness(state) == 1]

    # If no solution found after 1000 generations, return the best state found
    return max(population, key=fitness)

# Running the genetic algorithm
solution = genetic_algorithm()
print("Solution:", solution)
