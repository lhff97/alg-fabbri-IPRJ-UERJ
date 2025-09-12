#include "sort_char.h"
#include <string.h>

#define CHAR_RANGE 256

/*
 * Sorts a character array (C-style string) in place using Counting Sort.
 * This is significantly faster than a comparison-based sort like qsort
 * for this problem, as the range of character values is small and fixed.
 * The complexity is O(n + k) where n is the string length and k is CHAR_RANGE.
 * This version includes micro-optimizations to improve practical performance.
 */
void
sort_char(char *v)
{
  if (!v) {
    return;
  }

  unsigned int count[CHAR_RANGE] = {0};
  size_t len = 0;

  // Count characters and find length in a single pass
  for (char *p = v; *p; ++p, ++len) {
    count[(unsigned char)*p]++;
  }

  if (len <= 1) {
    return;
  }

  // Rebuild the string from the count array using memset for efficiency
  char *p = v;
  for (int i = 0; i < CHAR_RANGE; ++i) {
    if (count[i] > 0) {
      memset(p, i, count[i]);
      p += count[i];
    }
  }
}
