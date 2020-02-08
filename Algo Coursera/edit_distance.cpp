#include <iostream>
#include <string>
#include <algorithm>
#include  <cmath>

using std::string;

int min(int x, int y, int z){
  return std::min(std::min(x,y),z);
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here

  int row = str1.length();
  int col = str2.length();

  int distanceTable[row+1][col+1];
  //populating the table in bottom up manner

  for(int i = 0; i<= row; i++){
    for(int j = 0; j<= col; j++){
      //if the first string is empty, only option is to insert all chars form str2
      if(i == 0)
        distanceTable[i][j] = j;
      
      //if second string is empty, only otpion is to insert all chars from str1
      else if(j == 0)
        distanceTable[i][j] = i;
      
      //if last chars are same, ignore last char, recr for remaining string
      else if(str1[i-1] == str2[j-1])
        distanceTable[i][j] = distanceTable[i-1][j-1];
      
      //if the last chars are diff, we consider all possibilities
      else
        distanceTable[i][j] = 1+ min(distanceTable[i][j-1],
                          distanceTable[i-1][j],
                          distanceTable[i-1][j-1]);
    }

  }

  return distanceTable[row][col];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
