#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e5+3;
const int M=998244353;
int _,n,a[maxn],A,B,cnt[maxn],px,py,ban,cc,ans[maxn],cnt2[maxn];
mt19937_64 gen(19260817);
bool vis[maxn];
bool cmp(pi u,pi v){
    if (u.F!=v.F) return u.F<v.F;
    if (cnt[a[u.S]]!=cnt[a[v.S]]) return cnt[a[u.S]]>cnt[a[v.S]];
    return a[u.S]<a[v.S];
}
void solve(){
    scanf("%d%d%d",&n,&A,&B);
    //n=5; A=gen()%(n+1); B=gen()%(n+1);if(A>B)swap(A,B);
    for (int i=1;i<=n+1;i++) vis[i]=1,cnt[i]=0,cnt2[i]=0;
    vector <pi> b; b.clear();
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++; ans[i]=-1;
        b.pb((pi){cnt[a[i]],i});
    }
    //for (int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<endl;
    //cout<<A<<' '<<B<<endl;
    px=0; py=0; cc=0;
    for (int i=1;i<=n+1;i++){
        if (cnt[i]==0) ban=i; else ++cc;
        if (cnt[i]>cnt[px]) py=px,px=i;
        else if (cnt[i]>cnt[py]) py=i;
    }
    if (cc==1){
        if (A!=B) puts("NO");
        else {
            puts("YES");
            for (int i=1;i<=A;i++) printf("%d ",a[i]);
            for (int i=1;i<=n-A;i++) printf("%d ",ban);puts("");
        }
        return;
    }
    if (2*(n-cnt[px])<B-A){puts("NO");return;}
    if (cc==2&&B==n&&(B-A)&1){puts("NO");return;}
    if (B==n&&A==n-1){puts("NO");return;}
    sort(b.begin(),b.end(),cmp);
    int dx=-1,dy=-1;
    for (int i=B;i<n;i++) {
        int d=a[b[i].S];
        if (dx==-1) dx=d; else if (d!=dx) dy=d;
        ans[b[i].S]=ban;
    }
    bool flag=0;
    if ((B-A)&1){
        int op;
        if (dy==-1) op=1; else op=b[B-1].S;
        for (int i=op;i<=n;i++) if (ans[i]==-1) {
            if (dy!=-1) {ans[i]=(a[i]==dx)?dy:dx;break;}
            else if (a[i]!=dx) {ans[i]=dx;break;}
        }
    }
    //for (int i=1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
    for (int i=1;i<=n+1;i++) cnt[i]=0;
    b.clear();
    for (int i=1;i<=n;i++) if (ans[i]==-1) {
        cnt[a[i]]++;
        b.pb((pi){cnt[a[i]],i});
    }
    sort(b.begin(),b.end());
    for (int i=b.size()-A;i<b.size();i++) ans[b[i].S]=a[b[i].S];
    vector <pi> c; c.clear();
    for (int i=1;i<=n;i++) if (ans[i]==-1) c.pb((pi){a[i],i});
    sort(c.begin(),c.end());
    int m=c.size(); //assert(m%2==0);
    for (int i=0;i<m;i++) ans[c[i].S]=a[c[(i+m/2)%m].S];
    for (int i=1;i<=n;i++) cnt2[ans[i]]++;
    int AA=A,BB=B;
    for (int i=1;i<=n;i++) A-=a[i]==ans[i];
    for (int i=1;i<=n+1;i++) B-=min(cnt[i],cnt2[i]);
    puts("YES");
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");

}
int main(){
    scanf("%d",&_);
    while (_--) solve();
    return 0;
}