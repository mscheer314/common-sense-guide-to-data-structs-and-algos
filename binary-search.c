#include <stdio.h>

int main() {
  int value = 1;
  int size = 1200;
  int stuff[size];

  // populating the array
  for (int i = 0; i < 1200; i++) {
    stuff[i] = value;

    value++;
  }

  int lowIndex = 0;
  int highIndex = size - 1;

  int userValue;
  scanf("%d", &userValue);

  while (lowIndex <= highIndex) {
    int midPoint = lowIndex + (highIndex - lowIndex) / 2;

    if (userValue == stuff[midPoint]) {
      return 0;
    }

    if (userValue > stuff[midPoint]) {
      lowIndex = midPoint + 1;
    }

    else {
      highIndex = midPoint - 1;
    }
  }

  printf("Value not found");
  return 0;
}
