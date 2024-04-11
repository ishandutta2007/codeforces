#include <bits/stdc++.h>
using namespace std;
int n;
string s;
long long res;
long long MOD=998244353;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    int c1=0;
    int c2=n-1;
    while(c1<n && s[c1]==s[0]) c1++;
    c1--;
    while(c2>=0 && s[c2]==s[s.size()-1]) c2--;
    c2++;
    if(c1==n-1)
    {
        res=n*(n+1);
        res/=2;
        res%=MOD;
        cout<<res<<endl;
        return 0;
    }
    if(s[0]==s[n-1])
    {
        long long res1=c1+2;
        long long res2=(n-c2)+1;
        res=(res1*res2)%MOD;
        cout<<res<<endl;
        return 0;
    }
    else
    {
        res=c1+1+(n-c2)+1;
        res%=MOD;
        cout<<res<<endl;
        return 0;
    }
    return 0;
}