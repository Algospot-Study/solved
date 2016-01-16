#include <iostream>
#include <stack>

using namespace std;

const string openString = "({[", closeString = ")}]";

bool isMatched(string &inputString) {
    stack<char> inputStack;
    for (int i = 0; i < inputString.size(); ++i) {
        char tmpChar = inputString[i];
        try {
            if (tmpChar == openString[0] || tmpChar == openString[1] || tmpChar == openString[2])
                inputStack.push(inputString[i]);
            else {
                if (inputStack.empty()) return false;
                if (tmpChar == closeString[0] && inputStack.top() == openString[0]) {
                    inputStack.pop();
                } else if (tmpChar == closeString[1] && inputStack.top() == openString[1]) {
                    inputStack.pop();
                } else if (tmpChar == closeString[2] && inputStack.top() == openString[2]) {
                    inputStack.pop();
                }
            }
        }catch (int exception){
            return false;
        }
    }
    return inputStack.empty();
}

int main() {
    int testCase;
    string inputString;
    cin >> testCase;
    for (int i = 0; i < testCase; ++i) {
        cin >> inputString;
        if (isMatched(inputString)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}