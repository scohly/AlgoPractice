#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int getFibLastDigFast(int n){
    if(n<=1)
        return n;
    
    int previous = 0;
    int current = 1;

    int lastDig;

     for(int i =2; i<=n; i++){
        
         lastDig = (previous+current)%10;
         previous = current;
         current = lastDig;
         //easier to just calculate and store the modulus of the fib number... 
     }

     return lastDig;

}

int main() {
    int n,m;
    // std::cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';

    std::cin>>m;
    int d = getFibLastDigFast(m);
    
    std::cout<< d << '\n';

    return 0;

}
