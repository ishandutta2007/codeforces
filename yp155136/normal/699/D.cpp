#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 2e5 + 6;
int a[MAX_N];
int b[MAX_N]; //ans

struct Edge {
	int a,b;
	int p,s; //parent and son
} edg[MAX_N];

Edge MP(int _a,int _b,int _p,int _s) {
	Edge ret;
	ret.a=_a;
	ret.b=_b;
	ret.p=_p;
	ret.s=_s;
	return ret;
}

struct DisjointSet {
	int p[MAX_N];
	void init(int n) {
		for (int x=0;n>=x;x++) p[x]=x;
	}
	int Find(int x) {
		return p[x]==x?x:p[x]=Find(p[x]);
	}
	void Union(int x,int y) {
		p[Find(x)] = Find(y);
	}
} djs;

int root;
int cnt;

void magic(int n) {
	djs.init(n);
	int i=1,j=0; //i==>edge
	for (;n>=i;) {
		while (n>=i && djs.Find(edg[i].a) == djs.Find(edg[i].b)) {
			if (edg[i].s == edg[i].p) {
				i++;
				continue;
			}
			else if (root!=0) {
				cnt++;
				b[edg[i].s]=root;
				i++;
			}
			else {
				cnt++;
				root=edg[i].s;
				b[edg[i].s]=edg[i].s;
				i++;
			}
		}
		if (n>=i) djs.Union(edg[i].a,edg[i].b);
		i++;
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		root=0;
		cnt=0;
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			if (a[x]==x && root==0) {
				root=x;
				edg[x]=MP(x,x,x,x);
				b[x]=a[x];
			}
			else if (a[x]==x && root!=0) {
				cnt++;
				b[x]=root;
				edg[x]=MP(root,a[x],root,a[x]);
			}
			else {
				edg[x]=MP(a[x],x,a[x],x);
				b[x]=a[x];
			}
		}
		magic(n);
		printf("%d\n",cnt);
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",b[x]);
		}
		puts("");
	}
}