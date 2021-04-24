#include <bits/stdc++.h>
#include <cassert>

using namespace std;

long computeSpecialNum(
    long consCount, long prevRepeatedAmt, long prevRepeatedEndIndex, long firstCharIndex, string & s
){
    long result = 0;
    // for computing aaaaaa, bbb and etc.
    // exclude number of repeated of single character as
    // it is already included.
    long repeatedAmt = consCount + 1;
    long numPossibleSubstr = (repeatedAmt * (repeatedAmt + 1))/2;
    result += (numPossibleSubstr - repeatedAmt);

    // Add to result for such as aaaaaabaaaa, cckccccccccc and etc.
    // Single odd occurence such as ckc is excluded as it is already
    // included.
    if(
        prevRepeatedAmt > 0
        && prevRepeatedEndIndex == firstCharIndex - 2
        && s[prevRepeatedEndIndex] == s[firstCharIndex]
    ){
        long smallerRepeatedAmt
            = prevRepeatedAmt < repeatedAmt ? prevRepeatedAmt : repeatedAmt;
        result += (smallerRepeatedAmt - 1);
    }
    return result;
}

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long result = 0;
    long consCount = 0; // consecutive counter.
    long firstCharIndex = -1;
    long prevRepeatedAmt = 0;
    long prevRepeatedEndIndex = -1;
    long prevStartIndex = -1;
    result++; // include first character.

    for(int i = 1; i < n; ++i){
        // for every single character.
        result++;

        // For repeated characters like oo, aaa and others,
        // will increment consecutive counter
        if(s[i] == s[i-1]){
            if(consCount == 0){
                firstCharIndex = i-1;
            }
            consCount++;
            continue;

        // non, ono, opo and etc.
        } else if(i - 2 >= 0 && s[i] == s[i-2]){
            result++;
        }

        if(consCount == 0 ){
            continue;
        }

        result += computeSpecialNum(
            consCount, prevRepeatedAmt, prevRepeatedEndIndex, firstCharIndex, s
        );

        prevStartIndex = firstCharIndex;
        prevRepeatedEndIndex = i - 1;
        prevRepeatedAmt = consCount + 1;
        consCount = 0;
    }

    if(consCount != 0){
        result += computeSpecialNum(
            consCount, prevRepeatedAmt, prevRepeatedEndIndex, firstCharIndex, s
        );
    }

    return result;
}

bool isSpecial(string s, int start, int end){
    if(s.empty()){
      return false;
    }
    int n = end - start + 1;
    int counter = 0;
    char first = s[start];
    for(int i = start; i < start + (n/2); ++i){
        if(s[i] != first){
            return false;
        }
        if(s[i] != s[end - counter]){
            return false;
        }
        counter++;
    }
    return true;
}

enum {UNCHECKED = 0, UNSPECIAL, SPECIAL};

// Naive solution.
long substrCount2(int n, string s) {
    long result = 0;
    map<string, int> isSpecialCount;
    for(int strSize = 1; strSize <= n; strSize++){
        for(int i = 0; i < n - strSize + 1; i++){
            string currstr = s.substr(i, strSize);
            if(isSpecialCount[currstr] == (int) UNCHECKED ){
                bool special = isSpecial(currstr, 0, currstr.size() - 1);
                isSpecialCount[currstr] = special ? SPECIAL : UNSPECIAL;
            }
            if(isSpecialCount[currstr] == (int) SPECIAL){
                result++;
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";
    // cout << result << endl;

    fout.close();

    return 0;
}
