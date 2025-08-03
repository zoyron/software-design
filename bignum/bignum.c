// following https://austinhenley.com/blog/bignum1.html for writing a mini
// bignum library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this bignum strcut will represent out numbers by storing an array of digits
typedef struct {
  char *digits;
  int size;
} BigNum;

// Initialize the BigNum value
void bignum_init(BigNum *n, const char *str) {
  // BigNum ke variable me kuch hai bhi abhi
  // n me size store karenge, aur digits wali array me sare digits jo paas honge
  n->size = strlen(str);

  // sare digits store karne ke liye pehle ek array banana padega utne size ka
  // jitne size ka str hoga
  n->digits = malloc(n->size * sizeof(char));

  // let's fill the digits array of bignum struct
  for (int i = 0; i < n->size; i++) {
    n->digits[i] = str[n->size - 1 - i] - '0';
  }
}

// Free the memory by using this function
void bignum_free(BigNum *n) {
  free(n->digits);
  n->digits = NULL;
  n->size = 0;
}

// Compare 2 BigNums
int bignum_compare(const BigNum *a, const BigNum *b) {
  if (a->size != b->size) {
    return a->size > b->size ? 1 : -1;
  }
  for (int i = a->size - 1; i >= 0; i--) {
    return a->digits[i] > b->digits[i] ? 1 : -1;
  }

  return 0;
}

// Add 2 bignums
void bignum_add(BigNum *result, const BigNum *a, const BigNum *b) {
  int max_size = a->size > b->size ? a->size : b->size;
  result->digits = malloc((max_size + 1) * sizeof(char));
  int carry = 0, i;
  for (i = 0; i < max_size || carry; i++) {
    int sum = carry + (i < a->size ? a->digits[i] : 0) +
              (i < b->size ? b->digits[i] : 0);
    result->digits[i] = sum % 10;
    carry = sum / 10;
  }
  result->size = i;
}

// Multiply bignums
void bignum_multiply(BigNum *result, const BigNum *a, const BigNum *b) {
  result->digits = calloc(a->size + b->size, sizeof(char));
  result->size = a->size + b->size; // Max size we will need.

  for (int i = 0; i < a->size; i++) {
    for (int j = 0; j < b->size; j++) {
      int index = i + j;
      result->digits[index] += a->digits[i] * b->digits[j];
      result->digits[index + 1] += result->digits[index] / 10;
      result->digits[index] %= 10;
    }
  }

  // Trim any leading zeros
  while (result->size > 1 && result->digits[result->size - 1] == 0) {
    result->size--;
  }
}

// Print the bignum
void bignum_print(BigNum *n) {
  for (int i = n->size - 1; i >= 0; i--) {
    printf("%d", n->digits[i]);
  }
  printf("\n");
}

int main() {
  BigNum a, b, sum, prod;
  bignum_init(&a, "12345678901234567890");
  bignum_init(&b, "28289292982823101089");
  int cmp = bignum_compare(&a, &b);
  if (cmp > 0) {
    printf("a is bigger than b\n");
  } else if (cmp < 0) {
    printf("b is bigger than a\n");
  } else {
    printf("both are equal\n");
  }

  bignum_add(&sum, &a, &b);
  printf("Sum of 2 bignums: ");
  bignum_print(&sum);
  printf("\nProduct of 2 bignums: ");
  bignum_multiply(&prod, &a, &b);
  bignum_print(&prod);
  bignum_free(&a);
  bignum_free(&b);
  bignum_free(&sum);
  return 0;
}
