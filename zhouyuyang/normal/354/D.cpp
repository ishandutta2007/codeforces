#include<bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int X[100005],Y[100005];
int f[2][1000],sum[1000];
int n,k,kk,ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		X[i]=x-y+1; Y[i]=y;
		v[X[i]].push_back(i);
	}
	kk=int(sqrt(6*k))+1;
	memset(f,100,sizeof(f)); f[0][0]=0;
	for (int i=1,c=1;i<=n;i++,c^=1){
		memset(f[c],100,sizeof(f[c]));
		memset(sum,0,sizeof(sum));
		for (int j=0;j<v[i].size();j++){
			int id=v[i][j],las=n+1-i;
			if (las-Y[id]<=kk) sum[las-Y[id]+1]-=3;
		}
		for (int j=1;j<=kk;j++)
			sum[j]+=sum[j-1];
		for (int j=0;j<=kk;j++)
			f[c][j]=f[c^1][j+1]+sum[j];
		f[c][0]=min(f[c][0],f[c^1][0]);
		int mnv=2e9;
		for (int j=0;j<=kk;j++)
			mnv=min(mnv,f[c^1][j]);
		for (int j=0;j<=kk;j++)
			f[c][j]=min(f[c][j],mnv+j*(j+1)/2+2+sum[j]);
	}
	int ans=2e9;
	for (int i=0;i<=kk;i++)
		ans=min(ans,f[n&1][i]);
	printf("%d\n",3*k+ans);
}