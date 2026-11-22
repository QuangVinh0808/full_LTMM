#include "AES.h"
#include <iostream>
#include <iomanip>

using namespace std;

AES::AES(unsigned char key[16]) {
    for (int i = 0; i < 16; i++) {
        roundKey[i] = key[i];
    }
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            state[row][col] = 0;
        }
    }
}
void AES::getState(unsigned char output[16]) {
        std::cout << "Trang thai hien tai: \n";
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                output[row * 4 + col] = state[row][col];
                cout << hex << setw(2) << setfill('0') << (int)state[row][col] << " ";

            }
            std::cout << std::endl;
        }
        cout << dec << setfill(' ');
    }

void AES::setState(unsigned char input[16]) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            state[row][col] = input[row * 4 + col];
        }
    }
}