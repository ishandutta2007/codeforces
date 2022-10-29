#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 +6;

int deg[MAX_N];
int col[MAX_N];
vector<int> edg[MAX_N];
bool check[MAX_N];
bool visit[MAX_N];

void dfs(int id) {
	visit[id]=1;
	vector<int> v;
	check[col[id]]=1;
	v.push_back(col[id]);
	for (auto i:edg[id]) {
		v.push_back(col[i]);
		if (col[i] != -1) check[col[i]]=1;
	}
	int j=1;
	for (auto i:edg[id]) {
		while (check[j]) j++;
		if (col[i] == -1) {
			col[i]=j;
			j++;
		}
	}
	for (auto i:v) {
		if (i!=-1) check[i]=false;
	}
	for (auto i:edg[id]) {
		if (!visit[i])dfs(i);
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		memset(deg,0,sizeof(deg));
		for (int i=0;n>=i;i++) {
			edg[i].clear();
		}
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
			deg[a]++;
			deg[b]++;
		}
		memset(col,-1,sizeof(col));
		int root=-1;
		for (int i=1;n>=i;i++) {
			if (deg[i]==1) {
				root=i;
			}
		}
		col[root]=1;
		memset(check,0,sizeof(check));
		memset(visit,0,sizeof(visit));
		dfs(root);
		memset(check,0,sizeof(check));
		for (int i=1;n>=i;i++) {
			check[col[i]]=1;
		}
		int j=1;
		while (check[j]) j++;
		j--;
		printf("%d\n",j);
		for (int i=1;n>=i;i++){
			if (i!=1) printf(" ");
			printf("%d",col[i]);
		}
		puts("");
	}
}