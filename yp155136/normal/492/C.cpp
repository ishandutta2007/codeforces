#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

const int MAX_N = 1e5 + 6;

int main () {
	int n,r,a;
	while (scanf("%d %d %d",&n,&r,&a) != EOF) {
		LL need = LL(n)*a;
		priority_queue<pii,vector<pii>,greater<pii> >pq;
		for (int i=1;n>=i;i++) {
			LL x,y;
			scanf("%I64d %I64d",&x,&y);
			pq.push(make_pair(y,x));
			need -= x;
		}
		LL cnt=0;
		while (need > 0) {
			pii _=pq.top();
			pq.pop();
			LL can=r-_.second;
			if (can >= need) {
				cnt += need*_.first;
				break;
			}
			cnt += can*_.first;
			need -= can;
		}
		printf("%I64d\n",cnt);
	}
}