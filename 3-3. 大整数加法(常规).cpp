#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    // 把a作为位数最多的
    if(a.size() < b.size())  swap(a,b);
    
    // 分别计算每一位的和
    string result= "";
    for(int i = 1;i <= (int)a.size();i++){
        if((int)b.size() - i < 0) {
            result += a[a.size() - i];
            continue;
        }
        result += a[a.size() - i] - '0' + b[b.size() - i];
    }
    
    // 进位
    for(int i=0;i<(int)a.size() - 1;i++){
        if(result[i] > '9') {
            result[i+1] += (result[i] - '0') / 10;
            result[i] = (result[i] - '0') % 10 + '0';
        }
    }
    if(result.back() > '9' ) {
        result += (result.back() - '0' ) / 10 + '0';
        result[result.size()-2] = (result[result.size()-2] - '0') % 10 + '0';
    }
    
    reverse(result.begin(), result.end());
    cout << result;
    
    return 0;
}
