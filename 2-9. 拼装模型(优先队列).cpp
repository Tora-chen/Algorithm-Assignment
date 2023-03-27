#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue < int, vector<int>, greater<int> > model;
    
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        model.push(temp);
    }
    
    long long time{0};
    while(model.size() > 1){
        int a = model.top();
        model.pop();
        int b = model.top();
        model.pop();
        
        model.push(a+b);
        time += a+b;
    }
    
    cout << time;
    
    return 0;
}
