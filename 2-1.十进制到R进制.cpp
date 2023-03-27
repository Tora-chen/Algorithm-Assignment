#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void D_to_any(int n, int r) {
    string result = "";

    while (n > 0) {
        if (n % r >= 10) {
            result += 'A' - 10 + n % r;
        } else {
            result += '0' + n % r;
        }
        n /= r;
    };

    reverse(result.begin(), result.end());
    cout << result;
}
int main() {
    int n, r;
    cin >> n >> r;
    D_to_any(n, r);
    return 0;
}
