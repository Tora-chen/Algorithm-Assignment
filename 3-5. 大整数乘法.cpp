#include <iostream>
#include <algorithm>
using namespace std;
string BigPlus(string a,string b)
{
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
    if(result[result.size()-1] > '9' ) {
        result += (result[result.size()-1] - '0' ) / 10 + '0';
        result[result.size()-2] = (result[result.size()-2] - '0') % 10 + '0';
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}
int main()
{
    string a,b;
    cin >> a >> b;
    
    // 逆序
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    // 各位相乘
    string result_sum = "0", zeros = "";
    for(auto x:b) {
        string result = ""; // 值即为大小
        for(auto y:a){
            result += (x-'0')*(y-'0');
        }
        
        // 进位
        for(int i=0;i<(int)result.size() - 1;i++){
            if(result[i] > 9) {
                result[i+1] += result[i] / 10;
                result[i] = result[i] % 10;
            }
        }
        if(result[result.size()-1] > 9 ) {
            result += result[result.size()-1] / 10;
            result[result.size()-2] = result[result.size()-2] % 10;
        }
        
        // 恢复字符形式
        for(auto &z : result) {
            z += '0';
        }

        reverse(result.begin(), result.end());
        // 添零
        result += zeros;
        
        // 相加
        result_sum = BigPlus(result, result_sum);
        zeros += '0';
    }
    
    cout << result_sum;

    return 0;
}

