#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m);
	if (n==1) printf("%d",m/6*6+(m%6>3?m%6-3:0)*2);
	else if (n==2) printf("%lld",1ll*n*m-(m==3||m==7?2:(m==2?4:0)));
	else printf("%lld",1ll*n*m-((n&1)&&(m&1)));
}