#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(const string& path) {
    // TODO: Implementar solución usando pila de directorios
    return "";
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
