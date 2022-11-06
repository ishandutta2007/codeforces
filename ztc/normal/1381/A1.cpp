#include<stdio.h>
#include<vector>
char c[100002],d[100002];
int n,t;
std::vector<int>ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s%s",&n,c+1,d+1);ans.clear();
		for(int i=n;i;i--){
			if(d[i]==c[n-i+1])ans.push_back(1);
			ans.push_back(i);
			if(i!=1)ans.push_back(i-1);
		}printf("%d\n",ans.size());
		for(int i:ans)printf("%d ",i);puts("");
	}
}