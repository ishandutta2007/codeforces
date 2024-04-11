#include <bits/stdc++.h>
using namespace std;
set<long long> s;
int n;
bool lv(long long a)
{
    long long b=a/2;
    while(b>0 && s.find(-b)!=s.end()) b/=2;
    if(b==0) return false;
    s.erase(-a);
    s.insert(-b);
    return true;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        long long a;
        cin>>a;
        s.insert(-a);
    }
    while(1)
    {
        long long x=*s.begin();
        if(!lv(-x)) break;
    }
    auto it=s.begin();
    while(it!=s.end())
    {
        cout<<-(*it)<<" ";
        it++;
    }
    return 0;
}