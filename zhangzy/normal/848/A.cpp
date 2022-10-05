#include<bits/stdc++.h>
using namespace std;
int k,f[10010];

int main(){
	f[1]=0;
	for (int i=2;i<=10000;i++){
		f[i]=f[i-1]+i-1;
	}
	scanf("%d",&k);
	printf("a");
	char now='b';
	for (;k;now++){
		for (int i=1;1;i++){
			if (k>=f[i]&&k<f[i+1]){
				k-=f[i];
				for (int j=1;j<=i;j++){
					printf("%c",now);
				}
				break;
			}
		}
	}
}