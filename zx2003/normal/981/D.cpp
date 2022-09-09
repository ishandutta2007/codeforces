#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
int i,j,n,k,l;
ll f[N],a[N],ans,x;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=55;i>=0;--i){
		ans|=1ll<<i;
		memset(f,0,sizeof f);
		f[0]=1;
		for(j=0;j<n;++j){
			x=0;
			for(l=j+1;l<=n;++l){
				x+=a[l];
				if((x&ans)==ans)f[l]|=f[j]<<1;
			}
		}
		if(f[n]>>k&1);else ans^=1ll<<i;
	}
	cout<<ans<<endl;
	return 0;
}