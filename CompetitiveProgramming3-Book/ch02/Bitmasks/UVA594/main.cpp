#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int32_t reversed_bitset(int32_t num) {
  bitset<32> original(num);

  bitset<8> byte1, byte2, byte3, byte4;


  for(int i=0; i<8; i++) {
    byte1[7-i] = original[i];
    byte2[7-i] = original[i+8];
    byte3[7-i] = original[i+16];
    byte4[7-i] = original[i+24];
  }

  bitset<32> reversed;

  for(int i = 0; i < 8; i++) {
    reversed[i] = byte4[7-i];
    reversed[i+8] = byte3[7-i];
    reversed[i+16] = byte2[7-i];
    reversed[i+24] = byte1[7-i];
  }

  return static_cast<int32_t>(reversed.to_ulong());
}

int main() {
  int32_t input;
  while (std::cin >> input) {
      int32_t reversed = reversed_bitset(input);
      std::cout << input << " converts to " << reversed << std::endl;
  }
  return 0;
}
