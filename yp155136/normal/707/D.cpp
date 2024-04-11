#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX_N = 1003;
const int MAX_Q = 1e5+6;

int n,m,q;
bool rev[MAX_N]; //reverse --- for type 3
bool pnt[MAX_N][MAX_N];
int ans[MAX_Q];
int row[MAX_N];
int cnt;
vector<int> edg[MAX_Q];

struct Query {
	int type;
	int i,j;
	void input(int x) {
		j=0;
		scanf("%d %d",&type,&i);
		if (type<=2) scanf("%d",&j);
		if (type==4) edg[i].push_back(x);
		else edg[x-1].push_back(x);
	}
} query[MAX_Q];

void dfs(int id) {
	int type=query[id].type;
	int i=query[id].i;
	int j=query[id].j;
	bool change=false;
	if (type==1) {
		if ((rev[i] ^ pnt[i][j]) == 0) {
			change=true;
			cnt++;
			row[i]++;
			pnt[i][j] ^= 1;
		}
	} 
	else if (type==2) {
		if ((rev[i] ^ pnt[i][j]) == 1) {
			change=true;
			cnt--;
			row[i]--;
			pnt[i][j] ^= 1;
		}
	} 
	else if (type==3) {
		rev[i] ^= 1;
		cnt -= row[i];
		cnt += (m-row[i]);
		row[i] = m-row[i];
		change=true;
	}
	ans[id]=cnt;
	for (auto iter=edg[id].begin();iter!=edg[id].end();iter++) {
		int tmp=*iter;
		dfs(tmp);
	}
	if (type==1 && change) {
		cnt--;
		row[i]--;
		pnt[i][j] ^= 1;
	}
	else if (type==2 && change) {
		cnt++;
		row[i]++;
		pnt[i][j] ^= 1;
	}
	else if (type==3 &&change) {
		rev[i] ^= 1;
		cnt -= row[i];
		row[i] = m-row[i];
		cnt += row[i];
	}
}

int main () {
	while (scanf("%d %d %d",&n,&m,&q) != EOF) {
		for (int x=1;q>=x;x++) {
			query[x].input(x);
		}
		dfs(0);
		for (int x=1;q>=x;x++) {
			printf("%d\n",ans[x]);
		}
	}
}