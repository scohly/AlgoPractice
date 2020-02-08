#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long long a, long long b){
// int gcd_fast( int  a, int b){
  while(b != 0){
    // create the reaminder var as type Long
    int remainder = a % b; 
    // we take a mod b store in remainder, we keep doing this while b is not

    //swap a with b value
    a = b;

    //set b = to remainder
    b = remainder;
  }
  return a;
}

long long lcm_fast(long long a, long long b){
  long lcm; 

  lcm = (a*b)/(gcd_fast(a,b));

  return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
 
  std::cout<<lcm_fast(a,b)<<std::endl;
  return 0;
}
