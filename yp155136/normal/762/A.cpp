#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;

int main () {
	long long n,k;
	while (scanf("%I64d %I64d",&n,&k) != EOF) {
		LL tmp=sqrt(n);
		//cout<<"tmp = "<<tmp<<endl;
		vector<LL> v;
		vector<LL> q;
		for (int i=1;tmp>=i;i++) {
			if (n%i==0) {
				v.push_back(i);
				if (LL(i)*i!=n) q.push_back(n/i);
			}
		}
		LL ans=-1;
		int sz=v.size();
		for (int x=0;sz>x;x++) {
			k--;
			if (k==0) ans=v[x];
		}
		sz=q.size();
		for (int x=sz-1;x>=0;x--) {
			k--;
			if (k==0) ans=q[x];
		}
		printf("%I64d\n",ans);
	}
}