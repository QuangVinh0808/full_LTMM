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

    cout << "ok" << endl;

    return 0;
}