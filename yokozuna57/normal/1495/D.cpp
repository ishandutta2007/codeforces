#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

const int INF=1000000000;
const int MOD=998244353;

int n,m;
int a[602],b[602];
vector<int> G[402];
int d[402][402];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
		a[i]--; b[i]--;
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)d[i][j]=INF;
		d[i][i]=0;
	}
	for(int i=0;i<m;i++){
		d[a[i]][b[i]]=1;
		d[b[i]][a[i]]=1;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	
	int v[402];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			long long ret=1;
			for(int t=0;t<=d[i][j];t++)v[t]=-1;
			for(int k=0;k<n;k++){
				if(d[i][k]+d[k][j]==d[i][j]){
					if(v[d[i][k]]!=-1)ret=0;
					else v[d[i][k]]=k;
				}
			}
			if(ret!=0){
				for(int k=0;k<n;k++){
					if(d[i][k]+d[k][j]==d[i][j]){}
					else {
						long long cnt=0;
						for(int l: G[k]){
							if(d[l][i]==d[k][i]-1&&d[l][j]==d[k][j]-1)cnt++;
						}
						ret*=cnt;
						ret%=MOD;
					}
				}
			}
			printf("%lld%c",ret,(j+1==n)?'\n':' ');
		}
	}
}