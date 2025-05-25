#include <iostream>
#include <cstdlib> // for rand() and RAND_MAX
#include <ctime> // for time

class BayesianCoinToss {
private:
    double probability_heads;

public:
    BayesianCoinToss(double initial_probability_heads) : probability_heads(initial_probability_heads) {}

    std::string biased_coin_toss() {
        // Generate a random number between 0 and 1
        double random_number = static_cast<double>(rand()) / RAND_MAX;

        // Determine the outcome based on the current probability for heads
        if (random_number < probability_heads) {
            return "Heads";
        } else {
            return "Tails";
        }
    }

    void update_probability(const std::string& outcome) {
        // Update the probability based on the observed outcome
        if (outcome == "Heads") {
            // Increase the probability of heads
            probability_heads += 0.1;
        } else {
            // Decrease the probability of heads
            probability_heads -= 0.1;
        }

        // Ensure the probability stays within [0, 1]
        probability_heads = std::max(0.0, std::min(1.0, probability_heads));
    }

    double get_probability_heads() const {
        return probability_heads;
    }
};

int main() {
    // Initial probability of getting heads
    double initial_probability_heads = 0.5;
    // Number of coin tosses
    int num_tosses = 10;
    // Create a BayesianCoinToss instance
    BayesianCoinToss coin_toss_model(initial_probability_heads);

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    // Perform the biased coin tosses and update the probability distribution
    for (int i = 0; i < num_tosses; ++i) {
        std::string result = coin_toss_model.biased_coin_toss();
        std::cout << "Biased coin toss result: " << result << std::endl;
        // Update the probability distribution based on the observed outcome
        coin_toss_model.update_probability(result);
        std::cout << "Updated probability of getting heads: " << coin_toss_model.get_probability_heads() << std::endl;
    }

    return 0;
}
