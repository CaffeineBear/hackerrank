#include <its/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
  unordered_map<char, int> counter;
  int result = 0;
  for (int i = 0; i < a.size(); ++i) {
    char curr = a[i];
    counter[curr] += 1;
  }
  for (int i = 0; i < b.size(); ++i) {
    char currB = b[i];
    counter[currB] -= 1;
  }
  for (auto c: counter) {
    char currChar = c.first;
    int counted = abs(c.second);
    if(counted > 0){
      result += counted;
    }
  }
  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
b
