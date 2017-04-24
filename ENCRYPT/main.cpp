/**
 * @author Jade Yeom
 * @link - https://algospot.com/judge/problem/read/ENCRYPT
 */
#include <iostream>

using namespace std;

bool isEvenNumber(int idx){
    return idx == 0 || idx % 2 == 0;
}

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        string inputString="";
        string evenString="";
        string oddString="";

        cin >> inputString;

        for (int idx = 0; idx < inputString.length(); idx++){
            if(isEvenNumber(idx)){
                evenString += inputString[idx];
            } else {
                oddString += inputString[idx];
            }
        }
        cout << evenString + oddString << endl;
    }
}