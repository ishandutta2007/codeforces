#include<bits/stdc++.h> 
int a[]={0,4,10,20,35,56,83,116,155,198,244,292};
int main(){
	int n;
	scanf("%d",&n);
	if(n<=11)printf("%d\n",a[n]);
		else std::cout<<1ll*(n-11)*49+a[11]<<'\n';
	return 0;
}