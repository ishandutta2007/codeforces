#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e6+3;
const int M=1000000007;
typedef vector<int> vi;
typedef vector<vi> vii;
int n,a[5555],id[5555],x[maxn],y[maxn],cc,po[4100][4100],q,h[16][256],cnt[16];
int f[16][256][256];
int N=4096;
int S=256;
int _merge(int u,int v){
    if (u==0) return v;
    if (v==0) return u;
    ++cc; x[cc]=u; y[cc]=v;
    return cc;
}
vii solve(vi &b,int l,int r){
    //cout<<l<<' '<<r<<' '<<b.size()<<endl;
    int m=b.size();
    if (m==0){
        vii ret; ret.clear();
        return ret;
    }
    if (m==1){
        vii ret;
        ret.resize(1);
        ret[0].resize(1);
        ret[0][0]=id[l];
        return ret;
    }
    int mid=(l+r)>>1;
    vi p,q; p.clear(); q.clear();
    for (auto x:b) if (a[x]<mid) p.pb(x); else q.pb(x);
    vii A=solve(p,l,mid);
    vii B=solve(q,mid,r);
    vii ret; ret.resize(m);
    int pa=0,pb=0;
    for (int i=0;i<m;i++) {
        ret[i].resize(m);
        for (int j=0;j<m;j++) ret[i][j]=0;
        int qa=pa-1,qb=pb-1;
        for (int j=i;j<m;j++) {
            if (a[b[j]]<mid) ++qa; else ++qb;
            int vx=(pa>qa)?0:A[pa][qa];
            int vy=(pb>qb)?0:B[pb][qb];
            ret[i][j]=_merge(vx,vy);
        }
        if (a[b[i]]<mid) ++pa; else ++pb;
    }
    return ret;
}
void build(int x,int l,int r){
    int no=0;
    for (int i=0;i<N;i++) if (a[i]>=l&&a[i]<r) h[x][no++]=i;
    vector <int> tmp; tmp.clear();
    for (int i=0;i<no;i++) tmp.pb(h[x][i]);
    vii res=solve(tmp,l,r); cnt[x]=no;
    for (int i=0;i<no;i++)
        for (int j=0;j<no;j++)
            f[x][i][j]=res[i][j];
    /*
    for (int i=0;i<S;i++){
        for (int j=i;j<S;j++)cout<<f[x][i][j]<<' ';cout<<endl;
    }
    */
}
int main(){
    scanf("%d%d",&n,&q); cc=n;
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        a[i]--;
    }
    for (int i=n;i<N;i++) a[i]=-1;
    for (int i=0;i<n;i++) id[a[i]]=i+1;
    for (int i=0;i<N/S;i++) build(i,i*S,i*S+S);
    vector <int> ans;
    for (int i=0;i<q;i++){
        int l,r; scanf("%d%d",&l,&r); l--; r--;
        int now=0;
        for (int j=0;j<N/S;j++){
            int p=lower_bound(h[j],h[j]+cnt[j],l)-h[j];
            int q=lower_bound(h[j],h[j]+cnt[j],r+1)-h[j]-1;
            int val=p>q?0:f[j][p][q];
            now=_merge(now,val);
        }
        ans.pb(now);
    }
    printf("%d\n",cc);
    for (int i=n+1;i<=cc;i++) printf("%d %d\n",x[i],y[i]);
    for (auto x:ans) printf("%d ",x); puts("");
    return 0;
}