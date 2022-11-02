#include<bits/stdc++.h>
#define maxn 334500
using namespace std;
typedef long long ll;
struct node{
    ll a,b,p;
}c[maxn];
bool cmp(node &u,node &v){
    return u.a-u.b<v.a-v.b;
}
ll a[maxn],b[maxn],ans[maxn],n,u,v,m,s[maxn],t[maxn],res;
int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        c[i].p=i;
        scanf("%I64d%I64d",&c[i].a,&c[i].b);
        a[i]=c[i].a; b[i]=c[i].b;
    }
    sort(c+1,c+n+1,cmp);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+c[i].a;
    for (int i=n;i>=1;i--) t[i]=t[i+1]+c[i].b;
    for (int i=1;i<=n;i++) ans[c[i].p]=s[i-1]+t[i+1]+c[i].a*(n-i)+c[i].b*(i-1);
    for (int i=1;i<=m;i++){
        scanf("%I64d%I64d",&u,&v);
        res=min(a[u]+b[v],a[v]+b[u]);
        ans[u]-=res; ans[v]-=res;
    }
    for (int i=1;i<=n;i++) printf("%I64d ",ans[i]); puts("");
    return 0;
}