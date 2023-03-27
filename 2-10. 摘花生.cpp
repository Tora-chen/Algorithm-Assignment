#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef struct node {
    int num;
    int where[2];
    friend bool operator < (const node a, const node b) {
        return a.num < b.num;
    }
}node;

int main()
{
    int n1;
    cin >> n1;
    
    for(int i=0;i<n1;i++){
        priority_queue <node> peanut;
        int m,n,k;
        cin >> m >> n >> k;
        
        // 输入花生的个数，地点,将其加入队列
        for(int r=1;r<=m;r++){
            for(int c=1;c<=n;c++){
                
                int temp;
                cin >> temp;
                if (temp == 0) continue;
                else {
                    node tmp;
                    tmp.num = temp;
                    tmp.where[0] = r;
                    tmp.where[1] = c;
                    peanut.push(tmp);
                }
            }
        }
        
        // 第一颗“花生”设为路边
        node road {999, {0, peanut.top().where[1]}};
        peanut.push(road);
        
        int ans = 0, time = 0;
        while(1){
            node now = peanut.top();
            peanut.pop();
            if (peanut.size() == 0) break; // 如果花生全采完了
            node nxt = peanut.top();
            
            time += abs(now.where[0] - nxt.where[0]) + abs(now.where[1] - nxt.where[1]) + 1;
            ans += nxt.num;
            
            if(time + nxt.where[0] > k) {
                ans -= nxt.num;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
