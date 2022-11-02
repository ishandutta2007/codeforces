#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
string a,b;
int Cost(string a,string b)
{
    int Cnt=0;
    rep(i,a.size())
        if(a[i]!=b[i])
            Cnt++;
    return Cnt/2;
}
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;int H=0,T=0;
    cin>>a;rep(i,a.size())if(a[i]=='H')H++;else T++;
    b="";rep(i,H)b+='H';rep(i,T)b+='T';
    int ans=~0U>>1;
    rep(m,b.size()*2)
    {
        b=b.substr(1)+b[0];
        ans=min(ans,Cost(a,b));
    }
    cout<<ans<<endl;
}