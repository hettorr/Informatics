#include <gmpxx.h>
#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Improper input. Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    long n = strtol(argv[1], nullptr, 10);
    if (n < 0) {
        cerr << "n must be non-negative.\n";
        return 1;
    }

    mpz_class a = 0, b = 1, c;

    auto start = high_resolution_clock::now();

    for (long i = 0; i < n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    auto end = high_resolution_clock::now();

    double elapsed = duration<double>(end - start).count();

    cout << "Fibonacci Number " << n << ": " << a << "\n";
    cout << "Calculation Time: " << elapsed << " seconds\n";

    return 0;
}
