#include <bits/stdc++.h>
using namespace std;

int n;

int solve(){
	int ret;
	for(int i=1;;i++){
		if(i*(i+1)/2>=n){
			if(n==i*(i+1)/2-1)ret=i+1;
			else ret=i;
			return ret;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		scanf("%d",&n);
		printf("%d\n",solve());
	}
}