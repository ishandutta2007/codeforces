#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll INF = 2e18;
ll dp[60],cyc[60];

ll add(ll x,ll y){
	return min(x+y,INF);
}

ll mult(ll x,ll y){
	if(1.0L*x*y>INF)	return INF;
	else	return x*y;
}
int ans[51];
bool vis[51];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	cyc[0]=cyc[1]=cyc[2]=1;
	for(int i=3;i<=50;i++)
		cyc[i]=mult(cyc[i-1],(i-2));
	while(T--){
		int n;
		ll k;
		cin>>n>>k;
		dp[n+1]=1;
		for(int i=n;i>=1;i--){
			dp[i]=0;
			for(int j=i;j<=n;j++)
				dp[i]=add(dp[i],mult(dp[j+1],cyc[j-i+1]));
		}
		memset(vis,false,sizeof vis);
		memset(ans,0,sizeof ans);
		
		if(dp[1]<k){
			cout<<-1<<'\n';
			continue;
		}
		for(int pos=1;pos<=n;pos++){
			for(int i=pos;i<=n;i++){
				if(mult(dp[i+1],cyc[i-pos+1])<k){
					k-=mult(dp[i+1],cyc[i-pos+1]);
					continue;
				}	
				ll cnt;
				if(k%dp[i+1]==0){
					cnt=k/dp[i+1];
					k=dp[i+1];
				}
				else{
					cnt=k/dp[i+1];
					k-=dp[i+1]*cnt;
					cnt++;
				}
				vis[i]=true;
				ans[pos]=i;
				for(int j=pos+1;j<=i;j++){
					for(int z=pos;z<i;z++){
						if(z==j||vis[z])	continue;
						if(i==j){
							ans[j]=z;
							vis[z]=true;
							break;
						}
						int t=z;
						while(t!=j&&t!=0)	t=ans[t];
						if(t==0){
							if(cyc[i-j+1]<cnt){
								cnt-=cyc[i-j+1];
								continue;
							}
							else{
								ans[j]=z;
								vis[z]=true;
								break;
							}
						}
						else	continue;
					}
				}
				pos=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
}