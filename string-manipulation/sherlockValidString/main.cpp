#include <bits/stdc++.h>
#include <climits>

using namespace std;

void printOccurence(vector<pair<int, int>> patterns){
    for(auto &it: patterns){
        cout << "count: " << it.first << ", ";
        cout << "numOfKeyRelated: " << it.second << endl;
    }
}

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    const int NUM_ALPHABETS = 26;
    int charCounter[NUM_ALPHABETS];
    unordered_map<int, int> occurenceDict;
    for(int i = 0; i < NUM_ALPHABETS; ++i){
        charCounter[i] = 0;
    }

    for(char c : s){
        int currCount = ++charCounter[c - 'a'];
        occurenceDict[currCount] += 1;
        if(currCount - 1  > 0 && occurenceDict[currCount - 1] != 0){
            occurenceDict[currCount - 1] -= 1;
        }
    }

    vector<pair<int, int>> patterns;
    for( auto &it : occurenceDict){
        if(it.second >= 1){
            patterns.push_back(make_pair(it.first, it.second));
        }
    }

    // More than two patterns of number of counts.
    if(patterns.size() > 2){
        return "NO";
    }

    if(patterns.size() == 2){
        // case 1 There should be only one character index affected for different
        // patterns of counts.
        if(patterns[0].second != 1 && patterns[1].second != 1){
            return "NO";
        }

        // case 2 it should be either count diff is 1 or count itself is 1.
        int countThatHasOnlyOneCharRelated
            = patterns[0].second == 1 ? patterns[0].first : patterns[1].first;
        int diff = abs(patterns[0].first - patterns[1].first);
        if(countThatHasOnlyOneCharRelated != 1 && diff != 1 ){
            return "NO";
        }


    }

    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
