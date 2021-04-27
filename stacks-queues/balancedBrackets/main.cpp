#include <bits/stdc++.h>

using namespace std;

bool isOpening(char c){
    return c == '(' || c == '{' || c == '[';
}

bool isClosing(char c){
    return c == ')' || c == '}' || c == ']';
}

// Complete the isBalanced function below.
string isBalanced(string s) {
    string result = "YES";
    map<char, char> bracketDict;
    bracketDict['{'] = '}';
    bracketDict['['] = ']';
    bracketDict['('] = ')';

    deque<char> bracketsStack;
    for(char c : s){
        if(isOpening(c)){
            bracketsStack.push_back(c);
            continue;
        }
        if(isClosing(c)){
            if(bracketsStack.size() == 0){
                result = "NO";
                break;
            }
            char poppedBracket = bracketsStack.back();
            if(c != bracketDict[poppedBracket]){
                result = "NO";
                break;
            }
            bracketsStack.pop_back();
        }
    }
    if(bracketsStack.size() != 0){
        result = "NO";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
