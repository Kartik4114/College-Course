#include <iostream>

std::string fair_coin_toss(int toss_number) {
    // Toggle between "Heads" and "Tails" based on the toss number
    if (toss_number % 2 == 0) {
        return "Heads";
    } else {
        return "Tails";
    }
}

int main() {
    // Number of coin tosses
    int num_tosses = 10;

    // Perform the coin tosses
    for (int i = 0; i < num_tosses; ++i) {
        std::string result = fair_coin_toss(i);
        std::cout << "Coin toss result: " << result << std::endl;
    }

    return 0;
}
