#include "char-sorter.h"
#include <string.h>

#define CHAR_RANGE 256

/*
 * Sorts a character array (C-style string) in place using Counting Sort.
 * This is significantly faster than a comparison-based sort like qsort
 * for this problem, as the range of character values is small and fixed.
 * The complexity is O(n + k) where n is the string length and k is CHAR_RANGE.
 */
void
sort_chars(char *str)
{
  if (!str) {
    return;
  }

  size_t len = strlen(str);
  if (len <= 1) {
    return;
  }

  // 1. Create a count array to store count of individual characters
  unsigned int count[CHAR_RANGE] = {0};

  // 2. Store count of each character
  for (size_t i = 0; i < len; ++i) {
    count[(unsigned char)str[i]]++;
  }

  // 3. Rebuild the string from the count array
  char *p = str;
  for (int i = 0; i < CHAR_RANGE; ++i) {
    for (unsigned int j = 0; j < count[i]; ++j) {
      *p++ = (char)i;
    }
  }
}
