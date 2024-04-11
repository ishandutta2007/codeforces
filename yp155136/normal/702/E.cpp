#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const LL INF = 1e15+6;
const int MAX_N = 1e5 + 6;
const LL MAX_K = 1e10 +5;
const int MAX_P = 40;

struct Node {
	int to;
	LL len;
	LL min;
} node[MAX_P][MAX_N];

int binary[MAX_P];

Node MP(int _to,LL _len, LL _min) {
	Node tmp;
	tmp.to = _to;
	tmp.len = _len;
	tmp.min = _min;
	return tmp;
}

pii query(int id,LL k) {
	memset(binary,0,sizeof(binary));
	int i=0;
	while (k>0) {
		binary[i++] = k%2;
		k/=2;
	}
	pii ret=make_pair(0,INF);
	for (int x=MAX_P-1;x>=0;x--) {
		if (binary[x]==1) {
			ret = make_pair(ret.first + node[x][id].len , min(ret.second,node[x][id].min));
			id=node[x][id].to;
		}
	}
	return ret;
}

int main () {
	int n;
	LL k;
	while (scanf("%d %I64d",&n,&k) != EOF) {
		for (int x=0;n>x;x++) {
			scanf("%d",&node[0][x].to);
		}
		for (int x=0;n>x;x++) {
			scanf("%d",&node[0][x].len);
			node[0][x].min = node[0][x].len;
		}
		for (int i=1;MAX_P>i;i++) {
			for (int j=0;n>j;j++) {
				int tmp=node[i-1][j].to;
				node[i][j] = MP(node[i-1][tmp].to,node[i-1][j].len+node[i-1][tmp].len,min(node[i-1][j].min,node[i-1][tmp].min));
			}
		}
		for (int x=0;n>x;x++) {
			pii ret=query(x,k);
			printf("%I64d %I64d\n",ret.first,ret.second);
		}
	}
}