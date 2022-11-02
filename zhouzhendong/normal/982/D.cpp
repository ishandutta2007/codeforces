#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],id[N],hs,ans[N];
int tax[N],tot,all;
int t[N];
bool cmp(int aa,int bb){
	return a[aa]<a[bb];
}
void add(int x,int d){
	for (;x<=n;x+=x&-x)
		t[x]+=d;
}
int sum(int x){
	int ans=0;
	for (;x>0;x-=x&-x)
		ans+=t[x];
	return ans;
}
void adtax(int x,int t){
	if (x==0)
		return;
	if (t==1){
		if (tax[x]==0)
			tot++;
		tax[x]++;
	}
	else {
		tax[x]--;
		if (tax[x]==0)
			tot--;
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	tax[n]++,tot=all=1;
	for (int i=n;i>=1;i--){
		int pos=id[i],L=pos,R=pos,v=sum(pos);
		for (int j=19;j>=0;j--)
			if (L-(1<<j)>0&&sum(L-(1<<j))==v)
				L-=1<<j;
		for (int j=19;j>=0;j--)
			if (R+(1<<j)<=n&&sum(R+(1<<j))==v)
				R+=1<<j;
		adtax(R-L+1,-1);
		adtax(pos-L,1);
		adtax(R-pos,1);
		add(pos,1);
		add(pos+1,1);
		all--;
		if (L!=pos)
			all++;
		if (R!=pos)
			all++;
		if (tot==1){
			ans[i]=all;
		}
	}
	int res=1;
	for (int i=2;i<=n;i++)
		if (ans[i]>ans[res]||(ans[i]==ans[res]&&a[id[i]]<a[id[res]]))
			res=i;
	if (ans[res]==0)
		printf("%d",a[id[n]]+1);
	else 
		printf("%d",a[id[res-1]]+1);
	return 0;
}