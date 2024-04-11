#include<bits/stdc++.h>
#define maxn 202020
using namespace std;
typedef long long ll;
ll dp[maxn],ans,n,a[10][maxn],m;
struct node{
    int p[10],val;
}b[maxn];
bool cmp(node u,node v){
    for (int i=0;i<n;i++) if (u.p[i]!=v.p[i]) return u.p[i]<v.p[i];
    return false;
}
int main(){
    cin >> n >> m;
    for (int i=0;i<m;i++)
    for (int j=0;j<n;j++) {
        scanf("%I64d",&a[i][j]);
        b[a[i][j]].p[i]=j;
    }
    for (int i=1;i<=n;i++) b[i].val=i;
    sort(b+1,b+n+1,cmp);
    for (int i=1;i<=n;i++) dp[i]=1;
    for (int i=1;i<=n;i++) {
        bool flag=true;
        int p=0; ans+=dp[b[i].val];
        for (int j=0;j<m;j++) {
            int x=a[j][b[i].p[j]+1];
            if (!x) flag=false;
            else if (!p) p=x; else if (x!=p) flag=false;
        }
        if (flag) dp[p]+=dp[b[i].val];
    }
    cout << ans << endl;
}