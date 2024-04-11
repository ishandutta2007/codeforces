#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 5002;
const int MAX_M = 5002;

struct Node {
	int c;
	int t;
	void init() {
		c=0;
		t=-1;
	}
	void modify(int x,int y) {
		c=x;
		t=y;
	}
};

bool operator> (const Node& n1, const Node& n2) {
	return n1.t > n2.t;
}

bool operator< (const Node& n1, const Node& n2) {
	return n1.t < n2.t;
}

bool operator== (const Node& n1, const Node& n2) {
	return n1.t == n2.t;
}

Node row[MAX_N];
Node col[MAX_M];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int x=0;n>=x;x++) row[x].init();
		for (int x=0;m>=x;x++) col[x].init();
		int a,b,c;
		for (int x=0;k>x;x++) {
			scanf("%d %d %d",&a,&b,&c);
			if (a==1) row[b].modify(c,x);
			if (a==2) col[b].modify(c,x);
		}
		Node tmp;
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				tmp = max(row[x],col[y]);
				if (tmp.t==-1) printf("0");
				else printf("%d",tmp.c);
				if (y!=m) printf(" ");
			}
			puts("");
		}
	}
}