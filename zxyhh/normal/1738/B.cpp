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
int a[100005],s[100005];
int main() {
    int T=rd();
    while(T--) {
        n=rd();k=rd();
        for(int i=n-k+1;i<=n;i++) {
            s[i]=rd();
        }
        if (k==1) {
            printf("Yes\n");
            continue;
        }
        for(int i=n-k+2;i<=n;i++) a[i]=s[i]-s[i-1];
        bool flag=1;
        for(int i=n-k+3;i<=n;i++) {
            flag&=(a[i]>=a[i-1]);
        }
        if (1ll*a[n-k+2]*(n-k+1)>=s[n-k+1]&&flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}