#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string Del_0_Head(string a) {
    for(int i=0;i<(int)a.size()-1;i++){
        if(a[i] != '0')  {
            return a.substr(i);
        }
    }
    return "0";
}
string BigMinus(string a, string b) {
    // 去除前导零
    Del_0_Head(a);
    Del_0_Head(b);
    
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
    Del_0_Head(result);
    
    return (symbol ? "-":"") + result;
}

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
    if(result.back() > '9' ) {
        result += (result.back() - '0' ) / 10 + '0';
        result[result.size()-2] = (result[result.size()-2] - '0') % 10 + '0';
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string BigTimes(string a, string b)
{
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
    
    return result_sum;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string a,b;
        cin >> a >> b;
        if(a.size() < b.size()) {
            cout << 0 << '\n';
            continue;
        }
        if(b == "1") {
            cout << a << '\n';
            continue;
        }
        
        string result = "";
        for(int j=b.size()-1;j < (int)a.size();j++){
            for(int trys = 9; trys >= 0; trys--) {
                string temp_res = BigMinus(a.substr(0,j+1), BigTimes(to_string(trys), b));
                if(temp_res[0] == '-') continue;
                
                a.erase(0,j+1);
                a = temp_res+a;
                result += to_string(trys);
                break;
            }
        }
        
        //去除结果前导零
        Del_0_Head(result);
        
        cout << result << '\n';
    }
    
    return 0;
}
