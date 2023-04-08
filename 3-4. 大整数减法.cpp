#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    cin >> a >> b;
    
    // 去除前导零
    for(int i=0;i<(int)a.size()-1;i++){
        if(a[i] != '0')  {
            a=a.substr(i);
            break;
        }
    }
    for(int i=0;i<(int)b.size()-1;i++){
        if(b[i] != '0')  {
            b=b.substr(i);
            break;
        }
    }
        
    // 把a作为位数最多的
    bool symbol = 0;
    if(a.size() < b.size()) {
        symbol = 1;
        swap(a,b);
    }
    
    // 分别计算每一位的差
    string result= "";
    for(int i = 1;i <= (int)a.size();i++){
        if((int)b.size() - i < 0) {
            result += a[a.size() - i];
            continue;
        }
        result += a[a.size() - i] - b[b.size() - i] + '0';
    }
    
    // 借位
    for(int i=0;i<(int)a.size() - 1;i++){
        if(result[i] < '0') {
            result[i+1] -= 1;
            result[i] += 10;
        }
    }
    if(result.back() < '0' ) {
        result.back() = '0' - result.back() + '0';
        symbol = !symbol;
    }
    
    reverse(result.begin(), result.end());
    
    // 去除结果前导零
    for(int i=0;i<(int)result.size();i++){
        if(result[i] != '0' || i == (int)result.size() - 1)  {
            result=result.substr(i);
            break;
        }
    }
    
    cout << (symbol ? "-":"") << result;
    
    return 0;
}
