#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        
        int qian = 1, hou = 1;
        for(int i=2;i<a;i++){
            int new_ = (qian + hou)%1000;
            qian = hou;
            hou = new_;
        }
        cout << hou << '\n';
    }
    return 0;
}
