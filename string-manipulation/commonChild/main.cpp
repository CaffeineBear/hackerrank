#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
int commonChild(string s1, string s2) {
  // unordered<char, int> s1Counter;
  int result = 0;
  int N = s1.size();
  int M = s2.size();
  vector<vector<int>> C(N+1, vector<int>(M+1));
  for (int i = 0; i < s1.size(); ++i) {
    for (int j = 0; j < s2.size(); ++j) {
      if(s1[i] == s2[j]){
        C[i+1][j+1] = C[i][j] + 1;
        continue;
      }
      C[i+1][j+1] = max(C[i+1][j], C[i][j+1]);
    }
  }
  // cout << " ";
  // cout << "     ";
  // for (int j = 0; j < M + 1; ++j) {
  //   cout << s2[j] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < N + 1; ++i) {
  //   for (int j = 0; j < M + 1; ++j) {
  //     if(j == 0 && i == 0){
  //       cout << " ";
  //       cout << " : ";
  //     }
  //     if(j == 0 && i > 0){
  //       cout << s1[i-1] << " : ";
  //     }
  //     cout << C[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return C[N][M];
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string s1;
  getline(cin, s1);

  string s2;
  getline(cin, s2);

  int result = commonChild(s1, s2);

  fout << result << "\n";

  fout.close();

  return 0;
}

