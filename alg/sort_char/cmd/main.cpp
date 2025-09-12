#include "sort_char.h"
#include <stdio.h>

int
main(void)
{
  char my_string[] = "asfdlafjosamigerhmihefopjfpiatjhmopiapoklogrjkoihgapollktaoeirthfjirtpiocfkrvtreotuapotukvrvcokapkcoirkutvriapkovpkavvrtpvkcvekwpae";

  printf("Original string: %s\n", my_string);

  sort_char(my_string);

  printf("Sorted string:   %s\n", my_string);

  return 0;
}
