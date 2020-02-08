#include <iostream>

//we declare our denominations as 1 , 5 , 10
int denom[] = {1,5,10};
//V is our iterating variable
int V = sizeof(denom)/sizeof(denom[0]);

int get_change(int m) {
  //write your code here
  int n = 0;
  //n is our coinCount
  for(int i = V-1; i>=0; i--){
    while(m >= denom[i]){
      m -= denom[i];
      n++;
    }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
