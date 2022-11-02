#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    int e=0;
    int f=0;
    for(int i=0; i<b.size(); i++)
    {
        if(a[i]=='1') e++;
        if(b[i]=='1') f++;
    }
    int ans=0;
    if(e%2==f%2) ans++;
    for(int i=b.size(); i<a.size(); i++)
    {
        if(a[i]=='1') e++;
        if(a[i-(int)b.size()]=='1') e--;
        if(e%2==f%2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}