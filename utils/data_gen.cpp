#include <bits/stdc++.h>

int main() {
  std::srand(std::time(0));
  for (int i = 0; i < 8; i++) {
    for (int i = 0; i < 5; i++)
      // if (i != 2)
      std::cout << std::fixed << std::setprecision(2)
                << ((double)std::rand()) / RAND_MAX << " ";
    // else
    //   std::cout << std::fixed << std::setprecision(2)
    //             << ((double)std::rand() - RAND_MAX / 2) / RAND_MAX * 2 << "
    //             ";
    std::cout << std::endl;
  }
  return 0;
}