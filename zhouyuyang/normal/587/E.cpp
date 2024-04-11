#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int b[N],a[N],n,q;
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) b[x]^=v;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s^=b[x];
	return s;
}
struct Bas{
	int a[32];
	Bas(){
		memset(a,0,sizeof(a));
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
	void insert(int x){
		for (int i=29;i>=0&&x;i--)
			if ((x>>i)&1){
				if (!a[i]){
					a[i]=x;
					break;
				}
				x^=a[i];
			}
	}
	int count(){
		int ans=0;
		for (int i=0;i<=29;i++)
			ans+=(a[i]!=0);
		return ans;
	}
}t[N*4],ans;
Bas operator +(Bas a,Bas b){
	for (int i=0;i<=29;i++)
		a.insert(b.a[i]);
	return a;
}
void build(int k,int l,int r){
	if (l==r){
		t[k].insert(a[l]^a[l-1]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int x){
	if (l==r){
		for (int i=0;i<=29;i++)
			if (t[k].a[i]){
				x^=t[k].a[i];
				t[k].a[i]=0;
			}
		t[k].insert(x);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,x);
	else change(k*2+1,mid+1,r,p,x);
	t[k]=t[k*2]+t[k*2+1];
}
void ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		ans=ans+t[k];
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) ask(k*2,l,mid,x,y);
	else if (x>mid) ask(k*2+1,mid+1,r,x,y);
	else ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		change(i,a[i]^a[i-1]);
	}
	build(1,1,n);
	while (q--){
		int fl,l,r,x;
		scanf("%d%d%d",&fl,&l,&r);
		if (fl==1){
			scanf("%d",&x);
			change(l,x);
			change(r+1,x);
			change(1,1,n,l,x);
			if (r<n) change(1,1,n,r+1,x);
		}
		else{
			ans.clear();
			if (l<r) ask(1,1,n,l+1,r);
			ans.insert(ask(l));
			printf("%d\n",1<<ans.count());
		}
	}
}