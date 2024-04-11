#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int a[maxn],b[maxn],o[maxn],p[maxn],ans,n,td[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if (a[i]) o[b[i]]=0,p[b[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
        if (b[i]) o[b[i]]=1,p[b[i]]=i;
    }
    for (int i=1;i<=n;i++) if (!o[i]) td[i]=1; else td[i]=p[i]+1;
    for (int i=1;i<=n;i++) ans=max(ans,td[i]+n-i);
    if (o[1]){
        bool flag=true;
        for (int i=p[1]+1;i<=n;i++) if (i-p[1]!=b[i]-1) flag=false;
        int x=b[n];
        for (int i=x+1;i<=n;i++) if (td[i]>i-x) flag=false;
        if (flag) ans=min(ans,n-x);
    }
    cout << ans << endl;
    return 0;
}