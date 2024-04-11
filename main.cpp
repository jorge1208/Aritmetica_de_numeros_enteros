#include <iostream>
#include <bitset>

using namespace std;

bitset<8> boothMultiplication(bitset<8> multiplicand, bitset<8> multiplier) {
    bitset<8> A = multiplicand;
    bitset<8> Q = multiplier;
    bitset<8> M = multiplicand;
    bitset<8> result(0);

    for (int i = 0; i < 8; ++i) {
        // Check the two least significant bits of Q
        if ((Q & bitset<8>(0b11)) == bitset<8>(0b01)) {
            result = result + A;
        } else if ((Q & bitset<8>(0b11)) == bitset<8>(0b10)) {
            result = result - A;
        }

        // Right shift A and Q
        bool A0 = A[0];
        bool Q0 = Q[0];
        A >>= 1;
        Q >>= 1;
        A[7] = A0;
        Q[7] = Q0;
    }

    return result;
}

int main() {
    bitset<8> multiplicand;
    bitset<8> multiplier;

    cout << "Enter multiplicand (8 bits): ";
    cin >> multiplicand;
    cout << "Enter multiplier (8 bits): ";
    cin >> multiplier;

    bitset<8> result = boothMultiplication(multiplicand, multiplier);

    cout << "Result: " << result << endl;

    return 0;
}
