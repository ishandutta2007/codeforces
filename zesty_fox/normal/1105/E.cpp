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

const int N=100010,M=42;

int n,m,cnt,cname,ans;
map<string,int> name;

bitset<N> vis[M];

ll e[M];
int f[1<<(M/2)];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int op;string s;
        cin>>op;
        if(op==1) ++cnt;
        else{
            cin>>s;
            if(name.find(s)==name.end()) name[s]=++cname;
            vis[name[s]][cnt]=1;
        }
    }

    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            if((vis[i]&vis[j]).any()) e[i]|=(1ll<<(j-1)),e[j]|=(1ll<<(i-1));

    int mid=m/2;
    for(int i=0;i<(1<<mid);i++){
        bool flg=1;
        for(int j=1;j<=mid;j++)
            if((i>>(j-1)&1)&&(i&e[j])) {flg=0;break;}
        if(!flg) continue;
        ll tmp=i;
        for(int j=1;j<=mid;j++)
            if((i>>(j-1)&1)) tmp|=e[j];
        tmp>>=mid;
        f[tmp]=max(f[tmp],__builtin_popcount(i));
    }
    for(int j=1;j<=mid;j++)
        for(int i=0;i<(1<<mid);i++)
            if(i>>(j-1)&1) f[i]=max(f[i],f[i^(1<<(j-1))]);
    for(int i=0;i<(1<<(m-mid));i++){
        bool flg=1;
        for(int j=mid+1;j<=m;j++)
            if((i>>(j-mid-1)&1)&&(i&(e[j]>>mid))) {flg=0;break;}
        if(!flg) continue;
        ans=max(ans,__builtin_popcount(i)+f[((1<<(m-mid))-1)^i]);
    }
    cout<<ans<<endl;
    return 0;
}