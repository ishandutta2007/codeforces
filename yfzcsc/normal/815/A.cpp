#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int a[110][110],b[110][110],n,m,mn[110],flag,ans;
int solve1(){
	int ans=0;
	flag=0;
	for(int i=1;i<=m;++i){
		mn[i]=inf;
		for(int j=1;j<=n;++j)
			mn[i]=min(mn[i],a[j][i]);
	}
	for(int i=1;i<=n;++i){
		int p=mn[1]-a[i][1];
		for(int j=1;j<=m;++j)
			if(mn[j]-a[i][j]!=p)return inf;
		for(int j=1;j<=m;++j)
			if(mn[j]!=a[i][j])goto end;
		
		flag=i;
		end:;
	}
	if(!flag)return inf;
	for(int i=1;i<=n;++i){
		int p=a[i][1]-mn[1];
		ans+=p;
	}
	for(int i=1;i<=m;++i)ans+=mn[i];
	return ans;
}
int solve2(){
	int ans=0;
	flag=0;
	int n=::n,m=::m;
	swap(n,m);
	for(int i=1;i<=m;++i){
		mn[i]=inf;
		for(int j=1;j<=n;++j)
			mn[i]=min(mn[i],b[j][i]);
	}
	for(int i=1;i<=n;++i){
		int p=mn[1]-b[i][1];
		for(int j=1;j<=m;++j)
			if(mn[j]-b[i][j]!=p)return inf;
		for(int j=1;j<=m;++j)
			if(mn[j]!=b[i][j])goto end;
		
		flag=i;
		end:;
	}
	if(!flag)return inf;
	for(int i=1;i<=n;++i){
		int p=b[i][1]-mn[1];
		ans+=p;
	}
	for(int i=1;i<=m;++i)ans+=mn[i];
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]),b[j][i]=a[i][j];
	int ans1=solve1(),ans2=solve2();
	if(ans1>=inf&&ans2>=inf)return puts("-1"),0;
	if(ans1<ans2){
		printf("%d\n",ans1);
		for(int i=1;i<=m;++i){
			mn[i]=inf;
			for(int j=1;j<=n;++j)
				mn[i]=min(mn[i],a[j][i]);
		}
		for(int i=1;i<=n;++i){
			int p=a[i][1]-mn[1];
			for(int j=1;j<=p;++j)
				printf("row %d\n",i);
		}
		
		for(int i=1;i<=m;++i)
			for(int j=1;j<=mn[i];++j)
				printf("col %d\n",i);
	} else {
		
		printf("%d\n",ans2);
		for(int i=1;i<=n;++i){
			mn[i]=inf;
			for(int j=1;j<=m;++j)
				mn[i]=min(mn[i],b[j][i]);
		}
		for(int i=1;i<=m;++i){
			int p=b[i][1]-mn[1];
			for(int j=1;j<=p;++j)
				printf("col %d\n",i);
		}
		
		for(int i=1;i<=n;++i)
			for(int j=1;j<=mn[i];++j)
				printf("row %d\n",i);
	}
}