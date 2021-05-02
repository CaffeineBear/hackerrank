#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void removeUncommon(
    string & s1, string & s2, int (&s1Counter)[256], int (&s2Counter)[256],
    string & filteredS1, string & filteredS2
){
  for( char c : s1 ){
    s1Counter[c]++;
  }
  for( char c : s2 ){
    if(s1Counter[c] > 0){
      filteredS2 += c;
      s2Counter[c]++;
    }
  }
  for( char c : s1 ){
    if(s2Counter[c] > 0){
      filteredS1 += c;
    }
  }
}

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
  int s1Counter[256] = {0};
  int s2Counter[256] = {0};
  string filteredS2;
  string filteredS1;
  
  removeUncommon(s1, s2, s1Counter, s2Counter, filteredS1, filteredS2);
  cout << filteredS1 << endl;
  cout << filteredS2 << endl;


  unordered_map<char, vector<int> > s1CharMap;
  for (int i = 0; i < filteredS1.size(); ++i) {
    char currChar = filteredS1[i];
    s1CharMap[currChar].push_back(i);
  }
  
  //for (auto it = s1CharMap.begin(); it != s1CharMap.end(); ++it) {
  for (int i = 0; i < filteredS2.size(); ++i) {
    char currChar = filteredS2[i];
    auto it = s1CharMap.find(currChar); 
    if(it == s1CharMap.end()){
      continue;
    }
    int prevPos = *it[0];
    string currCombo;
    currCombo += currChar;
    for(int j =  i + 1; j < filteredS2.size(); ++j){
      char nextChar = filteredS2[i];
      auto it2 = s1CharMap.find(currChar); 
      if(it2 == s1CharMap.end()){
        continue;
      }
      int found = -1;
      for(int k : *it2){
        if( k > prevPos){
          found = k;
        }
      }


    }
    cout << currCombo << endl;
  }
  return 0;
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

