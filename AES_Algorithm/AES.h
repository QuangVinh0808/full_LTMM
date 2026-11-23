#include <array>
#include <cstdint>
#include <cstddef>


class AES {
private:
    unsigned char roundKey[16];
    unsigned char state[4][4];
    unsigned char invSbox[256];

    void invSubBytes();
    void invShiftRows();
    void invMixColumns();

    
public:
    AES(unsigned char key[16]);

    void getState(unsigned char output[16]);
    void setState(unsigned char input[16]);
    void addRoundKey(int round);
    void subBytes();
    void shiftRows();
    unsigned char multiply(unsigned char a, unsigned char b);
    void mixColumns();
};