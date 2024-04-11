#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int a,b,n;
		scanf("%d%d%d",&a,&b,&n);
		if(a<b)swap(a,b);
		int ret=0;
		while(a<=n){
			swap(a,b);
			a+=b;
			ret++;
		}
		printf("%d\n",ret);
	}
}