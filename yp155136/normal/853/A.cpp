#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 3e5 + 6;

LL c[MAX_N];
int p[MAX_N];

int main () {
	int n,k;
	scanf("%d %d",&n,&k);
	LL ans=0;
	for (int i=1;n>=i;i++) {
		scanf("%lld",&c[i]);
		ans += (-i)*c[i];
	}
	priority_queue<pii> pq;
	for (int i=1;k+1>=i;i++) {
		pq.push(make_pair(c[i],i));
	}
	for (int i=1;n>=i;i++) {
		pii pp=pq.top();
		pq.pop();
//		cout<<"i = "<<i<<" , add = "<<i+k<<"*"<<pp.first<<endl;
		ans += pp.first*(i+k);
		p[pp.second] = i+k;
		if (i+k+1 <= n) pq.push(make_pair(c[i+k+1],i+k+1));
	}
	printf("%lld\n",ans);
	for(int i=1;n>=i;i++) {
		if (i!=1) printf(" ");
		printf("%d",p[i]);
	}
	puts("");
}