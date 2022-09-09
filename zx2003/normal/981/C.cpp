#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,deg[N],x,y,i;
vector<pair<int,int> >ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		++deg[x];++deg[y];
	}
	int cnt=0;
	for(i=1;i<=n;++i)if(deg[i]>2)++cnt,x=i;
	if(cnt>1){
		puts("No");
		return 0;
	}
	puts("Yes");
	if(cnt){
		int lst=0;
		for(i=1;i<=n;++i)if(deg[i]==1){
			if(lst)ans.push_back(make_pair(lst,i)),lst=0;
				else lst=i;
		}
		if(lst)ans.push_back(make_pair(lst,x));
	}else{
		x=y=0;
		for(i=1;i<=n;++i)
			if(deg[i]==1){
				if(x)y=i;else x=i;
			}
		ans.push_back(make_pair(x,y));
	}
	printf("%d\n",int(ans.size()));
	for(i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}