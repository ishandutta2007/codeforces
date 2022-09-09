#include<bits/stdc++.h>
using namespace std;
int T,n,a,i,x;
int main(){
	for(scanf("%d",&T);T--;){
		map<int,int>mp;
		scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",&x),++mp[x];
		printf("%d\n",mp.size()==1?n:1);
	}
}