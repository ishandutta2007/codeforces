#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 106;

int X[MAX_N],Y[MAX_N];

vector<int> edg[MAX_N];
bool visit[MAX_N];

void dfs(int id) {
	visit[id]=1;
	for (auto i:edg[id]) {
		if (!visit[i]) dfs(i);
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d %d",&X[i],&Y[i]);
		}
		for (int i=1;n>=i;i++) {
			for (int j=1;n>=j;j++) {
				if (i==j) continue;
				if (X[i]==X[j] || Y[i]==Y[j]) {
					edg[i].push_back(j);
					edg[j].push_back(i);
				}
			}
		}
		memset(visit,0,sizeof(visit));
		int sz=0;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) {
				dfs(i);
				sz++;
			}
		}
		printf("%d\n",sz-1);
	}
}