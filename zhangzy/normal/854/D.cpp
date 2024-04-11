#include<bits/stdc++.h>
#define ll long long
#define D 1000000
using namespace std;
ll inf=233333333333;
struct Node{
	int who,cost;
};
vector<Node>vec[2][D+233];
ll mn[D+233]={0},f[D+233],tot,ans=inf;
int n,m,k;

void doit(Node t){
	if (mn[t.who]>t.cost){
		tot-=(mn[t.who]-t.cost);
		mn[t.who]=t.cost;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int d,x,y,z;m--;){
		scanf("%d%d%d%d",&d,&x,&y,&z);
		vec[!!y][d].push_back((Node){x+y,z});
	}
	
	for (int i=1;i<=n;i++) mn[i]=inf;
	tot=inf*n;
	for (int i=1;i<=D;i++){
		for (int j=0;j<(int)vec[0][i].size();j++){
			doit(vec[0][i][j]);
		}
		f[i]=tot;
	}
	
	for (int i=1;i<=n;i++) mn[i]=inf;
	tot=inf*n;
	for (int i=D;i;i--){
		for (int j=0;j<(int)vec[1][i].size();j++){
			doit(vec[1][i][j]);
		}
		ans=min(ans,(ll)((i-k-1>0)?tot+f[i-k-1]:inf));
	}
	if (ans==inf) ans=-1;
	cout<<ans;
}