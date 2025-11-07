#include <iostream>
#include <string>
#include <vector>
#include <cstddef>

const std::string big_string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

int
main()
{
  size_t search_index;

  if (!(std::cin >> search_index)) {
    std::cerr << "Error: Invalid input. Please provide an integer index." << std::endl;
    return 1;
  }

  if (search_index < big_string.length()) {
    std::cout << big_string[search_index] << std::endl;
  } else {
    std::cerr << "Error: Index " << search_index << " is out of bounds. The string length is " << big_string.length() << "." << std::endl;
    return 1;
  }

  return 0;
}