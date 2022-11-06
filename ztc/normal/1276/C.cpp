#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
int a[1000002],s[1000002],n,m=0,l=0,c=0;
std::pair<int,int>t[1000002];
std::vector<std::vector<int> >ans;
inline int Min(int a,int b){return a<b?a:b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);a[0]=-1e9;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])t[++m]=std::make_pair(0,a[i]);
		t[m].first++;
	}std::sort(t+1,t+m+1);
	for(int i=1;i<=m;i++)s[i]=s[i-1]+t[i].first;
	for(int i=1,k=0;i*i<=n;i++){
		while(k<m&&t[k+1].first<i)k++;
		for(int j=i;i*j<=n;j++)if(i*j>l*c){
			if(s[k]+(m-k)*i>=i*j)l=i,c=j;
		}
	}printf("%d\n%d %d\n",l*c,l,c);
	ans.resize(l+2);
	for(int i=1;i<=l;i++)ans[i].resize(c+2);
	for(int j=1,p=m;j<=c;j++){
		for(int i=1;i<=l;i++){
			if(ans[i][j-1]==t[p].second||t[p].first==0)p--;
			ans[i][j]=t[p].second;t[p].first--;
		}
	}for(int i=1;i<=l;i++){
		for(int j=1;j<=c;j++)printf("%d ",ans[i][(j+n-i)%c+1]);
		puts("");
	}
}