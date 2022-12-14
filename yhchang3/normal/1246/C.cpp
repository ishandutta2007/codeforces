#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long int D[2000][2000],R[2000][2000],SD[2001][2001],SR[2001][2001];
int cntr[2000][2000],cntd[2000][2000];
string g[2000];
int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>g[i];
	if(n+m==2){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)
			if(j==m-1)
				cntr[i][j]=0;
			else
				cntr[i][j]=cntr[i][j+1]+(g[i][j+1]=='R');
	for(int j=0;j<m;j++)
		for(int i=n-1;i>=0;i--)
			if(i==n-1)
				cntd[i][j]=0;
			else
				cntd[i][j]=cntd[i+1][j]+(g[i+1][j]=='R');
	for(int i=n-1;i>=0;i--)
		for(int j=m-1;j>=0;j--){
			if(j==m-1)
				R[i][j]=i==n-1;
			else
				R[i][j]=SD[i][j+1]-SD[i][m-cntr[i][j]];
			if(i==n-1)
				D[i][j]=j==m-1;
			else
				D[i][j]=SR[i+1][j]-SR[n-cntd[i][j]][j];
			R[i][j]%=mod;
			D[i][j]%=mod;
			SR[i][j]=(SR[i+1][j]+R[i][j])%mod;
			SD[i][j]=(SD[i][j+1]+D[i][j])%mod;
		}
	cout<<((R[0][0]+D[0][0])%mod+mod)%mod<<endl;
}