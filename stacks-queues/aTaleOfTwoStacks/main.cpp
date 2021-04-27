#include <cmath>;
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        void push(int x) {
            // cout << "push: " << x << endl;
            stack_newest_on_top.push(x);
            vector<int> newStack;
            while(stack_oldest_on_top.size() > 0 ){
                int curr = stack_oldest_on_top.top();
                newStack.push_back(curr);
                stack_oldest_on_top.pop();
            }
            newStack.push_back(x);

            for(int i = newStack.size() - 1; i >= 0; --i){
                stack_oldest_on_top.push(newStack[i]);
            }
        }

        void pop() {
            // cout << "popping top of oldest: " << stack_oldest_on_top.top() << endl;
            stack_oldest_on_top.pop();
            vector<int> newStack;
            while(stack_newest_on_top.size() > 0 ){
                int curr = stack_newest_on_top.top();
                newStack.push_back(curr);
                stack_newest_on_top.pop();
            }
            for(int i = newStack.size() - 1; i >= 1; --i){
                stack_newest_on_top.push(newStack[i]);
            }
        }

        int front() {
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}