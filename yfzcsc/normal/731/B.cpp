#include<bits/stdc++.h>
using namespace std;
int a[200100],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<n;++i)if(a[i]&1){
		if(a[i+1]==0){
			printf("NO");
			return 0;
		} else a[i+1]--;
	}
	if(a[n]&1)printf("NO");
	else printf("YES");
		
}