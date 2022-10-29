#include<vector>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 100100
#define inf (1<<30)
using namespace std;
typedef pair<int,int> data;
struct query{
	int l,r,id;
	int operator<(const query& q)const{
		return r>q.r;
	}
};
vector<query>v[320];
int kuai,f[maxn],a[maxn],n,m,pred[maxn],succ[maxn],dp[320][maxn],anses[maxn],s[maxn];
data b[maxn];
void reset(){
	for(int i=1;i<=n;++i)pred[i]=i-1,succ[i]=i+1;
	pred[n+1]=n,succ[0]=1;
}
void del(int x){
//	printf("del:%d,%d\n",x,s[x]);
	pred[succ[x]]=pred[x];
	succ[pred[x]]=succ[x];
}
int ins(int x){
	int ans=inf;
	if(pred[x])ans=min(ans,abs(s[pred[x]]-s[x]));
	if(succ[x]<=n)ans=min(ans,abs(s[succ[x]]-s[x]));
//	printf("ins:%d,%d\n",x,s[x]);
	pred[succ[x]]=x;succ[pred[x]]=x;
	return ans;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),b[i]=data(a[i],i);
	scanf("%d",&m);
	kuai=sqrt(n)+1;
	for(int i=1;i<=n;++i)dp[1][i]=inf;
	for(int i=2;i<=kuai;++i)
		for(int j=1;i+j-1<=n;++j)
			dp[i][j]=min(min(dp[i-1][j],dp[i-1][j+1]),abs(a[i+j-1]-a[j])); 
	for(int i=1;i<=m;++i){
		query q;
		scanf("%d%d",&q.l,&q.r),q.id=i;
		if(q.r-q.l+1<=kuai)anses[q.id]=dp[q.r-q.l+1][q.l];
		else v[q.l/kuai].push_back(q);
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)a[b[i].second]=i,s[i]=b[i].first;
	for(int i=0;i<=kuai;++i){
		if(v[i].empty())continue;
		reset();
		int l=i*kuai,r=l+kuai-1;
		for(int j=1;j<r;++j)del(a[j]);
		for(int j=n;j>r;--j)del(a[j]);
		f[r]=inf;
		for(int j=r+1;j<=n;++j)f[j]=min(f[j-1],ins(a[j]));
		for(int j=r-1;j>=l;--j)ins(a[j]);
		sort(v[i].begin(),v[i].end());
//		printf("[%d,%d]\n",f[9],f[10]);
		for(int j=0,k=n;j<v[i].size();++j){
			query q=v[i][j];
			while(k>q.r)del(a[k--]);
			int ans=f[k];
			for(int i=l;i<r;++i)del(a[i]);
//			puts("begin");
			for(int i=r-1;i>=q.l;--i)ans=min(ans,ins(a[i]));
//			puts("end.");
//			printf("{%d,%d}",l,q.l);
			for(int i=q.l-1;i>=l;--i)ins(a[i]);
			anses[q.id]=ans;
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",anses[i]);
}