#include <iostream>
#include <unordered_map>

using namespace std;



int fibonacci(int n) {
  unordered_map<int, int> fibDict;

  int sum  = 0;
  for(int i = 0; i < n; ++i){
    if(i == 0 || i == 1){
      fibDict[i] = 1;
      continue;
    }
    sum = fibDict[i-2] + fibDict[i-1];
    fibDict[i] = sum;
  }
  return sum;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}