#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,m;
    cin>>n>>m;
    vector<long long>a(n),b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    long long g=0;
    for(int i=1;i<n;i++)
        g=__gcd(g,abs(a[i]-a[i-1]));
    for(int i=0;i<m;i++)
        cout<<__gcd(g,a[0]+b[i])<<endl;
}