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

// Compare 2 BigNums
int bignum_compare(const BigNum* a, const BigNum* b){
  if(a->size != b->size){
    return a->size > b->size ? 1 : -1;
  }
  for(int i = a->size - 1; i>= 0; i--){
    return a->digits[i] > b->digits[i] ? 1 : -1;
  }

  return 0;
}

int main(){
  BigNum a, b;
  bignum_init(&a, "12345678901234567890");
  bignum_init(&b, "28289292982823101089");
  int cmp = bignum_compare(&a, &b);
  if(cmp > 0){
    printf("a is bigger than b\n");
  }
  else if(cmp < 0){
    printf("b is bigger than a\n");
  }
  else{
    printf("both are equal\n");
  }
  return 0;
}