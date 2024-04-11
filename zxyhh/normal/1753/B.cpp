#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void solve() ;
int main() {
    // int T;
    // T=rd();
    // for(int i=1;i<=T;i++) {
    //     solve();
    // }
    solve();
}
#define maxn 500005
int a[maxn],n,x;
int cnt[maxn];
void solve() {
    n=rd();x=rd();
    for(int i=1;i<=n;i++) {
        a[i]=rd();
        cnt[a[i]]++;
    }
    for(int i=1;i<x;i++) {
        if (cnt[i]) {
            if (cnt[i]%(i+1)!=0) {
                printf("No\n");
                return ;
            }
            cnt[i+1]+=cnt[i]/(i+1);
            cnt[i]=0;
        }
    }
    printf("Yes\n");
}