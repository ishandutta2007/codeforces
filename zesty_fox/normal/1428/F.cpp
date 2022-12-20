#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1000010;
ll ans,sum,n,f[N],now;
char s[N];
int main(){
    scanf("%lld%s",&n,s+1);
    for(int i=1;i<=n;i++) f[i]=n+1;
    for(int i=n;i>=1;i--){
        if(s[i]>'0') now++,sum+=f[now]-i;
        else for(;now;now--) f[now]=i+now;
        ans+=sum;
    }
    cout<<ans<<endl;
    return 0;
}