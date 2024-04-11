#include <bits/stdc++.h>
using namespace std;
int n,k;
void connect(int a,int b){
	printf("%d %d\n",a,b);
	printf("%d %d\n",n*2+1-a,n*2+1-b);
}
int main(){
	scanf("%d",&k);
	if (k==1)
		printf("YES\n2 1\n1 2");
	else if (k%2==0)
		puts("NO");
	else {
		puts("YES");
		n=k+2;
		printf("%d %d\n",n*2,n*k);
		for (int i=1;i<=k-1;i++){
			connect(i,k);
			connect(i,k+1);
			connect(i,k+2);
		}
		connect(k+1,k);
		for (int i=1;i<=k-1;i++)
			for (int j=1;j<=(k-3)/2;j++)
				connect(i,(i+j-1)%(k-1)+1);
		printf("%d %d",n,n+1);
	}
	return 0;
}