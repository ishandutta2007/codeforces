#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;cin>>n>>k;
	int rest=240-k,a=0;
	for(int i=1;i<=n;++i){
		if(rest<5*i)break;
		rest-=5*i,a++;
	}
	printf("%d",a);
}