#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll MOD=998244353;

ll cntl[1<<14][15][1<<6];
ll cntr[1<<14][15][1<<6];
ll ret[1<<13];

int n;
char c[15][15];
int x[10];
int used;
int conn;
void dfs(int k,int l,int r){
	if(k==l){
		//cout<<used<<" "<<x[l-1]<<" "<<conn<<endl;
		cntl[used][x[k-1]][conn]++;
	}
	if(k==r){
		cntr[used][x[k-1]][conn]++;
		return;
	}
	for(int i=0;i<n;i++){
		if((used>>i)&1)continue;
		x[k]=i;
		used+=1<<i;
		if(k>=1&&c[x[k]][x[k-1]]=='1')conn+=1<<(k-1);
		dfs(k+1,l,r);
		used-=1<<i;
		if(k>=1&&c[x[k]][x[k-1]]=='1')conn-=1<<(k-1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("\n");
		for(int j=0;j<n;j++){
			scanf("%c",&c[i][j]);
		}
	}
	
	int rev[1<<6];
	for(int i=0;i<(1<<(n-n/2-1));i++){
		rev[i]=0;
		for(int j=0;j<n-n/2-1;j++){
			if((i>>j)&1)rev[i]+=1<<(n-2-j);
		}
	}
	
	
	dfs(0,n/2,n-n/2);
	
	/*for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<4;k++){
				cout<<i<<" "<<j<<" "<<k<<" "<<cntl[i][j][k]<<" "<<cntr[i][j][k]<<endl;
			}
		}
	}*/
	
	ll ret[1<<13]={};
	
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1)cnt++;
		}
		if(cnt!=n/2)continue;
		int j=(1<<n)-1-i;
		for(int s=0;s<n;s++){
			if(((i>>s)&1)==0)continue;
			ll memo[2][1<<6] = {};
			for(int t=0;t<n;t++){
				if((i>>t)&1)continue;
				for(int u=0;u<(1<<(n-n/2-1));u++){
					memo[c[s][t]-'0'][u]+=cntr[j][t][u];
				}
			}
			for(int u=0;u<(1<<(n-n/2-1));u++){
				for(int t=0;t<(1<<(n/2-1));t++){
					ret[t+rev[u]]+=cntl[i][s][t]*memo[0][u];
					ret[t+(1<<(n/2-1))+rev[u]]+=cntl[i][s][t]*memo[1][u];
				}
			}
		}
	}
	for(int i=0;i<(1<<(n-1));i++){
		printf("%lld%c",ret[i],(i+1==(1<<(n-1)))?'\n':' ');
	}
}