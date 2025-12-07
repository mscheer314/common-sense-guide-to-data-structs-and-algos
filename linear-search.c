#include <stdio.h>

int main() {
  int searchValue;
  printf("Enter an integer: ");
  scanf("%d", &searchValue);
  int stuff[10] = {1,2,3,4,5,6,7,8,9,10};
  bool valueFound = false;

  for (int i = 0; i < 10; i++) {
    if (searchValue == stuff[i]) {
      valueFound = true;
      printf("Found value at index %d", i);
    } 
  }

  if (valueFound == false) {
    printf("Value not found.");
  }

  return 0;
}
