#include<bits/stdc++.h>
#define maxh 20
#define maxn 300050
using namespace std;

int n;
int pos[maxn],nxt[maxn];

int Log2[maxn]={-1};
int ST[maxh][maxn],* const a=ST[0];

int Max(int l,int r)    {
    int t=Log2[r-l+1];
    return max(ST[t][l],ST[t][r-(1<<t)+1]);
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",a+i);
    
    for (int i=1;i<=n;++i)  Log2[i]=Log2[i>>1]+1;
    for (int j=1;j<=Log2[n];++j)
        for (int i=1;i+(1<<j)-1<=n;++i)
            ST[j][i]=max(ST[j-1][i],ST[j-1][i+(1<<j-1)]);

    nxt[n+1]=n+1;
    for (int i=n;i;--i)  {
        nxt[i]=nxt[i+1];
        if (pos[a[i]])
            nxt[i]=min(nxt[i],pos[a[i]]);
        pos[a[i]]=i;
    }

    int ans=0;
    for (int i=1;i<=n;++i)  {
        for (int j=i;j<nxt[i];) {
            int mx=Max(i,j);
            if (mx==j-i+1)
                ++ans,++j;
            else
                j=mx+i-1;
        }
    }

    printf("%d\n",ans);
    return 0;
}