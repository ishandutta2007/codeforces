#include<stdio.h>
#include<algorithm>
#include<vector>
bool a[1022][1022];
int n,m=0;
std::pair<int,int>t[1022];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i].first);
		t[i].second=i;
	}std::sort(t+1,t+n+1,std::greater<std::pair<int,int> >());
	for(int i=1;i<=n;i++){
		for(int j=i;t[i].first;j>=n+1?(j=1):j++,t[i].first--){
			a[j][t[i].second]=1;
		}
	}printf("%d\n",n+1);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++)printf("%d",a[i][j]);
		puts("");
	}
}