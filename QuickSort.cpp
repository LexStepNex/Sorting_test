#include <iostream>
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    std::cout << arr[i] << (i == (n - 1) ? " \n" : ", ");
}

void quickSort(int* arr, int left, int right) {
  if (left > right) return;
  int k = arr[(left + right) / 2];
  int l = left;
  int r = right;

  while (l <= r) {
    while (arr[l] > k) l++;
    while (arr[r] < k) r--;

    if (l <= r) {
      std::swap(arr[l], arr[r]);
      l++;
      r--;
    }
  }
  quickSort(arr, left, r);
  quickSort(arr, l, right);
}
int main() {
  // Быстрая сортировка по убыванию
  int arr[15] = {114, 111, 106, 107, 108, 105, 115, 110,
                 104, 109, 112, 113, 116, 117, 118};

  int n = std::size(arr);

  std::cout << "Ввод: \n";
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << (i == (n - 1) ? " \n" : ", ");
  }

  quickSort(arr, 0, n - 1);
  std::cout << "Вывод: \n";
  printArray(arr, n);
  
}