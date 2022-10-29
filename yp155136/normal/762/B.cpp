#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int a,b,c;
	while (scanf("%d %d %d",&a,&b,&c) != EOF) {
		int n;
		scanf("%d",&n);
		vector<int> p,q;
		for (int x=0;n>x;x++) {
			int i;
			string j;
			cin >>i >> j;
			if (j=="USB") {
				p.push_back(i);
			}
			else {
				q.push_back(i);
			}
		}
		sort(p.begin(),p.end());
		sort(q.begin(),q.end());
		int cnt=0;
		long long ans=0;
		int id1=0,id2=0;
		int sz1=p.size(),sz2=q.size();
		for (;sz1>id1&&a>0;id1++,a--) {
			cnt++;
			ans+=p[id1];
		}
		for (;sz2>id2&&b>0;id2++,b--) {
			cnt++;
			ans+=q[id2];
		}
		while (c>0) {
			c--;
			if (sz1==id1 && id2==sz2) break;
			if (id2==sz2) {
				cnt++;
				ans+=p[id1++];
			}
			else if (id1==sz1) {
				cnt++;
				ans+=q[id2++];
			}
			else if (p[id1]>q[id2]) {
				cnt++;
				ans += q[id2++];
			}
			else {
				cnt++;
				ans += p[id1++];
			}
		}
		cout<<cnt<<' '<<ans<<endl;
	}
}