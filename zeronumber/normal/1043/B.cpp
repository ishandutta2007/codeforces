#include<bits/stdc++.h>
#define maxn 1050

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],n,cnt,ans[maxn];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
    for (int i=1;i<=n;i++){
        bool flag=true;
        for (int j=1;j+i<=n;j++) if (b[j]!=b[j+i]) flag=false;
        if (flag) ans[cnt++]=i;
    }
    printf("%I64d\n",cnt);
    for (int i=0;i<cnt;i++) printf("%I64d ",ans[i]); puts("");
    return 0;
}