#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> quickSortOptimized(vector<int> &a, int left, int right){
  int x = a[left];
  int leftPivot = left;

  //start the iterator at left aka 0 index
  int i = left;
  int rightPivot = right;

  vector<int> m(2);

  while(i <= rightPivot){

    if(a[i] < x){
      swap(a[leftPivot], a[i]);
      leftPivot++;
      i++;
    }
    else if(a[i] == x){
      i++;
    }
    else{
      swap(a[i],a[rightPivot]);
      rightPivot -= 1;
    }
    m[0] = leftPivot;
    m[1] = rightPivot;
  }
  return m;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  // int m = partition2(a, l, r);
  
  vector<int> m = quickSortOptimized(a,l,r);

  // randomized_quick_sort(a, l, m - 1);
  // randomized_quick_sort(a, m + 1, r);

  randomized_quick_sort(a, l, m[0]-1);
  randomized_quick_sort(a,m[1]+1,r);
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
