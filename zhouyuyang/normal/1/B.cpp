#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
char a[30],b[30];
int n,l,i,x,y,j;
int main(){
	scanf("%d",&n);
	for (int j=1;j<=n;j++){
		scanf("%s",&a);
		l=strlen(a);
		i=x=y=0;
		while (i<l&&a[i]>'9'){
			x=x*26+a[i]-'A'+1;
			i++;
		}
		while (i<l&&a[i]<='9'){
			y=y*10+a[i]-'0';
			i++;
		}
		if (i==l){
			printf("R%dC%d\n",y,x);
			continue;
		}
		i++;
		x=0;
		while (i<l){
			x=x*10+a[i]-'0';
			i++;
		}
		i=0;
		while (x!=0){
			i++;
			b[i]='A'+(x-1)%26;
			x=(x-1)/26;
		}
		for (;i;i--) printf("%c",b[i]);
		printf("%d\n",y);
	}
	return 0;
}