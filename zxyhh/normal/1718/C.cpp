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
#define maxn 200005
int T;
int n,q;
int a[maxn];
int G[maxn];
int p[maxn];
std::vector<ll> res[maxn];
bool vis[maxn];
std::multiset<ll> st;
int main() {
    T=rd();
    for(int i=2;i<=200000;i++) if (!vis[i]) {
        for(int j=i+i;j<=200000;j+=i) {
            vis[j]=1;
        }
    }
    while(T--) {
        n=rd(),q=rd();
        for(int i=1;i<=n;i++) {
            a[i]=rd();
        }
        int cnt=0;
        st.clear();
        for(int i=2;i<=n;i++) {
            if (n%i==0&&!vis[i]) {
                // printf("%d\n",i);
                ++cnt;
                res[cnt].clear();
                res[cnt].resize(n/i);
            }
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=cnt;j++) {
                res[j][(i-1)%res[j].size()]+=a[i];
            }
        }
        for(int i=1;i<=cnt;i++) {
            for(auto j:res[i]) {
                st.insert(j*res[i].size());
            }
        }
        printf("%lld\n",*st.rbegin());
        for(int i=1;i<=q;i++) {
            int p=rd(),x=rd();
            for(int j=1;j<=cnt;j++) {
                int pos=(p-1)%res[j].size();
                st.erase(st.find(res[j][pos]*res[j].size()));
                res[j][pos]-=a[p];
                res[j][pos]+=x;
                st.insert(res[j][pos]*res[j].size());
            }
            a[p]=x;
            printf("%lld\n",*st.rbegin());
        }
    }
}