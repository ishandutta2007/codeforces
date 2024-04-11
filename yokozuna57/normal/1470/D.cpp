#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> G[300010];

int c[300010];

void solve(){
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int v=que.front(); que.pop();
		if(c[v]!=0)continue;
		c[v]=1;
		vector<int> vec;
		for(int u: G[v]){
			if(c[u]==0){
				c[u]=-1;
				vec.push_back(u);
			}
		}
		for(int u: vec){
			for(int w: G[u]){
				if(c[w]==0)que.push(w);
			}
		}
	}
	//for(int i=0;i<n;i++)cout<<c[i]<<" "; cout<<endl;
	bool ok=true;
	vector<int> ret;
	for(int i=0;i<n;i++){
		if(c[i]==0){
			ok=false;
			break;
		}
		if(c[i]==1)ret.push_back(i);
	}
	if(ok){
		puts("YES");
		printf("%d\n",(int)ret.size());
		for(int i=0;i<ret.size();i++){
			printf("%d%c",ret[i]+1,(i+1==ret.size())?'\n':' ');
		}
	}
	else puts("NO");
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			G[i].clear();
			c[i]=0;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b); a--; b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		solve();
	}
}