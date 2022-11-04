#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int f[605][605];
int C[605][605];
map<int,int> mp;
int main(){
	int n,m,ans=1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (int j=2;j*j<=x;j++)
			for (;x%(j*j)==0;x/=j*j);
		mp[x]++;
	}
	for (int i=0;i<=2*n;i++)
		for (int j=C[i][0]=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	f[0][0]=1; n=m=0;
	map<int,int>::iterator it;
	for (it=mp.begin();it!=mp.end();it++){
		int t=it->second;
		for (int i=1;i<=t;i++)
			ans=1ll*ans*i%mo;
		for (int i=0;i<=m;i++)
			if (f[n][i])
				for (int k=1;k<=t;k++)
					for (int j=0;j<=i&&j<=k;j++)
						f[n+1][i-j+t-k]=(f[n+1][i-j+t-k]+1ll*f[n][i]*C[t-1][k-1]%mo*C[i][j]%mo*C[m+1-i][k-j]%mo)%mo;
		n++; m+=t;
	}
	printf("%d",1ll*ans*f[n][0]%mo);
}