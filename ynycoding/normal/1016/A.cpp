#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
    cin>>n>>m;
    int now=0;
    for(int i=1; i<=n; ++i)
    {
        int a;
        cin>>a;
        now+=a;
        cout<<now/m<<" ";
        now%=m;
    }
    return 0;
}