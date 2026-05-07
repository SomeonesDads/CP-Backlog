#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding

int main() {
    std::ofstream fout("matrix1000x1000_safe.txt");
    if (!fout) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    int rows = 1000;
    int cols = 1000;

    // Seed random
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Generate random number between -1 and 1
            double value = ((rand() % 2000) / 1000.0) - 1.0;

            // Optional: add a small identity component to improve conditioning
            if (i == j) value += 10.0;

            fout << std::fixed << std::setprecision(6) << value;
            if (j < cols - 1) fout << "\t";
        }
        fout << "\n";
    }

    fout.close();
    std::cout << "matrix1000x1000_safe.txt generated!\n";
    return 0;
}
