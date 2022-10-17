#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n,d;
		int a[102];
		scanf("%d%d",&n,&d);
		for(int i = 0 ; i < n ; i ++){
			scanf("%d",&a[i]);
		}
		int ret = a[0];
		for(int i = 1 ; i < n ; i ++){
			while(d >= i && a[i] > 0){
				ret ++;
				d -= i;
				a[i] --;
			}
		}
		printf("%d\n",ret);
	}
}