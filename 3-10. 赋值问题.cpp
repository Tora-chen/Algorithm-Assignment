#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    string vals[101];
    for(int i=0;i<n;i++){
        cin >> vals[i];
    }
    
    string HaveVal = "a";
    for(int i=0;i<n;i++){
        if(HaveVal.find(vals[i][2]) < 999) {
            HaveVal += vals[i][0];
        } else {
            if(HaveVal.find(vals[i][0]) < 999) {
                HaveVal.erase(HaveVal.find(vals[i][0]));
            }
        }
    }
    
    sort(HaveVal.begin(),HaveVal.end());
    
    if(HaveVal.size() == 0) {
        cout << "none";
    }else {
        for(int i=0;i<(int)HaveVal.size();i++){
            cout << HaveVal[i] << ' ';
        }
        if(HaveVal.size() == 1){
            cout << "only";
        }
    }
    return 0;
}
