#include <iostream>
using namespace std;
void getl(string& A)
{
    while (1) {
        char temp = getchar();
        if (temp == ' ') continue;
        else if (temp == '\n') break;
        else if (temp >= 'A' && temp <= 'Z') {
            temp = temp - 'A' + 'a';
        }
        A += temp;
    }


}
int main()
{
    int n;
    cin >> n;
    getchar();

    for (int i = 0; i < n; i++) {
        string A = "", B = "";
        getl(A);
        getl(B);
        cout << (A == B ? "YES" : "NO") << '\n';
        getchar();
    }
    return 0;
}
/*
3



a A bb BB ccc CCC
Aa BBbb CCCccc

a              dfadf              fasdf
adasddfsfsaf
 */
