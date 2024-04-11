#include<bits/stdc++.h>
#define maxn 1005000

using namespace std;
int a[maxn],dp[maxn],b[maxn];
int l,r,mid,n,d,k;

void add(int x){
    while (x<maxn){
        b[x]++;
        x+=x&(-x);
    }
}

int qry(int x){
    int rt=0;
    while (x){
        rt+=b[x];
        x-=x&(-x);
    }
    return rt;
}

int main()
{
    cin >> n >> k >> d;
    for (int i=2;i<=n+1;i++) scanf("%d",&a[i]); sort(a+2,a+n+2);
    a[1]=-d-1; add(1);
    for (int i=k+1;i<=n+1;i++){
        l=1;r=i;
        while (r-l>1){
            mid=(l+r)/2;
            if (a[i]-a[mid]<=d) r=mid; else l=mid;
        }
        if (i-k>=l){
            if (qry(i-k)-qry(l-1)>0) dp[i]=1,add(i);
        }
    }
    if (dp[n+1]) puts("YES"); else puts("NO");
    return 0;
}