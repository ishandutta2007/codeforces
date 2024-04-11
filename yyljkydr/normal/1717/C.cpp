#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1),b(n+1),da(n+1),db(n+1);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        bool ok=1;
        for(int i=0;i<n;i++)
            ok&=(a[i]<=b[i]),ok&=(b[(i+1)%n]>=b[i]-1||a[i]==b[i]);
        puts(ok?"Yes":"No");
    }
}