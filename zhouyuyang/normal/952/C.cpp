#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y;
	bool pd =true;
	scanf("%d",&n);
	scanf("%d",&x);
	for (int i = 2; i <= n; i++){
		scanf("%d",&y);
		if (abs(x - y) > 1) pd = false;
		x = y;
	}
	if (pd) printf("YES\n");
	else printf("NO\n");
}