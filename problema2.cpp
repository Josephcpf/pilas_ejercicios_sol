#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(const string& path) {
    Stack<string> pila;
    string temp;
    for (int i = 0; i <= path.size(); i++) {
        if (i == path.size() or path[i] == '/') {
            if (temp == "..") {
                if (!pila.isEmpty()) {pila.pop();}
            }
            else if (!temp.empty() and temp!= ".") {
                pila.push(temp);
            }
            temp ="";
        }
        else {
            temp += path[i];
        }
    }

    string result;
    while (!pila.isEmpty()) {
        result = "/" + pila.top()+ result;
        pila.pop();
    }

    if (result.empty()) {
    return "/";
} else {
    return result;
}
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
    runTest(1, "/home/", "/home");
    runTest(2, "/../", "/");
    runTest(3, "/home//foo/", "/home/foo");
    runTest(4, "/a/./b/../../c/", "/c");
    runTest(5, "/home//foo/../bar/./baz/", "/home/bar/baz");
    return 0;
}
