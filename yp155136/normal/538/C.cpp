#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

const int MAX_N = 1e5 +6;

int p[MAX_N],q[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int mx=-1;
		bool can=true;
		for (int i=1;m>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			mx = max(mx,b);
			if (i==1) {
				mx = max(mx,b+(a-1));
			}
			if (i==m) {
				mx = max(mx,b+(n-a));
			}
			if (i>1) {
				int day_delta=a-p[i-1];
				int dis_delta=abs(b-q[i-1]);
				if (day_delta < dis_delta) can=0;
				mx = max(mx,max(b,q[i-1])+(day_delta-dis_delta)/2);
			}
			p[i]=a;
			q[i]=b;
		}
		if (!can) cout<<"IMPOSSIBLE"<<endl;
		else cout<<mx<<endl;
	}
}