#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main(void) {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		if(n%m==0) printf("YES\n");// 
		else printf("NO\n");
	}
	return 0;
}