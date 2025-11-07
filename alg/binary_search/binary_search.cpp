#include <iostream>

int
binary_search(const int* arr, int size, int target)
{
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int
main()
{
  const int sorted_array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  const int arr_size = sizeof(sorted_array) / sizeof(sorted_array[0]);
  int target_value;

  if (!(std::cin >> target_value)) {
    std::cerr << "Error: Invalid input. Please provide an integer." << std::endl;
    return 1;
  }

  int result_index = binary_search(sorted_array, arr_size, target_value);

  std::cout << result_index << std::endl;

  return 0;
}