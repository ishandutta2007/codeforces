#include<bits/stdc++.h>
using namespace std;
#define db double

int n;
db a[111];

int main(){
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,greater<db>());
	db p0=1, p1=0;
	for (int i=1;i<=n;++i){
		db p=a[i];
		if (p*p0+(1-p)*p1>p1){
			p1=p*p0+(1-p)*p1;
			p0*=1-p;
		}
	}
	printf("%.15lf\n",p1);
}