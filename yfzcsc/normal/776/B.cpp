#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	if(n<3)printf("1\n");
	else printf("2\n");
	for(int i=2;i<=n+1;++i){
		for(int j=2;1ll*j*j<=i;++j)if(i%j==0){
			printf("2 ");goto end;
		}
		printf("1 ");
		end:;
	}
}