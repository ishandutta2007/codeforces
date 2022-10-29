#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2006;

pii operator-(const pii &p1,const pii &p2) {
	return make_pair(p1.first-p2.first,p1.second-p2.second);
}

pii a[MAX_N];
map<pii,int> mp;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		mp.clear();
		for (int i=1;n>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			a[i] = make_pair(x,y);
		}
		sort(a+1,a+n+1);
		for (int i=1;n>=i;i++) {
			for (int j=i+1;n>=j;j++) {
				mp[a[i]-a[j]]++;
			}
		}
		long long ans=0;
		for (int i=1;n>=i;i++) {
			for (int j=i+1;n>=j;j++) {
				long long tmp=mp[a[i]-a[j]];
				if (tmp) mp[a[i]-a[j]]=0;
				ans += (tmp)*(tmp-1)/2;
			}
		}
		printf("%I64d\n",ans/2);
	}
}