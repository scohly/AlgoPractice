#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

//For the sake of simplicty, declaring max bounds for weight and itemcount

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  //OUR table for finding the optimal weight 
  //aka max weight that is equal or less than cap
  //for DP we NEED to construct a 2d array...least how i grasped concept
  const int w_size = w.size();

  int** weightOptimal = new int*[w_size+1];
  //make our size const, moment we get vector in we can take .size()

  for(int i=0; i <= w_size; i++){
    weightOptimal[i] = new int[W+1];
  }
 

  for(int i=0; i<= w_size; i++){
    for(int j=0; j<= W; j++){
      if( i == 0 || j == 0){
        //i corresponds to element position in gold vec
        //j corresponds to weight capacity aka 1...W 
        //we set the i = 0, j=0 positions to 0
        weightOptimal[i][j] = 0;
      }
      else if( w[i-1] <= j){
        //if the gold with the given weight is <= capacity at positon j
        weightOptimal[i][j] = std::max(w[i-1] +weightOptimal[i-1][j-w[i-1]],weightOptimal[i-1][j]);
      
      }
      else{
        weightOptimal[i][j] = weightOptimal[i-1][j];
      }
    }
  }

  int optimalWeight = weightOptimal[w_size][W];

  for(int i = 0; i < w_size; i++){
    delete[] weightOptimal[i];
  }

  delete[] weightOptimal;

  return optimalWeight;

}

int main() {
  int n, W;
  std::cin >> W >> n;
  //read in from user weight of bag W, number of items to choose from n

  vector<int> w(n);
  //create a vector of type int with n # elements

  //iterate each vector position till its size n, store each element entered
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
