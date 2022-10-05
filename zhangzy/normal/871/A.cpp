#include<bits/stdc++.h>
using namespace std;

int T,n;
int main(){
	for (scanf("%d",&T);T--;){
		scanf("%d",&n);
		if (n&1){
			if (n<9||n==11){
				printf("-1\n");
			}else{
				printf("%d\n",(n-9)/4+1);
			}
		}else{
			if (n<4){
				printf("-1\n");
			}else{
				printf("%d\n",n/4);
			}
		}
	}
}