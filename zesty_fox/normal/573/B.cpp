#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int n,h[N],ans,a[N],b[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    for(int i=1;i<=n;i++) a[i]=min(a[i-1]+1,h[i]);
    for(int i=n;i>=1;i--) b[i]=min(b[i+1]+1,h[i]);
    for(int i=1;i<=n;i++) ans=max(ans,min(a[i],b[i]));
    cout<<ans<<endl;
    return 0;
}