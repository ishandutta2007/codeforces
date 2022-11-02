#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
char s[N];
int main(){
	scanf("%s",s+2);
	n=strlen(s+2);
	for (int i=2;i<=n+1;i++)
		a[i]=s[i]-'0';
	a[0]=a[1]=0;
	for (int i=0;i<=n+1;i++)
		for (int j=i+1;j<=n+1;j++)
			for (int k=j+1;k<=n+1;k++){
				int v=a[i]*100+a[j]*10+a[k];
				if (v%8==0){
					printf("YES\n%d",v);
					return 0;
				}
			}
	puts("NO");
	return 0;
}