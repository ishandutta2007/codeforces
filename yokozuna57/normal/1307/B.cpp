#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n,x;
		int a[100010];
		scanf("%d%d",&n,&x);
		for(int i = 0 ; i < n ; i ++){
			scanf("%d",&a[i]);
		}
		int ret = -1;
		int MAX = 0;
		for(int i = 0 ; i < n ; i ++){
			if(a[i] == x)ret = 1;
			MAX = max( MAX , a[i] );
		}
		if(ret == -1){
			ret = max( 2 , (x+MAX-1)/MAX );
		}
		printf("%d\n",ret);
	}
}