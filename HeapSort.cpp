#include <iostream>

int main() {
  // Сортировка по убыванию
  // По возрастанию меняем мин на макс и меняем знаки
  int arr[] = {114, 111, 106, 107, 108, 105,  115, 108, 110, 109, 112,
               113, 116, 117, 118, 119, 2500, 333, 674, 23,  33};

  int n = std::size(arr);

  std::cout << "Ввод: ";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << (i == (n - 1) ? " \n" : ", ");
  }
  
  while (n > 0) {
    for (int i = n / 2 - 1; i >= 0; i--) {  // вывод минимального в индекс 0 (heapify)
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
    }
    std::swap(arr[0], arr[n - 1]);
    n--;
  }

  std::cout << "Итог: ";
  for (int i = 0; i < std::size(arr); i++) {
    std::cout << arr[i] << (i == (std::size(arr) - 1) ? " \n" : ", ");
  }
}