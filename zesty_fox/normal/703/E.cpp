#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

template<typename T>
inline T gcd(T x,T y){return !x?y:gcd(y%x,x);}

const int N=1010,M=7010,INF=0x3f3f3f3f;
int n;
ll a[N],b[N],k;

struct Node{
    int cnt,fr;
    bool use;
    ll sum;
    bool operator < (const Node &rhs)const{
        return cnt!=rhs.cnt?cnt<rhs.cnt:sum<rhs.sum;
    }
};

vector<ll> d;
int cnt;
unordered_map<ll,int> id;
Node f[N][M];

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),k=rdll();
    for(int i=1;i<=n;i++) a[i]=rdll(),b[i]=gcd(a[i],k);

    if(k==1){
        int tmp=min_element(a+1,a+n+1)-a;
        printf("1\n%d\n",tmp);
        return 0;
    }

    for(ll i=1;i<=k/i;i++){
        if(k%i==0){
            d.pb(i);
            if(i!=k/i) d.pb(k/i);
        }
    }
    sort(d.begin(),d.end());cnt=d.size();
    for(int i=cnt-1;i>=0;i--) id[d[i]]=i;

    for(int i=0;i<=n;i++){
        for(int j=0;j<cnt;j++) f[i][j]={INF,0,0,0};
    }
    f[0][0]={0,0,0,0};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<cnt;j++){
            if(f[i][j].cnt==INF) continue;
            f[i+1][j]=min(f[i+1][j],{f[i][j].cnt,j,0,f[i][j].sum});

            int nxt=id[gcd((__int128)d[j]*b[i+1],(__int128)k)];
            f[i+1][nxt]=min(f[i+1][nxt],{f[i][j].cnt+1,j,1,f[i][j].sum+a[i+1]});
        }
    }
    if(f[n][cnt-1].cnt==INF) puts("-1");
    else{
        ll nowx=n,nowy=cnt-1;vi res;
        while(nowx){
            if(f[nowx][nowy].use) res.pb(nowx);
            nowy=f[nowx][nowy].fr,nowx--;
        }
        printf("%lu\n",res.size());
        for(auto x:res) printf("%d ",x);
        puts("");
    }
    return 0;
}