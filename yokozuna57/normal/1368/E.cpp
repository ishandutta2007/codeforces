#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define fr first
#define sc second

int n,m;
int x[400010],y[400010];
int z[200010];

vector<int> G[200010];
void solve(){
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=0;i<m;i++)G[y[i]].push_back(x[i]);
	
	for(int i=1;i<=n;i++){
		z[i]=0;
		for(int j=0;j<G[i].size();j++){
			z[i]=max(z[i],z[G[i][j]]);
		}
		z[i]++;
		if(z[i]==3)z[i]=0;
	}
	
	vector<int> ret;
	for(int i=1;i<=n;i++){
		if(z[i]==0)ret.push_back(i);
	}
	printf("%d\n",(int)ret.size());
	for(int i=0;i<ret.size();i++){
		printf("%d%c",ret[i],(i+1==ret.size())?'\n':' ');
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)scanf("%d%d",&x[i],&y[i]);
		solve();
	}
}