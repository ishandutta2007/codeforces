#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    bool x[n];
    for(int i=0;i<n;i++) cin>>x[i];
    bool ans=false;
    for(int i=0;i<n;i++) ans|=x[i];
    cout<<(ans?"HARD":"EASY");
    return 0;
}