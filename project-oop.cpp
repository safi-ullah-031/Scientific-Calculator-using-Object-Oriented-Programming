#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Base class
class ScientificCalculator {
public:
    virtual void performCalculation() = 0;
    void getValues(vector<double> &values, int &numValues) {
        cout << "Enter the number of values: ";
        cin >> numValues;
        values.resize(numValues);
        for (int i = 0; i < numValues; i++) {
            cout << "Enter value " << i + 1 << ": ";
            cin >> values[i];
        }
    }
};

// Child class 1: Simple Functions
class SimpleFunctions : public ScientificCalculator {
public:
    void performCalculation() override {
        vector<double> values;
        int numValues, choice;
        double result = 0;

        cout << "\n--- Simple Functions ---\n";
        getValues(values, numValues);

        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Percentage\n0. Back\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: result = accumulate(values.begin(), values.end(), 0.0); break;
            case 2: result = values[0]; for (int i = 1; i < numValues; i++) result -= values[i]; break;
            case 3: result = 1; for (double val : values) result *= val; break;
            case 4:
                result = values[0];
                for (int i = 1; i < numValues; i++) {
                    if (values[i] == 0) { cout << "Error: Division by zero!\n"; return; }
                    result /= values[i];
                }
                break;
            case 5: result = pow(values[0], values[1]); break;
            case 6: result = (values[0] / 100) * values[1]; break;
            case 0: return;
            default: cout << "Invalid choice!\n"; return;
        }
        cout << "Result: " << result << "\n";
    }
};

// Child class 2: Squares and Roots
class SquaresAndRoots : public ScientificCalculator {
public:
    void performCalculation() override {
        vector<double> values;
        int numValues, choice;
        cout << "\n--- Squares and Roots ---\n";
        getValues(values, numValues);

        cout << "1. Square\n2. Cube\n3. Square Root\n4. Cube Root\n0. Back\nEnter choice: ";
        cin >> choice;

        for (double val : values) {
            double result = (choice == 1) ? pow(val, 2) : (choice == 2) ? pow(val, 3) : (choice == 3 && val >= 0) ? sqrt(val) : cbrt(val);
            cout << "Result for " << val << ": " << result << "\n";
        }
    }
};

// Child class 3: Trigonometric Functions
class TrigonometricFunctions : public ScientificCalculator {
public:
    void performCalculation() override {
        vector<double> values;
        int numValues, choice;
        cout << "\n--- Trigonometric Functions ---\n";
        getValues(values, numValues);

        cout << "1. Sine\n2. Cosine\n3. Tangent\n4. Cotangent\n5. Secant\n6. Cosecant\n0. Back\nEnter choice: ";
        cin >> choice;

        for (double val : values) {
            double rad = val * M_PI / 180;
            double result = (choice == 1) ? sin(rad) : (choice == 2) ? cos(rad) : (choice == 3) ? tan(rad) : (choice == 4) ? 1 / tan(rad) : (choice == 5) ? 1 / cos(rad) : 1 / sin(rad);
            cout << "Result for " << val << ": " << result << "\n";
        }
    }
};

// Child class 4: Logarithmic Functions
class LogarithmicFunctions : public ScientificCalculator {
public:
    void performCalculation() override {
        vector<double> values;
        int numValues, choice;
        cout << "\n--- Logarithmic Functions ---\n";
        getValues(values, numValues);

        cout << "1. Natural Log (ln)\n2. Common Log (log10)\n0. Back\nEnter choice: ";
        cin >> choice;

        for (double val : values) {
            if (val <= 0) { cout << "Error: Log of non-positive number!\n"; return; }
            double result = (choice == 1) ? log(val) : log10(val);
            cout << "Result for " << val << ": " << result << "\n";
        }
    }
};

// Main function
int main() {
    while (true) {
        int choice;
        cout << "\n--- Scientific Calculator ---\n";
        cout << "1. Simple Functions\n2. Squares and Roots\n3. Trigonometric Functions\n4. Logarithmic Functions\n0. Exit\nEnter choice: ";
        cin >> choice;

        ScientificCalculator* calculator = nullptr;
        switch (choice) {
            case 1: calculator = new SimpleFunctions(); break;
            case 2: calculator = new SquaresAndRoots(); break;
            case 3: calculator = new TrigonometricFunctions(); break;
            case 4: calculator = new LogarithmicFunctions(); break;
            case 0: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n"; continue;
        }
        calculator->performCalculation();
        delete calculator;
    }
}


//adding one more comment
//end of code
