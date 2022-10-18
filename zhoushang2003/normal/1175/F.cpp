#include<bits/stdc++.h>
using namespace std;
#define int uint64_t
mt19937_64 R(time(0));
const int N=2e6;
int n,f[N],g[N],a[N],s[N],A,u;
void S(){
	u=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^f[a[i]],u=max(u,a[i]);
		if(a[i]==1)
			u=1;
		else if(i>=u&&(s[i]^s[i-u])==g[u])
			A++;
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],A+=a[i]==1,f[i]=R(),g[i]=g[i-1]^f[i];
	S(),reverse(a+1,a+n+1),S();
	cout<<A;
}