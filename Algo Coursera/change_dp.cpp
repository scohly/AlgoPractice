#include <iostream>

int get_change(int money) {
  //write your code here
  
  //as per question prompt our denominations are {1,3,4}
  int coins[] = {1,3,4};

  int resultTable[money +1];

  int coinArrSize = sizeof(coins)/sizeof(coins[0]);

  //base case
  resultTable[0] = 0;
  
  //Initialize results to invalid
  //removed INT_MAX and replaced with money+1 which is our invalid case
  for(int i=1; i <= money; i++){
    resultTable[i] = money+1;
  }

//this for loops will calculate min coins needed to make exact change
  for(int i = 1; i <= money ; i++){
    //second loop iterates through coin array
    for(int j = 0; j < coinArrSize; j++){

      if(coins[j] <= i){

        int subRes = resultTable[i - coins[j] ];

        //removed INT_MAX and replaced with money+1 which is our invalid case
        if((subRes != money+1) && (subRes+1 < resultTable[i]) ){
          resultTable[i] = subRes +1;
        }
      }
    }
  }
  return resultTable[money];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
