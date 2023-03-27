#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        char a[100001]{0}, b[100001]{0};
        scanf("%s %s", a, b);
        
        int pa = 0, pb = 0;
        while(1){
            if (a[pa] == b[pb]) {
                pa++;
                pb++;
            } else {
                pb++;
            }
            
            if (b[pb] == 0 && a[pa] != 0) {
                printf("No\n");
                break;
            } else if (b[pb] == 0 && a[pa] == 0) {
                printf("Yes\n");
                break;
            }
        }
    }
    return 0;
}
