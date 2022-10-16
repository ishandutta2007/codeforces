#include <bits/stdc++.h>
using namespace std;
int n, k;
int full;
char c[200002];
int cnt[200002][18];
int best[200002][18];
int f[1<<18];
const int inf=1<<20;
bool check(int req){
	for(int i=n; i>=1; i--){
		int j=i+req-1;
		for(int ch=1; ch<=k; ch++){
			if(j>n) best[i][ch]=inf;
			else if(cnt[j][0]+cnt[j][ch]-cnt[i-1][0]-cnt[i-1][ch]<req){//whole range cannot be filled with ch
				best[i][ch]=(i<n)?best[i+1][ch]:inf;
			}
			else best[i][ch]=i+req;
		}
	}
	for(int i=0; i<=full; i++) f[i]=inf;
	f[0]=1;
	for(int i=0; i<=full; i++) if(f[i]<=n){
		for(int j=0; j<k; j++) if(((i>>j)&1)==0){
			f[i^(1<<j)]=min(f[i^(1<<j)], best[f[i]][j+1]);
		}
		if(f[full]!=inf) return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	full=(1<<k)-1;
	for(int i=1; i<=n; i++){
		cin>>c[i];
		for(int j=0; j<=k; j++) cnt[i][j]=cnt[i-1][j];
		if(c[i]=='?'){
			cnt[i][0]++;
		}
		else{
			c[i]-='a'-1;
			cnt[i][c[i]]++;
		}
		
	}
	int low=1, high=n/k, mid, ans=0;
	while(low<=high){
		mid=(low+high)/2;
		if(check(mid)){
			ans=mid;
			low=mid+1;
		}
		else high=mid-1;
	}
	cout<<ans<<'\n';
}