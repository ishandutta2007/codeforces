#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans,sum[1000010];
int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^i;
    for(int i=2;i<=n;i++){
        int cnt=n/i,y=n%i;
        ans^=(cnt&1?(sum[i-1]^sum[y]):sum[y]);
    }
    for(int i=1;i<=n;i++) ans^=read();
    cout<<ans<<endl;
    return 0;
}