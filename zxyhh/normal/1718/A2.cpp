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
#define maxn 100005
int T,n;
int a[maxn];
int f[maxn];
int main() {
    T=rd();
    while(T--) {
        n=rd();
        for(int i=1;i<=n;i++) {
            a[i]=rd();
        }
        f[0]=0;
        int s=0;
        std::map<int,int> mp;
        mp[0]=0;
        for(int i=1;i<=n;i++) {
            s^=a[i];
            f[i]=f[i-1]+(a[i]!=0);
            if (mp.count(s)) 
                f[i]=std::min(f[i],f[mp[s]]+i-mp[s]-1);
            mp[s]=i;
        }
        printf("%d\n",f[n]);
    }
}