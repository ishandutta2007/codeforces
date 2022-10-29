#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e7 + 6;

LL a[MAX_N];

LL id;

LL l,r;

LL ans;

void f(LL x) {
//	cout<<"x = "<<x<<endl;
	if (x<=1) {
		
		if (l<=id && id<=r) ans+=x;
		id++;
		return;
	}
	LL st_id = id;
	f(x/2);
	LL last_id = id;
	if (l<=id && id<=r) ans+=x%2;
	int num=last_id - st_id;
	while (num--) {
		id++;
	}
}

LL pow(LL a,LL n) {
	LL ret=1;
	for (int x=0;n>x;x++) ret*=a;
	return ret;
}

int main () {
	LL n;
	while (cin >> n >> l >>r) {
		if (n==0 || n==1) {
			if (n==0) cout<<0<<endl;
			else cout<<1<<endl;
			continue;
		}
		id=1;
		LL ans=0;
		LL id=0;
		while (pow(2,id) <= n) id++;
		id--;
		for (LL i=l;r>=i;i++) {
			LL lowbit=i&(-i);
			LL tmp=0;
			while (lowbit!=pow(2,tmp)) tmp++;
//			cout<<"tmp = "<<tmp<<" , lowbit = "<<lowbit<<" , id = "<<id<<endl;
			ans += (n/pow(2,id-tmp))%2;
		}
		cout<<ans<<endl;
	}
}