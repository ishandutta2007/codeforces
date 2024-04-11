#include<bits/stdc++.h>
using namespace std;

int n,x,used[301000],p;

int main(){
	scanf("%d",&n);
	p=n+1;
	printf("1 ");
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		used[x]=1;
		while (used[p-1]) p--;
		printf("%d ",i-(n-p));
	}
}