#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int x[2001];
int y[2001];
long long b[2001];
long long sb[2001];
int cnt[2001];
long long c[2001][2001];
long long k[2001];
bitset<2001> f[2001];
const long long base=1000000007;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>r;
	for(int i=1; i<=n; i++){
		cin>>x[i]>>y[i]>>b[i];
		sb[i]=(b[i]*b[i])%base;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(max(abs(x[i]-x[j]), abs(y[i]-y[j]))<=r){
		cnt[i]++;
		f[i][j]=1;
	}
	for(int i=0; i<=n; i++){
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>=base) c[i][j]-=base;
		}
	}
	long long ans=0;
	for(int i=1; i<=n; i++){
		//how many way to choose m from n that include at least
		k[i]=c[n][m]-c[n-cnt[i]][m];
		(ans+=k[i]*sb[i])%=base;
	}
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++){
		//how many way to choose m from n that kill both
		//number of way to kill each - number of way to kill both 
		auto temp=f[i]|f[j];
		long long a=k[i]+k[j]+c[n-temp.count()][m]-c[n][m];
		(ans+=((a*b[i])%base*b[j])*2)%=base;
		// =only select from thing that can't kill j
	}
	(ans+=base)%=base;
	cout<<ans<<'\n';
}