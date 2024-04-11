#include<bits/stdc++.h>
#define ll long long 
ll rd() {
    ll x=0,f=1;
    char ch=getchar();
    for(;ch!=EOF&&ch!='-'&&!(ch>='0'&&ch<='9');ch=getchar());
    if (ch=='-') ch=getchar(),f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
int n,k;
int b[100005],a[100005];
std::vector<int> vt[100005];
int main() {
    // freopen("test.in","r",stdin);
    int T=rd();
    while(T--) {
        n=rd();
        for(int i=1;i<=n;i++) {
            b[i]=rd();
        }
        int R=n+1,L=0;
        for(int i=1;i<=n;i++) {
            if (b[i]>=i) {
                L=i;
            }
        }
        k=L;
        printf("%d\n",k);
        for(int i=0;i<=n+1;i++) vt[i].clear();
        for(int i=1;i<=n;i++) {
            vt[b[i]].push_back(i);
        }
        for(int now=vt[0].size()?0:n+1,cnt=0;cnt<n;) {
            std::vector<int> tmp;
            int x=0;
            for(auto i:vt[now]) {
                cnt++;
                tmp.push_back(i);
                if (vt[i].size()) x=i;
            }
            now=x;
            for(auto i:tmp) if (i!=now) {
                printf("%d ",i);
            }
            if (now) printf("%d ",now);
        }
        putchar('\n');
    }
}