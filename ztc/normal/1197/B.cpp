#include<stdio.h>
#include<algorithm>
int a,b,n,f=0;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a<b)f=1;
		if(f&&a>b)return printf("NO")&0;
		b=a;
	}printf("YES");
}