#include <iostream>
using namespace std;
void R_to_D(int a, int r) {
    int r_moto = r;
    int result{0};
    while(a > 0){
        int each = a % 10;
        result += each * (r/r_moto);
        a /= 10;
        r *= r_moto;
    }
    cout << result;
}
int main()
{
    int a, r;
    cin >> a >> r;
    
    R_to_D(a, r);
    return 0;
}
