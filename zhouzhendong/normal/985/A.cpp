#include <bits/stdc++.h>
using namespace std;
int n,p[100],ans1,ans2;
int main(){
	scanf("%d",&n);
	ans1=ans2=0;
	for (int i=1;i<=n/2;i++){
		scanf("%d",&p[i]);
	}
	sort(p+1,p+n/2+1);
	
	for (int i=1;i<=n/2;i++){
		ans1+=abs(p[i]-(i*2-1));
		ans2+=abs(p[i]-(i*2));
	}
	printf("%d",min(ans1,ans2));
	return 0;
}