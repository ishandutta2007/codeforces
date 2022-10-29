#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	int n,x;
	while (cin >> n >> x) {
		int now=1;
		int ans=0;
		for (int i=0;n>i;i++) {
			int l,r;
			cin >> l >> r;
			int tmp=(l-now)/x;
			tmp*=x;
//			cout<<"tmp = "<<tmp<<" , now = "<<now<<endl;
			ans += (l-now-tmp);
			ans += (r-l+1);
			now=r+1;
		}
		cout<<ans<<endl;
	}
}