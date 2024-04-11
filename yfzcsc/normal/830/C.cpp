#include<bits/stdc++.h>
#include<tr1/unordered_set>
#define maxn 1100
#define maxm 5001000
using namespace std;
typedef long long ll;
int a[maxn],n,p[maxm],psz;
long long k,tg[maxm],jian;
tr1::unordered_set<int>st;
int main(){
	//int qqp=clock();
//	freopen("B.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),jian+=a[i],a[i]--;
	for(int i=1;i<=n;++i)
		for(int j=1,pos;j<=a[i];j=pos+1){
			pos=a[i]/(a[i]/j);
			if(!st.count(pos))p[++psz]=pos,st.insert(pos);//,(psz%100000==0?printf("[%d]",psz):0);
		}
	sort(p+1,p+psz+1);
	for(int i=1;i<=n;++i)
		for(int j=1,pos,bg=1;j<=a[i];j=pos+1){
			pos=a[i]/(a[i]/j);
			int x=lower_bound(p+bg,p+psz+1,j)-p;
			int y=lower_bound(p+bg,p+psz+1,pos+1)-p;
			bg=y;
			tg[x]+=a[i]/j;
			tg[y]-=a[i]/j;
		}
	long long sum=0,ans=0;
	for(int i=1;i<=psz;++i){
		sum+=tg[i];
		long long x=(k+jian)/(sum+n);
	//	printf("[%d,%I64d,%I64d]",p[i],sum,x);
		if(p[i-1]+1<=x&&(i==psz||x<p[i+1]))
			ans=x;
	}
	long long x=(k+jian)/n;
	if(x>p[psz])ans=max(ans,x);
	cout<<ans;
//	cerr<<"used time:"<<((double)clock()-qqp)/(double)CLOCKS_PER_SEC;
}