#include<bits/stdc++.h>
#define N 300005
using namespace std;
map<int,pair<int,vector<int> > > mp;
int n,q,lim[N],t[N*4],mx[N*4],base;
void build(int k,int l,int r){
	t[k]=1e9;
	mx[k]=-1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void setmx(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k]=min(t[k],v);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) setmx(k*2,l,mid,x,y,v);
	else if (x>mid) setmx(k*2+1,mid+1,r,x,y,v);
	else setmx(k*2,l,mid,x,mid,v),
		 setmx(k*2+1,mid+1,r,mid+1,y,v); 
}
int qmx(int x){
	int k=1,l=1,r=n,v=t[1];
	while (l<r){
		int mid=(l+r)/2;
		k*=2;
		if (x<=mid) r=mid;
		else k++,l=mid+1;
		v=min(v,t[k]);
	}
	return v;
}
void Sset(int x,int v){
	int k=1,l=1,r=n;
	while (l<r){
		int mid=(l+r)/2;
		k*=2;
		if (x<=mid) r=mid;
		else k++,l=mid+1;
	}
	mx[k]=v;
	for (;k/=2;mx[k]=max(mx[k*2],mx[k*2+1]));
}
int qset(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return mx[k];
	int mid=(l+r)/2;
	if (y<=mid) return qset(k*2,l,mid,x,y);
	if (x>mid) return qset(k*2+1,mid+1,r,x,y);
	return max(qset(k*2,l,mid,x,mid),qset(k*2+1,mid+1,r,mid+1,y));
}
void work(int k,int l,int r,int v){
	if (l==r){
		if (lim[l]==-1)
			lim[l]=v;
		return;
	}
	int mid=(l+r)/2;
	work(k*2,l,mid,min(v,t[k*2]));
	work(k*2+1,mid+1,r,min(v,t[k*2+1]));
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		lim[i]=-1;
	build(1,1,n);
	while (q--){
		int fl,l,r,x,v;
		scanf("%d",&fl);
		if (fl==1){
			scanf("%d%d%d",&l,&r,&x);
			v=qset(1,1,n,l,r);
			if (v>x){
				puts("NO");
				return 0;
			}
			if (v<x){
				mp[x].first--;
				base|=x;
			}
			setmx(1,1,n,l,r,x);
		}
		else{
			scanf("%d%d",&x,&v);
			if (lim[x]==-1)
				lim[x]=qmx(x);
			Sset(x,v);
		}
	}
	work(1,1,n,t[1]);
	for (int i=1;i<=n;i++){
		mp[lim[i]].first++;
		mp[lim[i]].second.push_back(i);
	}
	for (auto &i:mp)
		if (i.second.first<0){
			puts("NO");
			return 0;
		}
	for (auto &i:mp)
		if (i.second.first>1){
			int tmp=1;
			for (;tmp<i.first;tmp=tmp*2+1);
			base|=tmp;
			lim[i.second.second[0]]=tmp/2;
			lim[i.second.second[1]]=i.first;
		}
	for (auto &i:mp)
		if (i.second.first==1){
			int tmp=i.first;
			for (int j=1<<29;j;j/=2)
				if (tmp>=j&&!(base&j))
					tmp-=j;
			lim[i.second.second[0]]=i.first-tmp;
			base|=i.first-tmp;
		}
	puts("YES");
	for (int i=1;i<=n;i++)
		printf("%d ",lim[i]);
}