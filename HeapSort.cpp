#include <iostream>

int main() {
  int arr[15] = {114, 111, 106, 107, 108, 105, 115, 104, 110, 109, 112, 113, 116, 117, 118};

  int n = 15;
  int count = 0;
  while (n > 0) {
    for (int i = n - 1; i >= 0; i--) {  // вывод максимального в индекс 0 (heapify)
      int min = i;  // родитель, корень
      int l = 2 * i + 1;
      int r = 2 * i + 2;  // **левая и правая ветвь корня** //

      if (l < n && arr[l] < arr[min]) {
        min = l;
      }
      if (r < n && arr[r] < arr[min]) {
        min = r;
      }

      if (min != i) {
        std::swap(arr[i], arr[min]);
      }
      count++;
    }
    std::swap(arr[0], arr[n - 1]);
    n--;
  }

  std::cout
      << "Ввод: 114, 111, 106, 107, 108, 105, 115, 104, 110, 109, 112, 113, 116, 117, 118\n";
  std::cout << "Итог: ";
  for (int i = 0; i < 15; i++) {
    std::cout << arr[i] << (i == 14 ? " \n" : ", ");
  }
  std::cout << "count: " << count;
}