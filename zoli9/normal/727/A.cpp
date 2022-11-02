#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long a, b;
bool f(long long x)
{
    if(x>b) return false;
    if(x==b)
    {
        v.push_back(x);
        return true;
    }
    if(f(2*x))
    {
        v.push_back(x);
        return true;
    }
    if(f(10*x+1))
    {
        v.push_back(x);
        return true;
    }
    return false;
}
int main()
{
    cin>>a>>b;
    if(f(a))
    {
       cout<<"YES"<<endl;
       cout<<v.size()<<endl;
       for(int i=v.size()-1; i>=0; i--)
       {
           cout<<v[i]<<" ";
       }
       cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}