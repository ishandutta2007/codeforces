// LUOGU_RID: 92711747
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=2010,MOD=998244353;

int n,tot,c[N],lim[N];
i64 f[2][N][N],ans;

template<typename T>
inline void add(T &a,T b){
    a+=b;
    if(a>=MOD) a-=MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) c[rdi()]++;
    sort(c+1,c+n+1,greater<int>());
    tot=find(c+1,c+n+1,0)-c-1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=tot;j++)
            lim[i]+=min(i,c[j]);

    f[0][0][n]=1;
    for(int i=0,nw=0;i<=n;i++,nw^=1){
        for(int s=0;s<=lim[i];s++){
            int up=(i?min(n/i,s):n);
            for(int lst=1;lst<=up;lst++){
                i64 &v=f[nw][s][lst];
                if(!v) continue;
                if(s==n) ans+=v;
                if(i==n) continue;
                for(int x=1;x<=lst&&s+x<=lim[i+1];x++)
                    add(f[nw^1][s+x][x],v);
                v=0;
            }
        }
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}