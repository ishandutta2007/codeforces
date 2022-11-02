#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e5+3;
const int M=998244353;
bitset <4005> f;
int n,a[4005],_;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        f.reset(); f[0]=1;
        for (int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        int mx=a[1],tot=1;
        for (int i=2;i<=n*2;i++){
            if (mx>a[i]) tot++;
            else mx=a[i],f|=f<<tot,tot=1;
        }
        f|=f<<tot;
        if (f[n]) puts("YES"); else puts("NO");
    }
    return 0;
}