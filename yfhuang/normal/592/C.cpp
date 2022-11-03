#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define read freopen("in.txt","r",stdin)
#define maxlongint 2147483647
#define maxn 1060
long long  gcd(long long  a,long long b)
{
    long long r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
using namespace std;
long long k,tt,t,w,b,sum,ans;
int main()
{
    cin>>t>>w>>b;
    k=gcd(w,b);
    if (w>b) swap(w,b);
    if ((double)b/k>(double)t/w) ans=w-1;
    else
    {
        sum=(double)t/w*(double) k/b;
        tt=t%(w/k*b);
        ans=sum*(w)+min(tt,w-1);
    }
    k=gcd(t,ans);
    if (ans>t) ans=t;
    if (ans/k==t/k) cout<<"1/1"<<endl;
    else cout<<ans/k<<"/"<<t/k<<endl;
    return 0;
}