#include<bits/stdc++.h>
int n,b,s,a,mx;
int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%d",&b);
		a=mx+b;mx=std::max(mx,a);
		printf("%d ",a);
	}
	puts("");
}