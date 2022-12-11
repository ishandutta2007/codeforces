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
#define maxn 15
int a[maxn];

void solve() {
    n=rd();
    for(int i=1;i<=n;i++) {
        a[i]=rd();
    }
    if (a[1]==1) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
}
int main() {
    int T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}