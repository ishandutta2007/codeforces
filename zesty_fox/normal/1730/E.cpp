#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=5e5+10,M=1e6+10;

vi fac[M];
void init(int lim){
    for(int i=1;i<=lim;i++)
        for(int j=i;j<=lim;j+=i)
            fac[j].pb(i);
}

inline int lg2(int x) {return !x?-1:__lg(x);}

struct ST{
    int mi[21][N],mx[21][N];
    void init(int *a,int n){
        for(int i=1;i<=n;i++)
            mi[0][i]=mx[0][i]=a[i];
        for(int j=1;j<=lg2(n);j++){
            for(int i=1;i<=n-(1<<j)+1;i++){
                mi[j][i]=min(mi[j-1][i],mi[j-1][i+(1<<(j-1))]);
                mx[j][i]=max(mx[j-1][i],mx[j-1][i+(1<<(j-1))]);
            }
        }
    }
    int qmax(int l,int r){
        int k=lg2(r-l+1);
        return max(mx[k][l],mx[k][r-(1<<k)+1]);
    }
    int qmin(int l,int r){
        int k=lg2(r-l+1);
        return min(mi[k][l],mi[k][r-(1<<k)+1]);
    }
}st;

int n,a[N];
int pgt[N],ngt[N],plt[N],nlt[N];
vi pos[M];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),pos[a[i]].pb(i);
    //st.init(a,n);

    static int st[N];int tp=0;
    for(int i=1;i<=n;i++){
        while(tp&&a[st[tp]]<=a[i]) tp--;
        pgt[i]=st[tp],st[++tp]=i;
    }
    tp=0;
    for(int i=1;i<=n;i++){
        while(tp&&a[st[tp]]>=a[i]) tp--;
        plt[i]=st[tp],st[++tp]=i;
    }
    tp=0;
    for(int i=n;i>=1;i--){
        while(tp&&a[st[tp]]<a[i]) tp--;
        ngt[i]=(tp?st[tp]:n+1),st[++tp]=i;
    }
    tp=0;
    for(int i=n;i>=1;i--){
        while(tp&&a[st[tp]]>=a[i]) tp--;
        nlt[i]=(tp?st[tp]:n+1),st[++tp]=i;
    }

    i64 ans=0;
    for(int i=1;i<=n;i++){
        int mx=a[i];
        for(auto mi:fac[mx]){
            if(pos[mi].empty()) continue;
            int L,R,cur,l,r;

            l=0,r=pos[mi].size()-1;
            while(l<r){
                int mid=(l+r+1)/2,cur=pos[mi][mid];
                if(cur<ngt[i]&&plt[cur]<i) l=mid;
                else r=mid-1;
            }
            cur=pos[mi][l];
            if(cur>=ngt[i]||plt[cur]>=i) R=i;
            else R=min(nlt[cur]-1,ngt[i]-1);

            l=0,r=pos[mi].size()-1;
            while(l<r){
                int mid=(l+r)/2,cur=pos[mi][mid];
                if(cur>pgt[i]&&nlt[cur]>i) r=mid;
                else l=mid+1;
            }
            cur=pos[mi][r];
            if(cur<=pgt[i]||nlt[cur]<=i) L=i;
            else L=max(plt[cur]+1,pgt[i]+1);

            auto it=lower_bound(pos[mi].begin(),pos[mi].end(),i);
            int nx=(it==pos[mi].end()?n:*it-1);
            int pr=(it==pos[mi].begin()?1:(it==pos[mi].end()?*prev(it)+1:(*it==i?i+1:*prev(it)+1)));
            nx=min(nx,R),pr=max(pr,L);

            ans+=(i64)(R-i+1)*(i-L+1)-(i64)(nx-i+1)*(i-pr+1);
        }
    }
    cout<<ans<<'\n';

    for(int i=1;i<=n;i++) pos[a[i]].clear();
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    init(M-10);
    int T=rdi();
    while(T--) solve();
    return 0;
}