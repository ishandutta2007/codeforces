#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1,maxn=1000+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool isprime(int x)
{
    if(x==1)return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return false;
    return true;
}
bool P[maxn];
int S[maxn];
int main()
{
    //freopen("in","r",stdin);
    int n,k;cin>>n>>k;S[0]=0;
    For(i,1,n)P[i]=isprime(i),S[i]=S[i-1]+P[i];
    For(i,1,n)
    {
        if(!P[i])continue;
        int t=i-1;bool ok=false;
        For(k,1,t-1)if(k<t-k&&P[k]&&P[t-k]&&!(S[t-k-1]-S[k]))
        {
            ok=true;
            break;
        }
        k-=ok;
    }
    if(k<=0)puts("YES");
    else puts("NO");
}