#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
int n,m;
#define maxn 200005
int a[maxn];
int f[maxn];
std::vector<int> vt;
int N;
int ans=0;
void dfs(int k,int tot,int S) {
    if (k==vt.size()) {
        if (tot&1) ans-=N/S;
        else ans+=N/S;
        return ;
    }
    dfs(k+1,tot,S);
    dfs(k+1,tot+1,S*vt[k]);
}
void solve() {
    n=rd();m=rd();
    for(int i=1;i<=n;i++) {
        a[i]=rd();
    }
    f[1]=1;
    for(int i=2;i<=n;i++) {
        if (a[i-1]%a[i]!=0) {
            printf("0\n");
            return ;
        }
        int t=a[i-1]/a[i];
        N=m/a[i];
        vt.clear();
        int st=sqrt(t);
        for(int i=2;i<=st;i++) {
            if (t%i==0) {
                vt.push_back(i);
                while(t%i==0) t/=i;
            }
        }
        if (t>1) vt.push_back(t);
        // printf("%d\n",N);
        // printf("%d\n",vt.size());
        // for(auto j:vt) printf("%d ",j);
        // putchar('\n');

        ans=0;
        // printf("%d\n",vt[0]);
        dfs(0,0,1);
        // printf("%d\n",ans);
        f[i]=1ll*f[i-1]*ans%998244353;
        // printf("%d %d\n",f[i],N);    
        // if (a[i]==1) {
        //     printf("%d\n",f[i]);
        //     return ;
        // }
    }
    printf("%d\n",f[n]);
}
int main() {
    int T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}