#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using db=double;
using vi=vector<int>;
using pii=pair<int,int>;

template <typename T>
T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N=100010;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

int n,a[N];
i64 m,sum[N];

inline int lg2(int x) {return !x?-1:__lg(x);}

struct ST{
    i64 mi[20][N],mx[20][N];
    void init(i64 *a,int n){
        for(int i=0;i<=n;i++) mi[0][i]=mx[0][i]=a[i];
        for(int j=1;j<=lg2(n+1);j++)
            for(int i=0;i<=n-(1<<j)+1;i++)
                mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]),
                mx[j][i]=max(mx[j-1][i],mx[j-1][i+(1<<(j-1))]);
    }
    i64 qmax(int l,int r){
        int k=lg2(r-l+1);
        return max(mx[k][l],mx[k][r-(1<<k)+1]);
    }
    i64 qmin(int l,int r){
        int k=lg2(r-l+1);
        return min(mi[k][l],mi[k][r-(1<<k)+1]);
    }
}st;

struct BIT{
    i64 sum[N*2],n;
    void init(int _n){n=_n;fill(sum,sum+n+1,0);}
    void add(int x,i64 v) {for(;x<=n;x+=(x&(-x))) sum[x]+=v;}
    i64 query(int x) {i64 ret=0;for(;x;x-=(x&(-x))) ret+=sum[x];return ret;}
}t1,t2;

i64 seq[N],tot;
int rk[N];

void init(){
    n=rdi(),m=rdi64();
    for(int i=1;i<=n;i++) a[i]=rdi(),sum[i]=sum[i-1]+a[i];
    st.init(sum,n);

    copy(sum,sum+n+1,seq+1);
    sort(seq+1,seq+n+2),tot=unique(seq+1,seq+n+2)-seq-1;
    for(int i=0;i<=n;i++) rk[i]=lower_bound(seq+1,seq+tot+1,sum[i])-seq;
}

int vis[N];
pair<i64,i64> calc(i64 mid){
    t1.init(tot),t2.init(tot);
    i64 s=0,c=0;

    t2.add(rk[0],1);
    for(int i=1;i<=n;i++){
        int mx=upper_bound(seq+1,seq+tot+1,sum[i]-mid)-seq-1;
        int cnt=t2.query(mx);
        s+=cnt*sum[i]-t1.query(mx),c+=cnt;
        t1.add(rk[i],sum[i]),t2.add(rk[i],1);
        
        vis[i]=(st.qmax(i,n)-st.qmin(0,i-1)>=mid);
    }

    vis[n+1]=1;
    for(int i=1,L=1,R=0;;){
        if(vis[i]){
            int j=i-1;
            while(j+1<=n&&vis[j+1]) ++j;
            if(!(i==1&&R==0||i==n+1&&R==n)){
                s+=st.qmax(i-1,j)-st.qmin(L-1,R);
                if(mid<=0) c+=i-R-1;
                else ++c;
            }
            if(i>n) break;
            L=i,R=j,i=j+1;
        }
        else ++i;
    }
    return {s-c*mid,c};
}

void solve(){
    i64 l=-1e10,r=1e10;
    while(l<r){
        i64 mid=(l+r+1)>>1;
        auto res=calc(mid);
        if(res.se>=m) l=mid;
        else r=mid-1;
    }
    auto res=calc(l);
    i64 ans=res.fi+l*m;
    cout<<ans<<endl;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init();solve();
    return 0;
}