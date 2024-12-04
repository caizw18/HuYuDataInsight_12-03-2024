#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class PiratesGold {
private:
    double initial_gold;    // Starting value of gold
    double risk_factor;     // Risk factor for treasure loss
    int rounds;             // Number of simulation rounds
    std::mt19937 rng;       // Random number generator
    std::uniform_real_distribution<> dist; // Uniform distribution for random events

public:
    PiratesGold(double initial, double risk, int rounds)
        : initial_gold(initial), risk_factor(risk), rounds(rounds),
        rng(std::random_device{}()), dist(0.0, 1.0) {
    }

    double simulateRound(double current_gold) {
        // Random event impact
        double random_event = dist(rng);

        // Treasure growth or loss
        if (random_event > risk_factor) {
            double growth_rate = 0.1 * random_event; // Treasure grows by a random percentage
            current_gold += current_gold * growth_rate;
        }
        else {
            double loss_rate = 0.2 * (1 - random_event); // Treasure lost by a random percentage
            current_gold -= current_gold * loss_rate;
        }
        return current_gold;
    }

    void runSimulation() {
        double gold = initial_gold;
        for (int i = 0; i < rounds; ++i) {
            gold = simulateRound(gold);
            std::cout << "Round " << i + 1 << ": Gold = " << gold << "\n";
        }
    }
};

int main() {
    double initial_gold = 1000.0; // Initial gold value
    double risk_factor = 0.3;    // 30% risk threshold
    int rounds = 10;            // Simulate 10 rounds

    PiratesGold simulation(initial_gold, risk_factor, rounds);
    simulation.runSimulation();

    return 0;
}