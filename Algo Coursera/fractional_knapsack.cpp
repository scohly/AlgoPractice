#include <iostream>
#include <vector>


using std::vector;


int find_max_index (vector<int> weights, vector<int> values) {
    int maxIndex = 0;
    double maxRatio = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double)values[i]/weights[i] > maxRatio) {
            maxRatio = (double)values[i]/weights[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double loot = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return loot;

        int index = find_max_index(weights, values);
        int availableWeight = std::min(capacity, weights[index]);

        loot += availableWeight * ( (double)values[index]/weights[index] );
        weights[index] -= availableWeight;
        capacity -= availableWeight;
    }

    return loot;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  // std::cout<<"max index: "<<findMaxIndex(values,weights)<<'\n';

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);

  std::cout << optimal_value << std::endl;
  return 0;
}
