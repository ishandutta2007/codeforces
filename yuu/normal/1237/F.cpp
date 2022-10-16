#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=998244353;
int h, w, n;
bool badr[3602];
bool badc[3602];
using ll=long long;
ll fact[3666];
ll p[3666][3666];
ll f[3666][1888];
ll a[1801];
ll b[1801];
void dp(int n, bool *bad, ll *res){
	for(int i=0; i<=n; i++) for(int j=0; j<=i/2; j++) f[i][j]=0;
	f[0][0]=1;
	for(int i=0; i<=n; i++) for(int j=0; j<=i/2; j++) if(f[i][j]){
		f[i+1][j]+=f[i][j];
		while(f[i+1][j]>=base) f[i+1][j]-=base;
		if((!bad[i+1])&&(!bad[i+2])){
			f[i+2][j+1]+=f[i][j];
			while(f[i+2][j+1]>=base) f[i+2][j+1]-=base;
		}
	}
	for(int i=0; i<=n/2; i++) res[i]=f[n][i];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>h>>w>>n;
	for(int i=0; i<3666; i++){
		p[i][i]=p[i][0]=1;
		for(int j=1; j<i; j++){
			p[i][j]=p[i-1][j]+p[i-1][j-1];
			while(p[i][j]>=base) p[i][j]-=base;
		}
	}
	fact[0]=1;
	for(int i=1; i<3666; i++) fact[i]=(fact[i-1]*i)%base;
	for(int i=0; i<3666; i++){
		for(int j=0; j<=i; j++) (p[i][j]*=fact[j])%=base;
	}
	for(int i=1; i<=n; i++){
		int r, c;
		cin>>r>>c;
		badr[r]=1;
		badc[c]=1;
		cin>>r>>c;
		badr[r]=1;
		badc[c]=1;
	}
	dp(h, badr, a);
	dp(w, badc, b);
	int fr=0;
	for(int i=1; i<=h; i++) if(!badr[i]) fr++;
	int fc=0;
	for(int i=1; i<=w; i++) if(!badc[i]) fc++;
	ll ans=0;
	for(int i=0; i<=fr/2; i++) if(a[i]) for(int j=0; j<=fc/2; j++) if(b[j]){
		if(j+i*2>fr) break;
		if(j*2+i>fc) break;
		(ans+=((a[i]*b[j])%base)*((p[fr-i*2][j]*p[fc-j*2][i])%base))%=base;
	}
	cout<<ans<<'\n';
}