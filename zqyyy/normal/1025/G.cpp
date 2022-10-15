#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=507,mod=1e9+7;
int n,cnt[N],pw[N];
int main(){
    n=read(),pw[0]=1;
    for(int i=1;i<=n;i++){
	int x=read();if(~x)cnt[x]++;
	pw[i]=(pw[i-1]<<1)%mod;
    }
    int ans=pw[n-1]-1;
    for(int i=1;i<=n;i++)ans=(ans+mod+1-pw[cnt[i]])%mod;
    return cout<<ans,0;
}