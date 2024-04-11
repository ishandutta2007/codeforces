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
const int inf=~0U>>1,maxn=100000+10,Log=20,seed=133331;
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll F=354871524;
map<int,VI> Map;
int n,A[maxn];
ll P[Log];
ll Hash[maxn][Log];
void DoIt()
{
    P[0]=seed;rep(i,Log-1)P[i+1]=P[i]*P[i];
    rep(j,Log)rep(i,n)
    if(i+(1<<j)<=n)
    {
        ll&tmp=Hash[i][j];
        if(!j)tmp=A[i]^F;
        else tmp=(Hash[i][j-1])*P[j-1]+Hash[i+(1<<(j-1))][j-1];
    }
}
int Lcp(int a,int b)
{
    if(a>b)swap(a,b);int ret=0;
    for(int i=Log-1;i>=0;i--)
    {
        if(b+(1<<i)>n)continue;
        if(Hash[a][i]==Hash[b][i])
            a+=(1<<i),b+=(1<<i),ret+=(1<<i);
    }
    return ret;
}
bool Check(int a,int b)
{
    int s=b-a;
    return Lcp(a,b)>=s;
}
struct Seg
{
    int l,r,s;
    Seg(int _l,int _r):l(_l),r(_r),s(r-l){}
    bool operator<(const Seg&o)const
    {
        if(s!=o.s)return s<o.s;
        return l<o.l;
    }
};
int main()
{
    //freopen("in","r",stdin);
    cin>>n;
    rep(i,n)scanf("%d",A+i),Map[A[i]].pb(i);
    DoIt();
    vector<Seg> S;
    for(map<int,VI>::iterator it=Map.begin();it!=Map.end();it++)
    {
        VI&tmp=it->second;
        For(i,0,tmp.size()-1)
            For(j,i+1,tmp.size()-1)
                if(Check(tmp[i],tmp[j]))
                    S.pb(Seg(tmp[i],tmp[j]-1));
    }
    sort(S.begin(),S.end());
    int now=0;
    rep(i,S.size())
    {
        Seg&tmp=S[i];
        if(tmp.l>=now)now=tmp.r+1;
    }
    cout<<n-now<<endl;
    For(i,now,n-1)cout<<A[i]<<" ";
}