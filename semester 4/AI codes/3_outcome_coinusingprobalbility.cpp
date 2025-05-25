#include <iostream>
#include <cstdlib> // for rand() and RAND_MAX
#include <ctime>   // for time()

std::string biased_coin_toss(double probability_heads) {
    // Generate a random number between 0 and 1
    double random_number = static_cast<double>(rand()) / RAND_MAX;

    // Determine the outcome based on the specified probability for heads
    if (random_number < probability_heads) {
        return "Heads";
    } else {
        return "Tails";
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    // Probability of getting heads (you can adjust this value)
    double probability_heads = 0.7;
    
    // Number of coin tosses
    int num_tosses = 10;

    // Perform the biased coin tosses
    for (int i = 0; i < num_tosses; ++i) {
        std::string result = biased_coin_toss(probability_heads);
        std::cout << "Biased coin toss result: " << result << std::endl;
    }

    return 0;
}
