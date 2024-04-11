#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second

namespace gao{
    int B=512, N=300001, tot=N/B;
    ll sumb[1010], sumpre[303000];
    ll cb[1010], cpre[303000];
    void add(int pos){
        for (int i=pos/B+1;i<=tot;++i)
            sumb[i]+=pos, cb[i]+=1;
        for (int i=pos;i/B==pos/B;++i){
            sumpre[i]+=pos, cpre[i]+=1;
        }
    }
    pll que(int pos){
        pos=min(pos,N);
        return (pll){sumb[pos/B]+sumpre[pos],cb[pos/B]+cpre[pos]};
    }
}

int n;
ll ans;
const int maxn=300000;

int main(){
    for (cin>>n;n--;){
        int x; scanf("%d",&x);
        {
            pll las={0ll,0ll};
            for (int i=0;i*x<=maxn;++i){
                pll now=gao::que((i+1)*x-1);
                ll sum=now.fi-las.fi, c=now.se-las.se; las=now;
                // if (sum||c){
                //     printf(" %d %lld %lld\n",i,c,sum);
                // }
                ans+=sum-c*x*i;
            }
        }
        // printf("(%lld) ",ans);
        {
            pll las={0ll,0ll};
            int i=1, sqr=sqrt(x)-3;
            for (;i<x;){
                int ne=i;
                if (i>=sqr) ne=x/(x/i);
                pll now=gao::que(ne);
                ll sum=now.fi-las.fi, c=now.se-las.se; las=now;
                // if (sum||c){
                //     printf("   %d-%d %lld %lld\n",i,ne,c,sum);
                // }
                ans+=x*c-sum*(x/i);
                i=ne+1;
            }
            ans+=(gao::que(maxn).se-gao::que(x).se)*x;
        }
        gao::add(x);
        printf("%lld ",ans);
        // puts("");
    }
    puts("");
}