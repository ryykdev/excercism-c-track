#include "eliuds_eggs.h"
#include "stdio.h"

unsigned int egg_count(const unsigned int decimal) {
  //
  int mut_decimal = decimal;
  int mut_count = 0;

  // we only need to count the 1s in the binary
  // representation, so all complexity of building
  // it can be skipped
  while (mut_decimal > 0) {
    //
    if (mut_decimal % 2 == 1) {
      mut_count += 1;
      mut_decimal = mut_decimal / 2;
    } else {
      mut_decimal = mut_decimal / 2;
    }
  }

  return mut_count;
}
