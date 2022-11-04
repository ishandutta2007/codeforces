#include<bits/stdc++.h>
#define N 200005
using namespace std;
int s1[N*4],s2[N*4],n,T,ans;
struct jdb{int t,v,id;}a[N];
vector<int> vec[N];
bool cmp(jdb a,jdb b){
	return a.v<b.v;
}
void build(int k,int l,int r){
	if (l==r){
		s1[k]=a[l].v;
		s2[k]=1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	s1[k]=s1[k*2]+s1[k*2+1];
	s2[k]=s2[k*2]+s2[k*2+1];
}
void change(int k,int l,int r,int p){
	if (l==r){
		s1[k]=s2[k]=0;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	s1[k]=s1[k*2]+s1[k*2+1];
	s2[k]=s2[k*2]+s2[k*2+1]; 
}
int ask(int k,int l,int r,int v){
	if (l==r){
		return v>=s1[k]?s2[k]:0;
	}
	int mid=(l+r)/2;
	if (s1[k*2]<=v)
		return s2[k*2]+ask(k*2+1,mid+1,r,v-s1[k*2]);
	return ask(k*2,l,mid,v);
}
int main(){
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].t,&a[i].v),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
		vec[a[i].t].push_back(i);
	build(1,1,n);
	int jdb=0;
	for (int i=1;i<=n;i++){
		int tmp=ask(1,1,n,T);
		tmp=min(tmp,i);
		if (tmp>ans)
			ans=tmp,jdb=i;
		for (int j=0;j<vec[i].size();j++)
			change(1,1,n,vec[i][j]);
	}
	printf("%d\n%d\n",ans,ans);
	for (int i=1,tmp=0;i<=n&&tmp<ans;i++)
		if (a[i].t>=jdb) tmp++,printf("%d ",a[i].id);
}