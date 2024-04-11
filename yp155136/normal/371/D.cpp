#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const long long int INF = 1234567899876543;

const int MAX_N = 200004;
LL a[MAX_N];
LL ans[MAX_N];

struct DisjointSet {
	int p[MAX_N];
	void init(int x) {
		for (int i=0;x>=i;i++) p[i]=i;
	}
	int Find(int x) {
		return p[x] == x ? x : p[x]=Find(p[x]);
	}
	void Union(int x,int y) {  //x-->y
		if (x<y) p[Find(x)]=Find(y);
		else p[Find(x)]=Find(y);
	}
} djs;

void pull(int i,int j) {
	int h=djs.Find(i);
	ans[h]+=j;
	if (a[h]<ans[h]) {
		int tmp=ans[h]-a[h];
		ans[h]=a[h];
		djs.Union(h,h+1);
		pull(i+1,tmp);
	}
	return;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) scanf("%d",&a[x]);
		a[n+1]=INF;
		memset(ans,0,sizeof(ans));
		int m;
		scanf("%d",&m);
		djs.init(n+1);
		while (m--) {
			int d;
			scanf("%d",&d);
			if (d==1) {
				int i,j;
				scanf("%d %d",&i,&j);
				pull(i,j);
			}
			else if (d==2) {
				int i;
				scanf("%d",&i);
				printf("%I64d\n",ans[i]);
			}
		}
	}
}