#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long
typedef pair<int,int> pii;
const int MAX_N = 5e5 + 6;
const int INF = 1e9+7;

struct Node {
	char c;
	int x;
	int y;
} ipt[MAX_N];

Node MP(char _c,int _x,int _y) {
	Node node;
	node.c=_c;
	node.x=_x;
	node.y=_y;
	return node;
}

vector<Node> rv;
vector<Node> rh;
vector<Node> bu;
vector<Node> bd;

bool operator<(const Node &n1,const Node &n2) {
	return n1.x<n2.x || n1.x==n2.x && n1.y<n2.y;
}

main () {
	int n;
	while (scanf("%I64d",&n) != EOF) {
		int tx,ty;
		rv.clear();
		rh.clear();
		bu.clear();
		bd.clear();
		for (int x=0;n>=x;x++) {
			if (!x) {
				int i,j;
				scanf("%I64d %I64d",&i,&j);
				ipt[x] = MP('K',i,j);
				tx=i;
				ty=j;
				continue;
			}
			char c;
			long long i,j;
			getchar();
			scanf("%c %I64d %I64d",&c,&i,&j);
			ipt[x]=MP(c,i,j);
			Node tmp=MP(c,-i+2*INF,-j+2*INF);
			if (i == tx) {
				rv.push_back(ipt[x]);
				rv.push_back(tmp);
			}
			else if (j == ty) {
				rh.push_back(ipt[x]);
				rh.push_back(tmp);
			}
			else if (j-i==ty-tx ) {
				bu.push_back(ipt[x]);
				bu.push_back(tmp);
			}
			else if (j+i == tx+ty) {
//				puts("in");
				bd.push_back(ipt[x]);
				bu.push_back(tmp);
			}
		}
		Node qq=MP('X',-tx+2*INF,-ty+2*INF);
		rv.push_back(MP('X',tx,-INF)); rv.push_back(MP('X',tx,INF)); rv.push_back(MP('X',tx,3*INF));
		rh.push_back(MP('X',-INF,ty)); rv.push_back(MP('X',INF,ty)); rv.push_back(MP('X',3*INF,ty));
		bu.push_back(MP('X',-INF,-INF)); bu.push_back(MP('X',INF,INF)); bu.push_back(MP('X',3*INF,3*INF));
		bd.push_back(MP('X',-INF,-INF)); bd.push_back(MP('X',INF,INF)); bd.push_back(MP('X',3*INF,3*INF));
		bool ans=false;
		sort(rh.begin(),rh.end());
		sort(rv.begin(),rv.end());
		sort(bu.begin(),bu.end());
		sort(bd.begin(),bd.end());
		//check rook first
		Node tmp= *lower_bound(rh.begin(),rh.end(),qq);
		if (tmp.c == 'R' || tmp.c == 'Q') ans=true;
		tmp = *upper_bound(rh.begin(),rh.end(),ipt[0]);
		if (tmp.c == 'R' || tmp.c == 'Q') ans=true;
		tmp = *lower_bound(rv.begin(),rv.end(),qq);
		if (tmp.c == 'R' || tmp.c == 'Q') ans=true;
		tmp = *upper_bound(rv.begin(),rv.end(),ipt[0]);
		if (tmp.c == 'R' || tmp.c == 'Q') ans=true;
		tmp = *lower_bound(bu.begin(),bu.end(),qq);
		if (tmp.c == 'B' || tmp.c == 'Q') ans=true;
		tmp = *upper_bound(bu.begin(),bu.end(),ipt[0]);
		if (tmp.c == 'B' || tmp.c == 'Q') ans=true;
		tmp = *lower_bound(bd.begin(),bd.end(),qq);
		if (tmp.c == 'B' || tmp.c == 'Q') ans=true;
		tmp = *upper_bound(bd.begin(),bd.end(),ipt[0]);
		if (tmp.c == 'B' || tmp.c == 'Q') ans=true;
		if (ans) puts("YES");
		else puts("NO");
	}
}