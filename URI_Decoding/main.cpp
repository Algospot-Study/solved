/**
 * @author Jade Yeom
 * @link - https://algospot.com/judge/problem/read/URI
 */

#include <iostream>

using namespace std;

const int commonLength = 7;

const string uriKey[commonLength] = {" ","!","$","%","(",")","*" };
const string uriValue[commonLength] = {"%20", "%21", "%24", "%25", "%28", "%29", "%2a"};

string replaceAll(std::string &str, const std::string &from, const std::string &to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        string inputString;
        cin >> inputString;

        for (int i = 0; i < 7; i++)
            replaceAll(inputString, (string)uriValue[i], uriKey[i]);

        cout << inputString << endl;
    }
}