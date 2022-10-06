#include <iostream>

int main() {
  //      Task_1
  std::cout << "\t\tTask_1" << std::endl;
  int x, y, z;
  std::cout << "Enter x:";
  std::cin >> x;
  std::cout << "Enter y:";
  std::cin >> y;
  std::cout << "Enter z:";
  std::cin >> z;

  // part_1
  std::cout << std::endl << "\tPart_1" << std::endl;
  if (x % 2 == 1 && y % 2 == 1) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  // part_2
  std::cout << std::endl << "\tPart_2" << std::endl;
  if ((x < 20 && y > 20) || (x > 20 && y < 20)) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  // part_3
  std::cout << std::endl << "\tPart_3" << std::endl;
  if (x == 0 || y == 0) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  // part_4
  std::cout << std::endl << "\tPart_4" << std::endl;
  if (x < 0 && y < 0 && z < 0) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  // part_5
  std::cout << std::endl << "\tPart_5" << std::endl;
  if ((x % 5 == 0 && y % 5 != 0 && z % 5 != 0) ||
      (x % 5 != 0 && y % 5 == 0 && z % 5 != 0) ||
      (x % 5 != 0 && y % 5 != 0 && z % 5 == 0)) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  // part_6
  std::cout << std::endl << "\tPart_6" << std::endl;
  if (x > 100 || y > 100 || z > 100) {
    std::cout << "condition is true";
  } else
    std::cout << "condition is false";

  //      Task_2
  std::cout << std::endl
            << "\t\tTask_2" << std::endl
            << "Enter positionA (vertical and horizontal): " << std::endl;
  std::pair<short, short> positionA;
  std::cin >> positionA.first >> positionA.second;
  if ((positionA.first < 1) || (positionA.first > 8) ||
      (positionA.second > 8) || (positionA.second < 1)) {
    std::cout << "You entered the position of the figure incorrectly! ";
    return 0;
  }

  std::cout << "Enter positionB (vertical and horizontal): " << std::endl;
  std::pair<short, short> positionB;
  std::cin >> positionB.first >> positionB.second;
  if ((positionB.first < 1) || (positionB.first > 8) ||
      (positionB.second > 8) || (positionB.second < 1)) {
    std::cout << "You entered the position of the figure incorrectly! ";
    return 0;
  }
  if ((positionA.first != positionB.first) &&
      (positionA.second != positionB.second)) {
    // for rook
    int rook = 0;
    if ((positionA.first == positionB.first) ||
        (positionA.second == positionB.second)) {
      std::cout << "A rook on field A \"THREATENS\" field B." << std::endl;
      rook = 1;
    } else
      std::cout << "A rook on field A \"NO_THREATENS\" field B." << std::endl;

    // for bishop
    int i = -7, bishop = 0;
    for (; i < 8; i++) {
      if (((positionA.first + i <= 8) || (positionA.first - i >= 1)) &&
          ((positionA.second + i <= 8) || (positionA.second - i >= 1))) {
        if (((positionA.first + i == positionB.first) &&
             (positionA.second + i == positionB.second)) ||
            ((positionA.first + i == positionB.first) &&
             (positionA.second - i == positionB.second))) {
          std::cout << "A bishop on field A \"THREATENS\" field B."
                    << std::endl;
          bishop = 1;
        }
      }
    }
    if (bishop == 0)
      std::cout << "A bishop on field A \"NO_THREATENS\" field B." << std::endl;

    // for king
    int k = 0;
    for (i = -1; i < 2; i++) {
      for (int j = -1; j < 2; j++) {
        if (((positionA.first + i <= 8) || (positionA.first + j >= 1)) &&
            ((positionA.second + i <= 8) || (positionA.second + j >= 1))) {
          if ((positionA.first + i == positionB.first) &&
              (positionA.second + j == positionB.second)) {
            std::cout << "The king in field A will \"COME\" to field B by "
                         "going horizontally by "
                      << i << " and vertically by " << j << "!" << std::endl;
            k = 1;
          }
        }
      }
    }
    if (k == 0)
      std::cout << "The king in field A will \"NOT_COME\" to field B"
                << std::endl;

    // for queen
    if (bishop || rook) {
      std::cout << "A queen on field A \"THREATENS\" field B." << std::endl;
    } else
      std::cout << "A queen on field A \"NO_THREATENS\" field B." << std::endl;

    // for pawn
    if ((positionA.first + 1 == positionB.first) &&
        ((positionA.second + 1 == positionB.second) ||
         (positionA.second - 1 == positionB.second))) {
      std::cout << "A pawn \"BEATS\" a piece on the field B." << std::endl;
    } else if ((positionA.first + 1 == positionB.first) &&
               (positionA.second == positionB.second)) {
      std::cout << "The pawn \"MOVED\" forward by 1 on the field B."
                << std::endl;
    } else if ((positionA.first == 2) &&
               (positionA.second == positionB.second)) {
      std::cout << "The pawn \"MOVED\" forward by 2 on the field B."
                << std::endl;
    } else
      std::cout << "The pawn will \"NOT_MOVE\" to field B." << std::endl;

  } else
    std::cout << "Two pieces cannot stand in the same square." << std::endl;

  //      Task_3
  std::cout << "\t\tTask_3" << std::endl
            << "Multiplication table by 7." << std::endl;
  for (int first_mnog = 1; first_mnog < 10; first_mnog++) {
    std::cout << first_mnog << " x 7 = " << first_mnog * 7 << std::endl;
  }
  std::cout << "Enter second multiplier" << std::endl;
  int N;
  std::cin >> N;
  std::cout << "Multiplication table by " << N << std::endl;
  for (int first_mnog = 1; first_mnog < 10; first_mnog++) {
    std::cout << first_mnog << " x " << N << " = " << first_mnog * N
              << std::endl;
  }

  //      Task_4
  std::cout << "\t\tTask_3" << std::endl;
  std::cout << "Multiplication from 8 to 15  is equal to "
            << 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15 << std::endl;
  std::cout << "Enter a and b for Multiplication: " << std::endl;
  short a, b, c, d, e;
  long long basket_a = 1, basket_b = 1, basket_c = 1;
  std::cin >> a >> b;
  e = c = a;
  d = b;
  if ((a > 1) && (a < 20)) {
    for (; a < 20; basket_a *= a, a++)
      ;
    std::cout << "The product of the numbers from " << c
              << " to 19 is equal to " << basket_a << std::endl;

  } else
    std::cout << "The numbers are entered incorrectly" << std::endl;

  if ((b > 1) && (b < 20)) {
    for (; b < 20; basket_b *= b, b++)
      ;
    std::cout << "The product of the numbers from " << d
              << " to 19 is equal to " << basket_b << std::endl;
  } else
    std::cout << "The numbers are entered incorrectly" << std::endl;

  if ((d > 1) && (d < 20) && (d >= c) && (c > 1) && (c < 20)) {
    if (c == d)
      std::cout << 0 << std::endl;
    else {
      for (; c < d + 1; basket_c *= c, c++)
        ;
      std::cout << "The product of the numbers from " << e << " to " << d
                << " is equal to " << basket_c << std::endl;
    }
  } else
    std::cout << "The numbers are entered incorrectly" << std::endl;
  return 0;
}