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
int n;
int a[105];
int cnt[2];
int f[105][105][105];
bool dfs(int u,int A,int B) {
    if (f[u][A][B]!=-1) return f[u][A][B];
    if ((cnt[0]-A+cnt[1]-B)%2==0) {
        bool res=0;
        if (A) {
            res|=dfs(u+1,A-1,B);
        }
        if (B) {
            res|=dfs(u,A,B-1);
        }
        return f[u][A][B]=res;
    }
    else {
        bool res=1;
        if (A) {
            res&=dfs(u,A-1,B);
        }
        if (B) {
            res&=dfs(u,A,B-1);
        }
        return f[u][A][B]=res;
    }
}
int main() {
    int T=rd();
    while(T--) {
        n=rd();
        cnt[0]=cnt[1]=0;
        for(int i=1;i<=n;i++) {
            int x=abs(rd())%2;
            cnt[x]++;
        }
        memset(f,-1,sizeof f);
        for(int i=0;i<=cnt[1];i++) {
            if (i%2==0) f[i][0][0]=1;
            else f[i][0][0]=0;
        }
        if (dfs(0,cnt[1],cnt[0])) {
            printf("Alice\n");
        }
        else {
            printf("Bob\n");
        }
    }
}