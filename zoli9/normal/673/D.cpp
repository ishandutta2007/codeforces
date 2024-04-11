#include <bits/stdc++.h>
using namespace std;
int n, k;
int a, b, c, d;
vector<int> v;
int main()
{
    cin>>n>>k;
    cin>>a>>b>>c>>d;
    if(n<=4)
    {
        cout<<-1;
        return 0;
    }
    if(k<=n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=a && i!=b && i!=c && i!=d) v.push_back(i);
    }
    cout<<a<<" "<<c<<" ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<d<<" "<<b<<endl;
    cout<<c<<" "<<a<<" ";
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<b<<" "<<d<<endl;
    return 0;
}