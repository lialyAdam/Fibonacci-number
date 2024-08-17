
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;
using namespace chrono;
//calculates the nth Fibonacci number using an iterative 
int fibonacci(int n) {
    if (n <= 1) return n;
    int prev_1 = 0, prev_2 = 1, current;
    for (int i = 2; i <= n; ++i) { //find iterative calcilation
        current = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = current;
    }
    return current; //return the result of nth Fibonacci number
}
// find measure execution time

void measure_time(int n) {
    auto start = high_resolution_clock::now();
    int result = fibonacci(n);
    auto stop = high_resolution_clock::now();
    duration<double> duration = stop - start;
    cout << fixed << setprecision(9);
    cout << "fibonacci(" << n << ") = " << result
        << ", Time for input " << n << "\t : " << duration.count() << " seconds" << endl;
}

int main() {
    vector<int> input_values = { 20, 25, 30, 35, 45 };//give program different inputs
    for (int n : input_values) {
        measure_time(n);  //ouput
    }
    return 0;
}