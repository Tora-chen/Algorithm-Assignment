#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    
    for(int b=1;b<=6;b++){
        if (a == b) continue;
        
        for(int c=1;c<=6;c++){
            if (c == a || c == b) continue;

            for(int d=1;d<=6;d++){
                if(d == a || d == b || d == c) continue;
                
                for(int e=1;e<=6;e++){
                    if(e == a|| e==b||e==c||e==d) continue;
                    
                    for(int f=1;f<=6;f++){
                        if(f == a||f==b||f==c||f==d||f==e) continue;

                        if((a+b+c == c+d+e) && (c+d+e) == (e+f+a)){
                            cout << a<<b<<c<<d<<e<<f<<'\n';
                        }
                    }
                }
            }
        }
    }
    return 0;
}
