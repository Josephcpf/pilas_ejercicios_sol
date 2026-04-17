#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(const vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);  // inicializa todo en -1
    Stack<int> s;            // guarda índices, no valores

    for (int i = 0; i < n; i++) {
        // mientras el elemento actual sea mayor que el tope, este bucle sirve para que entren y saquen indices
        while (!s.isEmpty() && arr[s.top()] < arr[i]) {
            res[s.top()] = arr[i];  // arr[i] es la respuesta de ese índice
            s.pop();
        }
        s.push(i);  // siempre pusheas el índice actual
    }

    return res;
}
bool equalVectors(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

void runTest(int testNumber, const vector<int>& input, const vector<int>& expected) {
    vector<int> result = solve(input);
    if (equalVectors(result, expected)) {
        cout << "Test " << testNumber << " OK\n";
    } else {
        cout << "Test " << testNumber << " FAILED\n";
        cout << "Esperado: ";
        printVector(expected);
        cout << "\nObtenido: ";
        printVector(result);
        cout << "\n\n";
    }
}

int main() {
    runTest(1, {2,1,2,4,3}, {4,2,4,-1,-1});
    runTest(2, {4,3,2,1}, {-1,-1,-1,-1});
    runTest(3, {1,2,3,4}, {2,3,4,-1});
    runTest(4, {5}, {-1});
    runTest(5, {1,3,2,4}, {3,4,4,-1});
    return 0;
}
