#include<bits/stdc++.h>
using namespace std;

int n, G[8][8], deg[8];

#define pii pair<int,int>
#define fi first
#define se second

vector<int>vec[8];
vector<pii>ans;

int rd(){
	static char s[233];
	scanf("%s",s); return strlen(s);
}

int usd[8];

void dfs(int x){
	usd[x]=1;
	for (int y=1;y<=6;++y)
		if (G[x][y]&&!usd[y]){
			ans.push_back({vec[x].back(),vec[y].back()});
			--deg[x]; --deg[y]; --G[x][y]; --G[y][x];
			dfs(y);
		}
}

bool chk(){
	for (int S=1;S<(1<<6);++S){
		int v=0, e1=0, e2=0;
		for (int i=1;i<=6;++i)
			if (S>>i-1&1)
				v+=vec[i].size();
		for (int i=1;i<=6;++i)
			if (S>>i-1&1)
				for (int j=1;j<=6;++j)
					if (i!=j){
						if (S>>j-1&1)
							e2+=G[j][i];
						else
							e1+=G[j][i];
					}
		//printf(" %d %d %d %d\n",S,v,e1,e2);
		int e=e1+e2/2;
		if (v>e) return 0;
	}
	return 1;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		int t=0;
		for (int x=i;x;x/=10) ++t;
		vec[t].push_back(i);
	}
	for (int i=1;i<n;++i){
		int x=rd(), y=rd();
		if (x==y){
			if (vec[x].size()<2){
				puts("-1"); exit(0);
			}
			int bk=vec[x].back(); vec[x].pop_back();
			ans.push_back({bk,vec[x].back()});
		}else{
			++G[x][y]; ++G[y][x];
			++deg[x]; ++deg[y];
		}
	}
	if (*max_element(deg+1,deg+7)==0) goto ok;

	int sta[8];

	dfs(1);
	for (int i=1;i<=6;++i){
		if (!vec[i].size()) continue;
		if (!usd[i]){
			puts("-1"); exit(0);
		}
		sta[i]=vec[i].back();
		vec[i].pop_back();
	}

	// for (int i=1;i<=6;++i) printf(" %d %d\n",i,(int)vec[i].size());
	// for (int i=1;i<=6;++i)
	// 	for (int j=1;j<=6;++j)
	// 		if (G[i][j])
	// 			printf("  %d %d %d\n",i,j,G[i][j]);
	
	if (!chk()){
		puts("-1"); exit(0);
	}
	cerr<<"fuck"<<endl;
	while (ans.size()<n-1){
		for (int i=1;i<=6;++i)
			for (int j=1;j<=6;++j)
				if (i!=j&&vec[j].size()&&G[i][j]){
					--G[i][j]; --G[j][i]; int bk=vec[j].back(); vec[j].pop_back();
					if (chk()){
						ans.push_back({sta[i],bk});
						goto over;
					}
					++G[i][j]; ++G[j][i]; vec[j].push_back(bk);
				}
		over:;
	}

	ok:;
	for (auto o:ans) printf("%d %d\n",o.fi,o.se);
}