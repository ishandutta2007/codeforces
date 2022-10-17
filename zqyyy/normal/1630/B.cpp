#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,K,a[N],cnt[N];
int pre[N],lst[N];
inline void work(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]]++;
	int x=0,y=0,mn=1e9;
	for(int l=1,r=0,sum=0;l<=n;sum-=cnt[l++]){
		while(r<n && sum-(n-sum)<K)sum+=cnt[++r];
		if(r-l<mn && sum-(n-sum)>=K)x=l,y=r,mn=r-l;
	}
	printf("%d %d\n",x,y);
	int sum=0;
	vector<pair<int,int> >ans;
	for(int i=1;i<=n;i++){
		sum+=x<=a[i] && a[i]<=y?1:-1;
		if(sum>0)pre[i]=lst[sum-1],lst[sum]=i;
	}
	for(int i=n;i;i=pre[i])ans.push_back({pre[i]+1,i});
	reverse(ans.begin(),ans.end());
	for(int i=0;i<K-1;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	printf("%d %d\n",ans[K-1].first,n);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
	return 0;
}