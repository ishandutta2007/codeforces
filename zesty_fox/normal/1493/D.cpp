#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
 
#define rdi read<int>
#define rdl read<ll>
 
const int N=200010,MOD=1e9+7,INF=0x3f3f3f3f,P=18010;
int n,q,a[N];
 
int p[N],cp,vis[N];
void pr(int lim){
    vis[0]=vis[1]=1;
    for(int i=2;i<=lim;i++){
        if(!vis[i]){
            p[++cp]=i;
            for(int j=i;j<=lim/i;j++) vis[i*j]=1;
        }
    }
}
 
ll qpow(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}
 
multiset<int> s[P];
map<int,int> fac[N],tmp;
ll ans=1;
ll gcd(ll x,ll y){return !x?y:gcd(y%x,x);}
int main(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++){
        a[i]=rdi();
        if(i==1) ans=a[i];
        else ans=gcd(ans,a[i]);
    }
    pr(N-10);
    for(int i=1;i<=n;i++){
        int lim=sqrt(a[i]),x=a[i];
        for(int j=1;p[j]<=lim&&j<=cp;j++){
            if(x%p[j]==0){
                int cnt=0;
                while(x%p[j]==0) x/=p[j],cnt++;
                fac[i][j]=cnt;
            }
            lim=sqrt(x);
        }
        if(x>1){
            int tmp=lower_bound(p+1,p+cp+1,x)-p;
            fac[i][tmp]++;
        }
        for(auto x:fac[i]) s[x.first].insert(x.second);
    }
    while(q--){
        int id=rdi(),val=rdi();
        int lim=sqrt(val),x=val;tmp.clear();
        for(int j=1;p[j]<=lim&&j<=cp;j++){
            if(x%p[j]==0){
                int cnt=0;
                while(x%p[j]==0) x/=p[j],cnt++;
                tmp[j]=cnt;
            }
            lim=sqrt(x);
        }
        if(x>1){
            int posss=lower_bound(p+1,p+cp+1,x)-p;
            tmp[posss]++;
        }
        for(auto x:tmp){
            int x1=x.first,x2=x.second;
            int pre=fac[id][x1],post=pre+x2;
            fac[id][x1]+=x2;
            int minx1=s[x1].size()<n?0:(*s[x1].begin());
            if(pre) s[x1].erase(s[x1].find(pre));
            s[x1].insert(post);
            int minx2=s[x1].size()<n?0:(*s[x1].begin());
            ans=ans*qpow(p[x1],minx2-minx1)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}