#include <bits/stdc++.h>
using namespace std;
int deg[100009];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(deg[i]==2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}