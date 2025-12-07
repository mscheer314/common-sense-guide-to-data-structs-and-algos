#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

  int array_size = argc -1;

  if (array_size == 0) {
    printf("Usage %s <num1> <num2> ... <numN>\n", argv[0]);
    printf("Please provide integers as command-line arguments.\n");
    return 1;
  }

  int *integer_array = (int *)malloc(array_size * sizeof(int));

  // check if the memory allocation failed
  if (integer_array == NULL) {
    perror("Failed to allocate memory");
    return 1;
  }

  // convert the strings from the command-line args into integers
  for (int i = 0; i < array_size; i++) {
    // strtol converts the chars to ints stops at the first char it cannot convert.
    // and returns a pointer to that char. assuming a valid conversion (ex. 12) 
    // the first char it cannot convert is the null terminator at the end of any C 
    // string. if the user entered a bad value (ex. 12a) then the pointer would point
    // to the 'a'
    char *endptr;
    // errno is a global error code and setting it to 0 here makes it clear that if
    // an error is generated and this value is set, that it was set in this process
    // and not by something earlier.
    errno = 0;

    // this returns that pointer to the first char it cannot convert to an int.
    // the 10 is telling the function to use base 10.
    long val = strtol(argv[i + 1], &endptr, 10);

    if (errno != 0 || *endptr != '\0') {
      fprintf(stderr, "Error: Argument '%s' is not a valid integer. \n", argv[i + 1]);
      free(integer_array);
      return 1;
    }

    integer_array[i] = (int)val;
  }


  free(integer_array);
  return 0;
}
