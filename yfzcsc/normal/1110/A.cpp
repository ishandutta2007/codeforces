#include<bits/stdc++.h>
using namespace std;
int b,k;
int main(){
	scanf("%d%d",&b,&k);
	int ans=0;
	for(int i=1;i<=k;++i){
		int x;
		scanf("%d",&x);
		ans=(ans*b+x)%2;
	}
	puts(~ans&1?"even":"odd");
}