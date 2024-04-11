#include<bits/stdc++.h>
const int N=1000005;
using namespace std;
int n,m,x,y,del[N],ans[N];
vector<int> e[N];
int main(){
	scanf("%d%d",&n,&m);
	while (m--) scanf("%d%d",&x,&y),e[x].push_back(y);
	for (int i=1;i<=n;i++) if (!del[i])
		for (int j=0;j<e[i].size();j++) if (e[i][j]>i) del[e[i][j]]=1;
	for (int i=n;i;i--) if (!del[i]){
		ans[++*ans]=i;
		for (int j=0;j<e[i].size();j++) del[e[i][j]]=1;
	}
	printf("%d\n",*ans);
	for (int i=1;i<=*ans;i++)
		printf("%d ",ans[i]);
}