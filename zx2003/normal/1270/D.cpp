#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,x,y;
map<int,int>mp;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=k+1;++i){
		printf("? ");for(j=1;j<=k+1;++j)if(i!=j)printf("%d ",j);puts("");fflush(stdout);
		scanf("%d%d",&x,&y);++mp[y];
	}
	printf("! %d\n",mp.rbegin()->second);fflush(stdout);
	return 0;
}