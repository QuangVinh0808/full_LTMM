#include <iostream>
#include "AES.h"

using namespace std;

int main() {
    unsigned char key[16] = {
        0x00, 0x01, 0x02, 0x03,
        0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b,
        0x0c, 0x0d, 0x0e, 0x0f
    };

    AES aes(key);

    unsigned char result[16];
    aes.getState(result);
    for (int i = 0; i < 16; i++) {
        if (result[i] != 0) {
            cout << "state tai byte " << i << " khong bang 0!" << endl;

            return 1;
        }
    }

    unsigned char input[16] = {
        0x00, 0x11, 0x22, 0x33,
        0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff
    };
    aes.setState(input);
    aes.getState(result);

    for(int i = 0; i < 16; i++) {
        if (result[i] != input[i]) {
            cout << "state tai byte " << i << " khong bang voi input!" << endl;

            return 1;
        }
    }
    unsigned char expected[16] = {
        0x00, 0x10, 0x20, 0x30,
        0x40, 0x50, 0x60, 0x70,
        0x80, 0x90, 0xa0, 0xb0,
        0xc0, 0xd0, 0xe0, 0xf0
    };

    aes.setState(input);
    aes.addRoundKey(0);
    aes.getState(result);

    for (int i = 0; i < 16; i++) {
        if (result[i] != expected[i]) {
            cout << "AddRoundKey sai tai byte " << i << endl;
            return 1;
        }
    }

    cout << "OK" << endl;

    unsigned char expectedSubBytes[16] = {
        0x63, 0xca, 0xb7, 0x04,
        0x09, 0x53, 0xd0, 0x51,
        0xcd, 0x60, 0xe0, 0xe7,
        0xba, 0x70, 0xe1, 0x8c
    };
    aes.setState(input); // bdau lại
    aes.addRoundKey(0);
    aes.subBytes();
    aes.getState(result);

    for (int i = 0; i < 16; i++) {
        if (result[i] != expectedSubBytes[i]) {
            cout << "SubBytes sai tai byte " << i << endl;
            return 1;
        }
    }

    cout << "PASS: SubBytes." << endl;

    return 0;
}