#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 14;
const int MAX_K = 1006;
const int INF = 1e9 + 7;

char mp[MAX_K][MAX_N][MAX_N];
int adj[MAX_K][MAX_K];

int f(int i,int j,int n,int m) {
	int ret=0;
	for (int x=1;n>=x;x++) {
		for (int y=0;m>y;y++) {
			ret += (mp[i][x][y]!=mp[j][x][y]);
		}
	}
	return ret;
}

vector<pii> ans;

int d[MAX_K];
int from[MAX_K];
bool visit[MAX_K];

int Prim(int n) {
	//n equals k in problem
	int ret=0;
	int id=1;
	fill(d,d+MAX_K,INF);
	fill(from,from+MAX_K,INF);
	fill(visit,visit+MAX_K,false);
	from[1] = 1;
	d[1]=0;
	visit[1]=1;
	for (int i=2;n>=i;i++) {
		if (adj[1][i] < d[i]) {
			d[i] = adj[1][i];
			from[i] = 1;
		}
	}
	for (int i=2;n>=i;i++) {
		int mn=INF;
		int mn_id=-1;
		for (int j=1;n>=j;j++) {
			if (visit[j] == 0 && d[j]<mn) {
				mn=d[j];
				mn_id=j;
			}
		}
		ans.push_back(make_pair(mn_id,mn));
		ret+=mn;
		d[mn_id] = 0;
		visit[mn_id]=1;
		for (int j=1;n>=j;j++) {
			if (d[mn_id] + adj[j][mn_id] < d[j]) {
				d[j] = d[mn_id] + adj[j][mn_id];
				from[j] = mn_id;
			}
		}
	}
	return ret;
}

int main () {
	int n,m,k,w;
	while (scanf("%d %d %d %d",&n,&m,&k,&w) != EOF) {
		getchar();
		for (int i=1;k>=i;i++) {
			for (int j=1;n>=j;j++) {
				scanf("%s",mp[i][j]);
			}
		}
		for (int i=1;k>=i;i++) {
			adj[i][i] = 0;
			for (int j=i+1;k>=j;j++) {
				adj[i][j] = adj[j][i] = min(w*f(i,j,n,m),n*m);
//				cout<<"adj["<<i<<"]["<<j<<"] = "<<adj[i][j]<<endl;
			}
		}
		ans.clear();
		printf("%d\n",Prim(k)+n*m);
		puts("1 0");
		for (auto i:ans) {
			if (i.second == n*m) printf("%d 0\n",i.first);
			else printf("%d %d\n",i.first,from[i.first]);
		}
	}
}