#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x=0;
	scanf("%d",&n);
	if(n==1){
		puts("1");
	} else {
		int mn=1<<30;
		for(int i=1;i<=n;++i)
			if(mn>i+(n+i-1)/i)
				mn=i+(n+i-1)/i,x=i;
		int lst=n;
		for(int i=1;i<=n;i+=x){
			int rest=min(x,n-i+1);
			for(int j=lst-rest+1;j<=lst;++j)printf("%d ",j);
			lst-=rest;
		}
	}
}