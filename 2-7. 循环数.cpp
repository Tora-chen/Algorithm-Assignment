#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        string s_num;
        cin >> s_num;
        int size = s_num.size();
        
        // 转成整数形式
        long long i_num = 0;
        long long k = 1;
        for (int i = size - 1; i >= 0; i--) {
            i_num += (s_num[i] - '0') * k;
            k *= 10;
        }

        // 依次相乘
        bool IsCyclic = 1;
        for (int i = 2; i <= size; i++) {
            long long i_new_num = i_num * i;
            // 转回字符串
            string s_new_num(size, ' ');
            for (int i = size - 1; i >= 0; i--) {
                s_new_num[i] = i_new_num % 10 + '0';
                i_new_num /= 10;
            }            
            
            // 是不是循环数？
            string s_num_2 = s_num + s_num;
            if ((int)s_num_2.find(s_new_num) == -1) {
                IsCyclic = 0;
            }
        }
        
        if(IsCyclic == 1){
            cout << s_num << " is cyclic\n";
        }else{
            cout << s_num << " is not cyclic\n";
        }    
        
    }
    return 0;
}

/*
5
142857
142856
142858
01
0588235294117647
 */
