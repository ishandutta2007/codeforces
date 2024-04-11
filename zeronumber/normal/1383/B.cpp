#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,_,a[maxn];
void solve(){
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum^=a[i];
    }
    if (!sum){puts("DRAW");return;}
    int r=-1;
    for (int i=0;i<30;i++) if (sum&(1<<i)) r=i;
    int cnt=0;
    for (int i=1;i<=n;i++) if (a[i]&(1<<r)) ++cnt;
    if (n%2==0) puts("WIN");
    else if (cnt%4==1) puts("WIN");
    else puts("LOSE");
}
int main(){
    scanf("%d",&_);
    while (_--) solve();
}