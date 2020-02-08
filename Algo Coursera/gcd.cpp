#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

int main() {
  // int a, b;
  // std::cin >> a >> b;
  // std::cout << gcd_naive(a, b) << std::endl;

  int m,n;
  std::cin>>m>>n;
  // std::cout<<"gcd of "<< m<< " and "<< n << " is: "<< gcd_fast(m,n)<< std::endl;
  std::cout<< gcd_fast(m,n)<< std::endl;
  return 0;
}
