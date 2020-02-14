#include <iostream>
#include <cmath>

using namespace std;

void analyzeDivisors(int number, int& outputDivisorCount, int& outputDivisorSum);
/*
 * this function we will design and imiplment will take a number, an output of the count of divisors (pass by reference), a
 * output of the divisor sum (pass by refernce) and will update both numbers (hence pass by reference)
 *
 * return is void
 *
 * side note: why iterate up to sqrt(num?) because of this:
 * This problem has very simple solution, we all know that for any number ‘num’ all its divisors are always less than
 * and equal to ‘num/2’ and all prime factors are always less than and equal to sqrt(num).
 */

void findAmicablePairs(int targetNum);



bool isPerfectNumber(int targetNum);
/*
 * this function returns either true/false, it reads in the target Number, determines if it is a perfect number, does
 * so by calling the analyzeDivisor function and checks if outputDivisorSum == num
 */

int main() {
    int targetNum;

    std::cout << "Please enter a number!" << std::endl;

    cin>>targetNum;
    cout<<endl;

    cout<<"Listed below are the perfect numbers between 2 and "<<targetNum<<endl;

    for(int i = 2; i<= targetNum; i++){
        if(isPerfectNumber(i) == 1)
            cout<<i<<" "<<endl;
    }

    cout<<"now lets find amicable pairs! Enter a new number or the same";

    int newTarget;
    cin>>newTarget;

    findAmicablePairs(newTarget);

    return 0;
}


void analyzeDivisors(int targetNum, int& outputDivisorCount, int& outputDivisorSum){

    for(int i=1; i<sqrt(targetNum); i++){
        if(targetNum % i == 0){
            outputDivisorSum += i;
            outputDivisorCount++;
        }
    }

    for(int i = sqrt(targetNum); i >= 1; i-- ){
        if((targetNum % i == 0 )&& ( targetNum/i != targetNum)){
            outputDivisorSum += targetNum/i;
            outputDivisorCount++;
        }
    }

}

bool isPerfectNumber(int targetNum){
    int outputDivisorCount = 0;
    int outputDivisorSum = 0;

    analyzeDivisors(targetNum,outputDivisorCount, outputDivisorSum);

    if(outputDivisorSum == targetNum)
        return true;
    else
        return false;

}

void findAmicablePairs(int targetNum){
    int outputDivisorCount = 0;
    int outputDivisorSum = 0;

    cout<<endl;
    cout<< "Listed below are the Amicable Pairs beteween 2 and "<<targetNum<<endl;

    for(int num1 = 2; num1<= targetNum; num1++){
        analyzeDivisors(num1, outputDivisorCount, outputDivisorSum);

        int num2 = outputDivisorSum;

        outputDivisorCount = 0;
        outputDivisorSum = 0;

        analyzeDivisors(num2, outputDivisorCount, outputDivisorSum);

        int newNum1 = outputDivisorSum;

        if((num2> num1) && (num1 == newNum1) && (num2<targetNum))
            cout<<"The amicable pair is: ( "<<num1<<", "<<num2<<")"<<endl;

        outputDivisorCount = 0;
        outputDivisorSum = 0;

        //after each pair printed, reset the count and sum
    }


}
