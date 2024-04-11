#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;
const LL INF = 1e15 + 6;

LL a[MAX_N];
LL b[MAX_N];

int main () {
	int n,q;
	while (scanf("%d %d",&n,&q) != EOF) {
		for(int i=1;n>=i;i++) {
			scanf("%I64d",&b[i]);
			if (i>1) a[i] = abs(b[i]-b[i-1]);
		}
		while (q--) {
			int L,R;
			scanf("%d %d",&L,&R);
			L++;
			deque<pii> dq;
			dq.push_back(make_pair(INF,L-1));
			LL ans=0;
			for (LL i=L;R+1>=i;i++) {
				LL add=a[i];
				if (i==R+1) add=INF;
				while (dq.size()>0 && add>dq[dq.size()-1].first) {
					ans += ((i-dq[dq.size()-1].second)*(dq[dq.size()-1].second-dq[dq.size()-2].second))*(dq[dq.size()-1].first);
					dq.pop_back();
				}
				dq.push_back(make_pair(add,i));
//				cout<<"i = "<<i<<" , ans = "<<ans<<endl;
			}
			printf("%I64d\n",ans);
		}
	}
}