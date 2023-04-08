#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string del(string a, int n) {
    return a.erase(n,1);
} 
string min_num(string a) {
    int min_res = stoi(del(a,0));
    for(int i=1;i<(int)a.size();i++){
        string temp = del(a,i);
        min_res = min(min_res, stoi(temp));
    }
    return to_string(min_res);
}
int main()
{
    string m;
    int k;
    cin >> m >> k;
    
    for(int i=0;i<k;i++){
        m = min_num(m);
    }
    
    cout << m;
    return 0;
}
