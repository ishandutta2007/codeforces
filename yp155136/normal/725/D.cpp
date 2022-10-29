#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const LL MAX_N = 3e5 + 6;

LL w[MAX_N];
LL v[MAX_N];
pii a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%I64d %I64d",&v[x],&w[x]);
			a[x] = make_pair(v[x],MAX_N - x);
		}
		int best=MAX_N;
		sort(a+1,a+n+1);
		for (int x=1;n>=x;x++) {
			if (a[x] == make_pair(v[1],MAX_N-1)) {
				best=n-x+1;
			}
			a[x] = make_pair(a[x].first, -a[x].second + MAX_N);
		}
//		sort(a+1,a+n+1);
		priority_queue<LL,vector<LL>,greater<LL> > pq;
		int pos=-1;
		for (int x=1;n>=x;x++) {
			if (a[x].first >= v[1] && a[x].second != 1) {
				pq.push(w[ a[x].second ] - v[ a[x].second ] + 1);
			}
			else if (a[x].second == 1) {
				pos=x;
			}
		}
		
//		cout<<"ori best = "<<best<<endl;
		LL ret=v[1];
		int rank=best;
//		cout<<"in\n";
		while (!pq.empty()) {
//			cout<<"sz = "<<pq.size()<<endl;
			LL i=pq.top();
			pq.pop();
//			cout<<"i = "<<i<<" , ret = "<<ret<<" , pos = "<<pos<<endl;
			if (i > ret) break;
			LL before=ret;
			ret -= i;
			rank--;
			for (int x=pos;x>=1;x--) {
				if (a[x].first > ret && a[x].second != 1) {
					rank++;
					if (a[x].first != before)pq.push(w[ a[x].second ] - v[ a[x].second ] + 1);
					swap(a[x],a[pos]);
					pos=x;
				}
				else if (a[x].first == ret && a[x].second != 1) {
					pq.push(w[ a[x].second ] - v[ a[x].second ] + 1);
				}
				else if (a[x].second != 1)break;
			}
			best = min(best,rank);
//			cout<<"after do rank = "<<rank<<endl;
		}
		printf("%d\n",best);
	}
}