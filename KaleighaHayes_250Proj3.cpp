//Kaleigha  Hayes
//1313037
//10/23/2023
//Project 3 CSDP 250
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

// Step 1: Split the decimal number into integer and decimal parts
void SplitDecimal(double decimalNumber, int& integerPart, double& decimalPart) {
    integerPart = static_cast<int>(decimalNumber);
    decimalPart = decimalNumber - integerPart;
}

// Step 2: Convert the integer part into binary using a stack
std::string IntegerToBinary(int integerPart) {
    if (integerPart == 0) {
        return "0";  // Handle the special case of 0
    }

    std::stack<int> binaryStack;
    while (integerPart > 0) {
        int remainder = integerPart % 2;
        binaryStack.push(remainder);
        integerPart /= 2;
    }

    std::string binaryRepresentation = "";
    while (!binaryStack.empty()) {
        binaryRepresentation += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryRepresentation;
}

// Step 3: Convert the decimal part into binary using a queue
std::string DecimalToBinary(double decimalPart, int precision) {
    std::queue<int> binaryQueue;
    for (int i = 0; i < precision; ++i) {
        decimalPart *= 2;
        int bit = static_cast<int>(decimalPart);
        binaryQueue.push(bit);
        decimalPart -= bit;
    }

    std::string binaryRepresentation = ".";
    while (!binaryQueue.empty()) {
        binaryRepresentation += std::to_string(binaryQueue.front());
        binaryQueue.pop();
    }

    return binaryRepresentation;
}

// Step 4: Output the result
void OutputResult(const std::string& binaryRepresentation) {
    std::cout << "Binary representation: " << binaryRepresentation << std::endl;
}

int main() {
    double decimalNumber;
    int integerPart;
    double decimalPart;
    int decimalPrecision;

    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    std::cout << "Enter the number of decimal places to convert: ";
    std::cin >> decimalPrecision;

    if (decimalNumber < 0) {
        std::cerr << "Please enter a non-negative decimal number." << std::endl;
        return 1;
    }

    // Step 1: Split the number into integer and decimal parts
    SplitDecimal(decimalNumber, integerPart, decimalPart);

    // Step 2: Convert the integer part to binary
    std::string integerBinary = IntegerToBinary(integerPart);

    // Step 3: Convert the decimal part to binary
    std::string decimalBinary = DecimalToBinary(decimalPart, decimalPrecision);

    // Step 4: Output the result
    OutputResult(integerBinary + decimalBinary);

    return 0;
}

