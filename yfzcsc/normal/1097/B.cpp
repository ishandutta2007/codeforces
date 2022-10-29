#include<bits/stdc++.h>
using namespace std;
int n,a[20];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);++i){
		int sum=0;
		for(int j=1;j<=n;++j)
			if(i>>j-1&1)sum+=a[j];
			else sum-=a[j];
		if(sum%360==0){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}