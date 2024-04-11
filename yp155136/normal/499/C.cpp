#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 306;

LL a[MAX_N],b[MAX_N],c[MAX_N];

int main () {
	LL x1,x2,y1,y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		int n;
		cin >>n;
		int ans=0;
		for (int i=0;n>i;i++) {
			cin >>a[i] >>b[i]>>c[i];
			LL _ = a[i]*x1 + b[i]*y1 + c[i];
			LL __= a[i]*x2 + b[i]*y2 + c[i];
			if (_>0) _ =1;
			else _=-1;
			if (__>0) __=1;
			else __=-1;
			ans += !(_==__);
		}
		cout<<ans<<endl;
	}
}