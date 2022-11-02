#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	LL ans=0;
	LL v1=1.0*n*(n-1)/2;
	LL v2=(n&1)?(1.0*(n/2)*(n/2+1)):(1.0*(n/2)*(n/2));
	while (m--){
		int x,d;
		scanf("%d%d",&x,&d);
		ans+=1LL*x*n;
		if (d>=0)
			ans+=v1*d;
		else
			ans+=v2*d;
	}
	printf("%.10lf",1.0*ans/n);
	return 0;
}