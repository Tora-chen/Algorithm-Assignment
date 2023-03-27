#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    // 输入所有号码
    char numbers[10001][8]{ 0 };
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 7;j++) {
            do{
                cin >> numbers[i][j];
            }while(numbers[i][j] == '-'); // 遇‘-’跳过
            
            // trans
            if (numbers[i][j] >= 'A' && numbers[i][j] <= 'Y') {
                numbers[i][j] = "2223334445556667777888999"[numbers[i][j] - 'A'];
            }
        }
    }

    // 标记重复的号码
    int memo[10001][2]{0}; // 第一位为重复号码的下标，第二位为重复次数
    int DoCounted[10001]{0}; // 标记此号是否已经比较过
    int end = 0;
    for (int i = 0; i < n; i++) {
        if(DoCounted[i] == 1) continue;
        
        bool IfSame = 0;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(numbers[i], numbers[j]) == 0) {
                IfSame = 1;
                DoCounted[j] = 1;
                memo[end][0] = i;
                memo[end][1] += 1;
            }
        }

        end += IfSame;
    }
    
    // Sort
    for(int i=0;i < end - 1;i++){
        for (int j = 0; j < end - i - 1; j++) {
            if(strcmp(numbers[memo[j][0]], numbers[memo[j+1][0]]) > 0){
                int temp = memo[j][0];
                memo[j][0] = memo[j+1][0];
                memo[j+1][0] = temp;
                
                int temp_ = memo[j][1];
                memo[j][1] = memo[j+1][1];
                memo[j+1][1] = temp_;
                
            }
        }
    }
    
    // 输出重复的号码以及重复次数
    if(end){
        for (int i = 0; i < end; i++) {
            for(int j = 0;j < 7;j++){
                if(j == 3) cout << '-';
                cout << numbers[memo[i][0]][j];
            }
            cout << ' ' << memo[i][1] + 1 << '\n';
        }
    } else 
        cout << "No duplicates.\n";

    return 0;
}
