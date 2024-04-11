#include <bits/stdc++.h>
using namespace std;

int solve(int x,int y){
	if(x==y)return x+y;
	return 2*max(x,y)-1;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",solve(a,b));
	}
}