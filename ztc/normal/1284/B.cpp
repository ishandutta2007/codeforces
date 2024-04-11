#include<stdio.h>
#include<algorithm>
#include<vector>
int n,cnt=0,top=0,g[100002],c[1000002];
std::pair<int,int>a[100002];
long long ans=0;
void add(int p){
	while(p<=1e6+1)c[p]++,p+=p&-p;
}
int get(int p){
	int cnt=0;
	while(p)cnt+=c[p],p-=p&-p;return cnt;
}
int main(){
	scanf("%d",&n);ans=1ll*n*n;
	while(n--){
		int m;scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d",&g[i]),g[i]++;
		bool f=0;
		for(int i=1;i<m;i++)f|=g[i]<g[i+1];
		if(f)cnt++;
		else{
			top++;
			a[top].first=g[m];
			a[top].second=g[1];
		}
	}std::sort(a+1,a+top+1);
	for(int i=1;i<=top;i++){
		add(a[i].second);
	}for(int i=1;i<=top;i++){
		ans-=get(a[i].first);
	}printf("%lld",ans);
}