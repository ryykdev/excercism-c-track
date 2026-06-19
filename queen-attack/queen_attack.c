#include "queen_attack.h"
#include <stdint.h>

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
  // queens can not be on same poistion
  if (queen_1.row == queen_2.row && queen_1.column == queen_2.column)
    return INVALID_POSITION;
  // restricted to board size
  if (queen_1.row < 0 || queen_1.row > 7 || queen_1.column < 0 ||
      queen_1.column > 7 || queen_2.row < 0 || queen_2.row > 7 ||
      queen_2.column < 0 || queen_2.column > 7)
    return INVALID_POSITION;

  // queens can attack lines
  // on same row or on same column
  if (queen_1.row == queen_2.row || queen_1.column == queen_2.column)
    return CAN_ATTACK;

  // at this point queens have valid positions
  // its enough to check if their diagonals meet
  // (4,2) x (6,6)
  for (uint8_t i = 1; i < 7; i++) {
    // Q I
    // check that no overflow happens
    // (2,2) x (1,3)
    // (2, 2) x (0,4)
    if (queen_1.column >= i && queen_1.row >= i) {
      if (queen_1.column - i == queen_2.column &&
          queen_1.row - i == queen_2.row)
        return CAN_ATTACK;
      // Q II
      // requires no check as uint8_t max is 255 and not reached
      else if (queen_1.column + i == queen_2.column &&
               queen_1.row + i == queen_2.row)
        return CAN_ATTACK;
      // Q III
      // requires single check
      if (queen_1.column + i == queen_2.column &&
          queen_1.row - i == queen_2.row)
        return CAN_ATTACK;
      // Q IV
      // single check
      if (queen_1.column - i == queen_2.column &&
          queen_1.row + i == queen_2.row)
        return CAN_ATTACK;
    }
  }
  return CAN_NOT_ATTACK;
}
