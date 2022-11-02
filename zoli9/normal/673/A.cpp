#include <bits/stdc++.h>
using namespace std;
int n;
int t[109];
int main(){

    cin>>n;
    for(int i=1; i<=n; i++) cin>>t[i];
    t[0]=0;
    int akt=0;
    t[n+1]=91;
    while(1)
    {
        if(akt==n)
        {
            cout<<min(90, t[akt]+15);
            return 0;
        }
        if(t[akt]+15<t[akt+1])
        {
            cout<<t[akt]+15;
            return 0;
        }
        akt++;
    }
    return 0;
}