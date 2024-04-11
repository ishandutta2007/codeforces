#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
char c[N];
int n,i,j;
long long ans;
bool ck(int l,int r){
	for(int i=l;i<r;++i)for(int j=1;i+j*2<=r;++j)if(c[i]==c[i+j] && c[i]==c[i+j*2])
		return 1;
	return 0;
}
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=j=1;i<=n;++i){
		for(;ck(j,i);++j);
		ans+=j-1;
	}
	printf("%lld\n",ans);
	return 0;
}