#include <iostream>
#include <cassert>
#include <vector>

using std::vector;


int binarySearch(const vector<unsigned long int> inp, int left, int right, int key){
  if(right<left){
    return -1;
  }
  int mid = left + ((right-left)/2);
  if(inp[mid] == key){
    return mid;
  }
  else if( key > inp[mid]){
    return binarySearch(inp, mid+1, right, key);
  }
  else{
    return binarySearch(inp, left, mid-1, key);
  }
}


int binary_Search(const vector<unsigned long int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
    return binarySearch(a,left,right,x);
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int binary_search(const vector<unsigned long int>&a, int key){
  int left = 0, right = (int)a.size(); 
  //opted to use whileLoop and an iterative approach

  while(left <= right){
    int mid = left + (right-left) / 2;
    if(key == a[mid]){
      return mid;
    }
    else if(key < a[mid]){
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<unsigned long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<unsigned long int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
