#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,a[333],bel[333],sz[333]={0},b[333],tot=0,now,sum=0;
ll f[333][333],jc[333],ny[333],ans=1;
map<int,int>mp[333];
map<int,int>::iterator it;

bool C(ll x){
	ll y=sqrt(x+0.5);
	return y*y==x;
}

ll K(ll x,int y){
	for (ll t=1;1;x=x*x%mod,y>>=1){
		if (y) t=y&1?t*x%mod:t; else return t; 
	}
}
ll CH(int x,int y){
	return jc[x] *ny[x-y]%mod *ny[y]%mod;
}
ll R(ll &x,ll y){
	x=(x+y)%mod;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++){
			if (C((ll)a[i]*a[j])){
				sz[bel[i]=j]++;
				mp[j][a[i]]++;
				break;
			}
		}
	}
	
	jc[0]=1;
	for (int i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	ny[n]=K(jc[n],mod-2);
	for (int i=n;i>0;i--){
		ny[i-1]=ny[i]*i%mod;
	}
	
	for (int i=1;i<=n;i++){
		if (bel[i]==i){
			b[++tot]=sz[i];
			ans=ans*jc[sz[i]]%mod;
			/*for (it=mp[i].begin();it!=mp[i].end();it++){
				ans=ans*ny[(int)it->second]%mod;
			}*/
		}
	}
	memset(f,0,sizeof f);
	
	f[0][0]=1;
	int tem;
	for (int i=0;i<tot;i++){
		tem=b[i+1];//printf(" %d\n",b[i+1]);
		for (int j=0;j<=sum;j++){
			if (now=f[i][j]){
				for (int x=1;x<=min(sum+1,tem);x++){// 
					for (int y=max(0,x+j-sum-1);y<=min(j,x);y++){// 
						R(f[i+1][j-y+tem-x],now *CH(tem-1,x-1)%mod *CH(j,y)%mod *CH(sum+1-j,x-y)%mod );
					}
				}
			}
		}
		sum+=tem;
	}
	/*for (int i=0;i<=3;i++){
		for (int j=0;j<=10;j++){
			printf(" %I64d",f[i][j]);
		}printf("\n");
	}*/
	ans=ans*f[tot][0]%mod;
	ans=(ans%mod+mod)%mod;
	printf("%I64d\n",ans);
}