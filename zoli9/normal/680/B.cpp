#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int t[109];
int ans;
int main()
{
    cin>>n>>a;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(t[i]==1)
        {
            if(a==i)
            {
                ans++;
                continue;
            }
            int k;
            if(a>i) k=a+a-i;
            else k=a-(i-a);
            if(k<1 || n<k)
            {
                ans++;
                continue;
            }
            if(t[k]==1) ans++;
        }
    }
    cout<<ans;
    return 0;
}