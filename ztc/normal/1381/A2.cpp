#include<stdio.h>
#include<vector>
char c[100002],d[100002];
int n,t;
std::vector<int>ans;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s%s",&n,c+1,d+1);ans.clear();
//		for(int i=n;i;i--){
//			if(d[i]==c[n-i+1])ans.push_back(1);
//			ans.push_back(i);
//			if(i!=1)ans.push_back(i-1);
//		}
		int l=1,r=n;
		for(int i=n;i>=2;i-=2){
			if(d[i]==c[l])ans.push_back(1);
			ans.push_back(r-l+1);l++;
			if(d[i-1]!=c[r])ans.push_back(1);
			ans.push_back(r-l+1);r--;
		}if((n&1)&&c[l]!=d[1])ans.push_back(1);
		printf("%d\n",ans.size());
		for(int i:ans)printf("%d ",i);puts("");
	}
}