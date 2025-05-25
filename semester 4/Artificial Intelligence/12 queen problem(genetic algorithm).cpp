#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <cassert>

// NOTE :- 
// REMEMBER ANSWER WON'T COME IN THIS

using namespace std;

int nq; // Number of Queens
int maxFitness; // Maximum Fitness

vector<int> random_chromosome() {
    vector<int> chromosome;
    for (int i = 0; i < nq; ++i) {
        chromosome.push_back(rand() % nq + 1);
    }
    return chromosome;
}

int fitness(const vector<int>& chromosome) {
    int horizontal_collisions = 0;
    int diagonal_collisions = 0;

    int n = chromosome.size();
    vector<int> left_diagonal(2 * n, 0);
    vector<int> right_diagonal(2 * n, 0);

    for (int i = 0; i < n; ++i) {
        left_diagonal[i + chromosome[i] - 1]++;
        right_diagonal[n - i + chromosome[i] - 2]++;
    }

    for (int i = 0; i < 2 * n - 1; ++i) {
        int counter = 0;
        if (left_diagonal[i] > 1) {
            counter += left_diagonal[i] - 1;
        }
        if (right_diagonal[i] > 1) {
            counter += right_diagonal[i] - 1;
        }
        diagonal_collisions += counter / (n - abs(i - n + 1));
    }

    horizontal_collisions = accumulate(chromosome.begin(), chromosome.end(), 0,
        [&chromosome](int sum, int queen) { return sum + count(chromosome.begin(), chromosome.end(), queen) - 1; }) / 2;

    return maxFitness - (horizontal_collisions + diagonal_collisions);
}

double probability(const vector<int>& chromosome) {
    return static_cast<double>(fitness(chromosome)) / maxFitness;
}

vector<int> random_pick(const vector<vector<int>>& population, const vector<double>& probabilities) {
    double total = accumulate(probabilities.begin(), probabilities.end(), 0.0);
    double r = (rand() / (RAND_MAX + 1.0)) * total;

    double upto = 0;
    for (size_t i = 0; i < population.size(); ++i) {
        if (upto + probabilities[i] >= r) {
            return population[i];
        }
        upto += probabilities[i];
    }

    assert(false && "Shouldn't get here");
    return {};
}

vector<int> reproduce(const vector<int>& x, const vector<int>& y) {
    int n = x.size();
    int c = rand() % n;
    vector<int> child(x.begin(), x.begin() + c);
    child.insert(child.end(), y.begin() + c, y.end());
    return child;
}

vector<int> mutate(vector<int> x) {
    int n = x.size();
    int c = rand() % n;
    int m = rand() % n + 1;
    x[c] = m;
    return x;
}

void print_chromosome(const vector<int>& chrom) {
    cout << "Chromosome = { ";
    for (int i : chrom) {
        cout << i << " ";
    }
    cout << "}, Fitness = " << fitness(chrom) << endl;
}

vector<vector<int>> genetic_queen(const vector<vector<int>>& population) {
    double mutation_probability = 0.03;
    vector<vector<int>> new_population;
    vector<double> probabilities;

    transform(population.begin(), population.end(), back_inserter(probabilities), probability);

    for (size_t i = 0; i < population.size(); ++i) {
        vector<int> x = random_pick(population, probabilities);
        vector<int> y = random_pick(population, probabilities);
        vector<int> child = reproduce(x, y);

        if ((rand() / (RAND_MAX + 1.0)) < mutation_probability) {
            child = mutate(child);
        }

        print_chromosome(child);
        new_population.push_back(child);

        if (fitness(child) == maxFitness) {
            break;
        }
    }

    return new_population;
}

int main() {
    cout << "Enter Number of Queens: ";
    cin >> nq;

    maxFitness = (nq * (nq - 1)) / 2;
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<vector<int>> population;
    for (int i = 0; i < 100; ++i) {
        population.push_back(random_chromosome());
    }

    int generation = 1;
    while (find_if(population.begin(), population.end(), [](const vector<int>& chrom) { return fitness(chrom) == maxFitness; }) == population.end()) {
        cout << "=== Generation " << generation << " ===" << endl;
        population = genetic_queen(population);
        cout << endl;
        cout << "Maximum Fitness = " << max_element(population.begin(), population.end(), [](const vector<int>& a, const vector<int>& b) { return fitness(a) < fitness(b); })->size() << endl;
        ++generation;
    }

    vector<int> chrom_out;
    cout << "Solved in Generation " << generation - 1 << "!" << endl;
    for (const auto& chrom : population) {
        if (fitness(chrom) == maxFitness) {
            cout << endl;
            cout << "One of the solutions: " << endl;
            chrom_out = chrom;
            print_chromosome(chrom);
        }
    }

    vector<vector<char>> board(nq, vector<char>(nq, 'x'));
    for (int i = 0; i < nq; ++i) {
        board[nq - chrom_out[i]][i] = 'Q';
    }

    cout << endl;
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
