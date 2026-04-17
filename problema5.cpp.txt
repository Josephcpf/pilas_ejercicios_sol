#include <iostream>
#include <string>

#include "pila.h"
using namespace std;


string solve(const string& s) {
    Stack<string> pila1;
    Stack<int> pila2;
    string temp = "";
    int k= 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            k = k + s[i] - '0';
        }
        else if(s[i] == '[') {
            pila2.push(k);
            pila1.push(temp);
            k= 0;
            temp = "";
        }
        else if (s[i] == ']') {
            string prev = pila1.top();
            pila1.pop();
            int rep= pila2.top();
            pila2.pop();

            string repetidas= "";

            for (int j = 0; j < rep; j++) {
                repetidas = repetidas + temp;
            }
            temp = prev + repetidas;

        }
        else {
            temp += s[i];
        }
    }

    return temp;
}

void runTest(int testNumber, const string& input, const string& expected) {
    string result = solve(input);
    if (result == expected) {
        cout << "Test " << testNumber << " OK\n";
    } else {
        cout << "Test " << testNumber << " FAILED\n";
        cout << "Input: " << input << "\n";
        cout << "Esperado: " << expected << "\n";
        cout << "Obtenido: " << result << "\n\n";
    }
}

int main() {
    runTest(1, "3[a]", "aaa");
    runTest(2, "2[ab]3[c]", "ababccc");
    runTest(3, "3[a2[c]]", "accaccacc");
    runTest(4, "1[x]", "x");
    runTest(5, "2[abc]3[cd]ef", "abcabccdcdcdef");
    return 0;
}