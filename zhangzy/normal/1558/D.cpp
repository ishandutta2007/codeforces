#include<bits/stdc++.h>
using namespace std;

namespace trp{
    #define o 202000
    #define ll long long
    int ch[o][2]={0}, sz[o], key[o], cnt=0, rt=0;
    int val[o], laz[o];

    void init(){
        for (int i=0;i<=cnt;++i){
            ch[i][0]=ch[i][1]=0;
            sz[i]=key[i]=0;
            val[i]=laz[i]=0;
        }
        cnt=rt=0;
    }

    int U(int x){
        // haha;
    }
    void D(int x){
    	if (!laz[x]) return;
    	for (int i=0;i<2;++i){
            if (!ch[x][i]) continue;
    		val[ch[x][i]]+=laz[x];
    		laz[ch[x][i]]+=laz[x];
        }
        laz[x]=0;
    }
    int mg(int &pos,int x,int y){
        if (!x||!y) return pos=x+y;
        D(x), D(y);
        if (key[x]>key[y]) pos=x, mg(ch[x][1],ch[x][1],y);
        else pos=y, mg(ch[y][0],x,ch[y][0]);
        U(pos);
    }
    int cut(int x,int &t0,int &t1,int sb){
        if (!x) return t0=t1=0;
        D(x);
        if (val[x]<sb) t0=x, cut(ch[x][1], ch[x][1], t1, sb);
        else t1=x, cut(ch[x][0], t0, ch[x][0], sb);
        U(x);
    }
    int add(int v){
        // printf(" add : %d\n",v);
    	cnt++;
    	key[cnt]=rand()*100000+rand(); val[cnt]=v;
        int x, y;
        cut(rt,x,y,v);
        mg(rt,x,cnt); mg(rt,rt,y);
        // printf("  %d  %d %d %d\n",rt,ch[rt][0],ch[rt][1],val[rt]);
    }
    int mdf(int pos,int v){ // [pos, inf)
        // printf(" mdf : >=%d %d\n",pos,v);
        int x,y;
        cut(rt,x,y,pos);
        // printf("   %d %d %d\n",x,y,pos);
        if (y){
            val[y]+=v, laz[y]+=v;
        }
        mg(rt,x,y);
    }
    bool fin(int pos){
        // for (int i=1;i<=cnt;++i)
        //     printf("     %d  %d %d %d %d\n",i,ch[i][0],ch[i][1],val[i],laz[i]);
        int x,y,z,res;
        cut(rt,x,y,pos); cut(y,y,z,pos+1);
        res=!!y;
        mg(rt,x,y); mg(rt,rt,z);
        // printf(" fin : %d %d\n",pos,res);
        // printf("       %d %d %d\n",x,y,z);
        return res;
    }
}

#define ll long long
const int mod=998244353;
ll K(ll x,ll y=mod-2){
    ll t=1;
    for (;y;y>>=1,x=x*x%mod)
        if (y&1) t=t*x%mod;
    return t;
}

int n=4e5+7, m;
ll jc[404000], inv[404000];

ll C(int n,int m){
    return jc[n]*inv[m]%mod*inv[n-m]%mod;
}

void fuck(){
    scanf("%d%d",&n,&m);
    int ans=0;
    trp::init();
    for (int i=1;i<=m;++i){
        int x, y;
        scanf("%d%d",&x,&y);
        if (trp::fin(y-1)){
            trp::mdf(y-1,1);
        }else{
            ++ans;
            trp::mdf(y-1,1);
            trp::add(y);
        }
    }
    // cerr<<"ans : "<<ans<<endl;
    int c=n-ans;
    ll shit=C(n+c-1,c-1);
    printf("%lld\n",shit);
}

int main(){
    jc[0]=1; for (int i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
    inv[n]=K(jc[n]); for (int i=n;i>=1;--i) inv[i-1]=inv[i]*i%mod;
    int T;
    for (cin>>T;T--;){
        fuck();
    }
}