#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 100003;

struct Edge {
	int a;
	int b;
	int c;
	void give_val(int _a,int _b,int _c) {
		a=_a,b=_b,c=_c;
	}
} edg[MAX_N];

bool use[MAX_N];
bool check[MAX_N];

struct DisjointSet {
	int p[MAX_N];
	int rank[MAX_N];
	void init(int n) {
		for (int x=0;n>=x;x++) {
			p[x]=x;
			rank[x]=1;
		}
	}
	int Find(int x) {
		return p[x]==x?x:Find(p[x]);
	}
	void Union(int x,int y) {
		if (rank[Find(x)]>rank[Find(y)]) {
			swap(x,y);
		}
		rank[Find(y)]+=rank[Find(x)];
		p[Find(x)]=Find(y);
	}
} djs;

int kruskal(int n,int m) {
	int i=0,j=0;
	int ans=0;
	for (;n-1>i&&m>j;i++) {
		while (djs.Find(edg[j].a)==djs.Find(edg[j].b) && m>j) j++;
		if (djs.Find(edg[j].a)!=djs.Find(edg[j].b)) {
			djs.Union(edg[j].a,edg[j].b);
			use[j]=true;
			j++;
			ans++;
		}
	}
	for (int x=0;m>x;x++) {
		if (use[x]==false) {
			if (check[djs.Find(edg[x].a)]==false) {
				check[djs.Find(edg[x].a)]=true;
				ans++;
			}
		}
	}
	return ans;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		djs.init(n);
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[x].give_val(i,j,1);
			use[x]=false;
			check[x]=false;
		}
		printf("%d\n",n-kruskal(n,m));
	}
}