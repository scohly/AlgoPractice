#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority(vector<int> &a, int left, int right) {
  //1 Element no majority
  // if (left == right) return -1;

  // if (left + 1 == right) return a[left];
  //write your code here

//FAILS AND ONLY RETURNS 0
  int candidate = -1;
  int frequencyCount = 0;

  for(int i= 0; i<a.size();i++){
    if(frequencyCount == 0){
      candidate = a[i];
      frequencyCount = 1;
      continue;
    }
    else{
      if (candidate == a[i]){
        frequencyCount = frequencyCount+1;
      }
      else{
        frequencyCount = frequencyCount-1;
      }

    }
    if(frequencyCount == 0){
      return -1;
    }

  }
  //step 2, is candidate a majority element?
  for(int i = 0; i<a.size();i++){
    if(candidate == a[i]){
      frequencyCount = frequencyCount+1;
    }
  }
 return (frequencyCount > a.size()/2 ) ? 1:-1;
}




//Attempt 2
int get_majority_element(vector<int> &a, int left, int right){
  if(left == right ) return -1;
  if(left + 1 == right) return a[left];

  int leftCandidate = get_majority_element(a,left,(left + right -1)/2 + 1);
  int rightCandidate = get_majority_element(a,(left+right - 1)/2 + 1, right);

  int leftFrequency = 0;
  for(int i = left; i < right; i++){
    if(a[i] == leftCandidate)
      leftFrequency += 1;
  }
  if(leftFrequency > (right - left )/2 )
    return leftCandidate;

  int rightFrequency = 0;
  for(int i = left; i< right; i++){
    if(a[i] == rightCandidate)
      rightFrequency +=1;
  }
  if(rightFrequency > (right - left)/2 )
    return rightCandidate;
  
  return -1;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  
}
