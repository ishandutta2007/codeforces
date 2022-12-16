#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

const int N=100010;
int n,m,a[N],cnt1[N],cnt[N][510],tot,num[N];
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]>n) continue;
        else cnt1[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt1[i]<i) continue;
        else{
            num[++tot]=i;
            for(int j=1;j<=n;j++) cnt[j][tot]=cnt[j-1][tot]+(a[j]==i);
        }
    }
    while(m--){
        int l=read(),r=read(),ans=0;
        for(int i=1;i<=tot;i++){
            if(cnt[r][i]-cnt[l-1][i]==num[i]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}