#include<bits/stdc++.h>
using namespace std;
const int N=3005;
typedef long long ll;
int p,c,i,j,k,n,m;
vector<int>a[N];
ll ans;
int b[N],xb;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);ans=1ll<<60;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		cin>>p>>c;a[p].push_back(c);
	}
	for(i=1;i<=m;++i)sort(a[i].begin(),a[i].end());
	for(i=max((unsigned int)1,a[1].size());i<=n;++i){
		ll su=0;xb=0;int z=i-a[1].size();
		for(j=2;j<=m;++j){
			for(k=0;a[j].size()-k>=i;++k)su+=a[j][k],--z;
			for(;k<a[j].size();++k)b[++xb]=a[j][k];
		}
		sort(b+1,b+xb+1);
		for(j=1;j<=z && j<=xb;++j)su+=b[j];
		if(su<ans)ans=su;
	}
	cout<<ans<<'\n';
	return 0;
}