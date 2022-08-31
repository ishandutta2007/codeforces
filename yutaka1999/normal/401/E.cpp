#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int p;
int n,m;

int search(ll x)
{
    int s=0,e=200000;
    while(e-s>1)
    {
        int med=(s+e)/2;
        if((ll)med*(ll)med>x) e=med;
        else s=med;
    }
    return s;
}
ll cnt(ll dist)
{
    if(dist<1) return 0;
    ll ret=(ll) n*(ll) (m+1)+(ll) m*(ll) (n+1);
    ret%=p;
    for(int i=1;i<=n;i++)
    {
        if(dist<(ll) i*(ll) i) break;
        int zan=search(dist-(ll) i*(ll) i);zan=min(zan,m);
        if(zan==0) break;
        int lim=i;
        ll sum=0;
        vector <int> pr;
        for(int j=2;j*j<=lim;j++)
        {
            if(lim%j==0)
            {
                pr.push_back(j);
                while(lim%j==0) lim/=j;
            }
        }
        if(lim!=1) pr.push_back(lim);
        for(int S=0;S<1<<pr.size();S++)
        {
            int cnt=0,pd=1;
            for(int j=0;j<pr.size();j++)
            {
                if(S>>j&1)
                {
                    cnt++;
                    pd*=pr[j];
                }
            }
            int all=zan/pd;
            ll val=(ll) (m+1)*(ll) all-(ll) pd*(ll) all*(ll) (all+1)/2;
            val%=p;
            if(cnt%2==0) sum+=val;
            else sum-=val;
            if(sum<0) sum+=p;
            sum%=p;
        }
        ret=(ret+(ll) (n-i+1)*sum*2LL%p)%p;
    }
    return ret;
}
int main()
{
    int l,r;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&l,&r,&p);
    ll ret=cnt((ll) r*(ll) r)-cnt((ll) (l-1)*(ll) (l+1));
    if(ret<0) ret+=p;
    printf("%llld\n",ret);
    return 0;
}