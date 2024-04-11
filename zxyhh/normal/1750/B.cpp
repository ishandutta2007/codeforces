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
char a[maxn];
void solve() {
    n=rd();
    ll ans=0;
    scanf("%s",a+1);
    int tot0=0,tot1=0;
    for(int i=1,now=0;i<=n;i++) {
        if (a[i]==a[i-1]) now++;
        else now=1;
        if (a[i]=='1') tot1++;
        else tot0++;
        ans=std::max(ans,std::max(1ll*now*now,1ll*tot0*tot1));
    }
    printf("%lld\n",ans);
}
int main() {
    int T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}