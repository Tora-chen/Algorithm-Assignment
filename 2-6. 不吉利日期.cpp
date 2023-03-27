#include <iostream>
using namespace std;
int dow(int y, int m, int d) { 
    y -= m<3; 
    return (y + y/4 - y/100 + y/ 400 + "-bed=pen+mat."[m] + d) % 7;
}
int main()
{
    int year;
    cin >> year;
    
    for(int i=1;i<=12;i++){
        if (dow(year, i, 13) == 5)
            cout << i << '\n';
    }

    return 0;
}
