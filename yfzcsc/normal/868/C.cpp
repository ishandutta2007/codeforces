#define _GLIBCXX_IOSTREAM
#include<bits/stdc++.h>
using namespace std;
int n,k,a[100100],mx,c[1000];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		for(int j=1,x;j<=k;++j)
			scanf("%d",&x),a[i]|=(x<<j-1);
		c[a[i]]++,mx=max(mx,a[i]);
	}
	for(int i=0;i<=mx;++i)if(c[i])
		for(int j=0;j<=mx;++j)if(c[j])
			if(!(i&j))return printf("YES"),0;
	printf("NO");
}