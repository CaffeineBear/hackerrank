#include <bits/stdc++.h>
#include <unordered_map>
#include <cassert>

using namespace std;
using IntCounter = unordered_map<int, int>;

vector<string> split_string(string);

int debug = false;
int largeDebug = false;

void printAllBribes(vector<int> & q){
  for(int i = 0; i < q.size(); ++i){
    std::cout << q[i];
    if(i + 1 < q.size()){
      std::cout << " ";
    }
  }
  std::cout << endl;
}

void swap(vector<int> & q, int a, int b){
  if(debug == true){
    std::cout << q[a] << " <-> " << q[b];
  }
  int temp = q[a];
  q[a] = q[b];
  q[b] = temp;
  if(debug == true){
    std::cout << " : ";
    printAllBribes(q);
  }
}


// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
  IntCounter bribedCounter;
  int result = 0;

  for(int i = 1; i < q.size(); ++i){
    if(debug){
      std::cout << "------------" << endl;
      std::cout << "i: " << i << endl;
      printAllBribes(q);
    }

    // Bubble sort but stop if bribbed counter exceeds 2.
    int currIndex = i;
    while(q[currIndex-1] > q[currIndex]){
      // increment counter on the front one (currIndex -1)
      // because current array is the result of
      // their swapping so we have to count backwards.
      if(++bribedCounter[q[currIndex-1]] > 2){
        cout << "Too chaotic" << endl;
        return;
      }
      swap(q, currIndex-1, currIndex);
      currIndex -= 1;
      result++;
      if(currIndex == 0){
        break;
      }
    }
  }
  if(largeDebug){
    printAllBribes(q);
  }
  cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
