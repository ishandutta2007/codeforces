#include<bits/stdc++.h>
using namespace std;

long long int a[101][101];
long long int res[101][101],tmp2[101][101];
const int mod = 1e9+7;
long long int mypow(long long int x,long long int b){
	long long int res=1;
	while(b){
		if(b&1)
			res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
void ex(int n,long long int b){
	for(int i=0;i<n;i++)
		res[i][i]=1;
	while(b){
		if(b&1){
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					tmp2[i][j]=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					for(int k=0;k<n;k++)
						tmp2[i][j]=(tmp2[i][j]+res[i][k]*a[k][j])%mod;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					res[i][j]=tmp2[i][j];
		}
		b>>=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				tmp2[i][j]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
					tmp2[i][j]=(tmp2[i][j]+a[i][k]*a[k][j])%mod;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=tmp2[i][j];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=res[i][j];
}
int v[101];
int c[101];
long long int cnt;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,k;
	cin>>N>>k;
	long long int tmp=N*(N-1)/2;
	for(int i=0;i<N;i++)
		cin>>v[i];
	for(int i=0;i<N;i++)
		if(v[i]==0)	cnt++;
	int tttmp=0;
	for(int i=cnt;i<N;i++)
		if(v[i]==1)	tttmp++;
	for(int j=0;j<=N;j++){
		if(j>N-cnt||N-j-cnt>cnt)	continue;
		long long int now=tmp;
		for(int i=0;i<=N;i++){
			if(i==j-1){
				now=((now-(2*cnt+j-N)*j)%mod+mod)%mod;
				a[i][j]=((2*cnt+j-N)*j)%mod*mypow(tmp,mod-2)%mod;
			}
			else if(i==j+1){
				now=((now-(N-cnt-j)*(N-cnt-j))%mod+mod)%mod;
				a[i][j]=((N-cnt-j)*(N-cnt-j)%mod*mypow(tmp,mod-2))%mod;
			}
		}
		a[j][j]=now*mypow(tmp,mod-2)%mod;
	}
	ex(N+1,k);
	cout<<a[N-cnt][tttmp]<<endl;
}