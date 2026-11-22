#include <array>
#include <cstdint>
#include <cstddef>


class AES {
private:
    unsigned char roundKey[16];
    unsigned char state[4][4];
    unsigned char invSbox[256];

    void subBytes();
    void shiftRows();
    void mixColumns();
    void addRoundKey(int round);

    void invSubBytes();
    void invShiftRows();
    void invMixColumns();

    unsigned char multiply(unsigned char a, unsigned char b);
public:
    AES(unsigned char key[16]);

    void getState(unsigned char output[16]);
};