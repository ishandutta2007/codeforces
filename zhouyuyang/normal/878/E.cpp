#include<bits/stdc++.h>
#define mo 1000000007
#define N 100005
using namespace std;
int f[N],pre[N],v[N],s[N],n,m;
int sum[N],ans[N],P[N],sp[N];
vector<pair<int,int> > q[N]; 
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
void merge(int a,int b){
	if ((a-pre[a]>31&&sum[b]>0)||
		sum[a]+((1ll*sum[b])<<(a-pre[a]))>mo)
			sum[b]=mo;
	else sum[b]=sum[a]+(sum[b]<<(a-pre[a]));
	f[a]=f[b]; pre[b]=pre[a];
}
int ask(int a,int b){
	return (s[a]-1ll*s[b+1]*P[b-a+1]%mo+mo)%mo;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=P[0]=1;i<=n;i++){
		f[i]=i; pre[i]=i-1;
		scanf("%d",&v[i]); P[i]=P[i-1]*2%mo;
	}
	for (int i=n;i;i--)
		s[i]=(1ll*s[i+1]*2+v[i]+mo)%mo;
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		q[r].push_back(make_pair(l,i));
	}
	for (int i=1;i<=n;i++){
		sum[i]=v[i];
		while (pre[i]&&sum[i]>=0) merge(pre[i],i);
		sp[i]=(sp[pre[i]]+2ll*ask(pre[i]+1,i))%mo;
		for (int j=0;j<q[i].size();j++){
			int a=q[i][j].first,b=get(a);
			ans[q[i][j].second]=(sp[i]-sp[b]+mo+1ll*ask(a,b))%mo;
		}
	}
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}