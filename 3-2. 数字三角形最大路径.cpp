#include <iostream>
using namespace std;

int n;
int arr[101][101]{0};

int maxroad(int r, int c) {
    if(r == n - 2) {
        return arr[r][c] + max(arr[r + 1][c], arr[r+ 1][c+1]);
    }
    return arr[r][c] + max(maxroad(r+1, c), maxroad(r+1, c+1));
}

int main()
{
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << maxroad(0, 0);
    return 0;
}
