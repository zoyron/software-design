// following https://austinhenley.com/blog/bignum1.html for writing a mini bignum library

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this bignum strcut will represent out numbers by storing an array of digits
typedef struct{
  char *digits;
  int size;
} BigNum;

// Initialize the BigNum value
void bignum_init(BigNum* n, const char *str){
  // BigNum ke variable me kuch hai bhi abhi
  // n me size store karenge, aur digits wali array me sare digits jo paas honge
  n->size = strlen(str);
  
  // sare digits store karne ke liye pehle ek array banana padega utne size ka jitne size ka str hoga
  n->digits = malloc(n->size * sizeof(char));

  // let's fill the digits array of bignum struct
  for(int i = 0; i< n->size; i++){
    n->digits[i] = str[n->size - 1 - i] - '0';
  }
}

// Free the memory by using this function
void bignum_free(BigNum* n){
  free(n->digits);
  n->digits = NULL;
  n->size = 0;
}

int main(){
  BigNum a;
  bignum_init(&a, "12345678901234567890");
  return 0;
}