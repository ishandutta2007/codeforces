#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10,bd=5e6+10;
int n;
struct node{
	int x,y;
}a[M];
bool cmp(node A,node B){
	return A.x==B.x?A.y<A.y:A.x<B.x;
}
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
int tag[M*50],L[M*50],R[M*50],mx[M*50],tot;
void pd(int x){
	tag[L[x]]+=tag[x]; mx[L[x]]+=tag[x];
	tag[R[x]]+=tag[x]; mx[R[x]]+=tag[x];
	tag[x]=0;
}
void pu(int x){
	mx[x]=max(mx[L[x]],mx[R[x]]);
}
void update(int &x,int l,int r,int ll,int rr,int d){
	if (!x) x=++tot;
	if (l==ll && r==rr){
		tag[x]+=d;
		mx[x]+=d;
		return ;
	}
	if (!L[x]) L[x]=++tot;
	if (!R[x]) R[x]=++tot;
	pd(x);
	if (rr<=mid) update(L[x],l,mid,ll,rr,d);
	else if (ll>mid) update(R[x],mid+1,r,ll,rr,d);
	else update(L[x],l,mid,ll,mid,d),update(R[x],mid+1,r,mid+1,rr,d);
	pu(x);
}
int main(){
	n=read(); int r=read();
	for (int i=1;i<=n;i++){
		int x=read(),y=read();
		a[i].x=x+y;
		a[i].y=x-y;
//		cout<<a[i].x<<" "<<a[i].y<<"   FFF\n";
	}
	sort(a+1,a+n+1,cmp);
	a[n+1].x=bd;
	int d=r+r;
	int Rot = 0 ,ans=0;
	for (int i=1,j=1;i<=n;i++){
		while (a[j].x<a[i].x-d && j<=i){
			update(Rot,-bd,bd,a[j].y,a[j].y+d,-1);
			j++;
		}
		while (a[i].x==a[i+1].x && i<=n){
			update(Rot,-bd,bd,a[i].y,a[i].y+d,1);
			i++;
		}
		update(Rot,-bd,bd,a[i].y,a[i].y+d,1);
		ans=max(ans,mx[Rot]);
//		cout<<ans<<"   FFFFFFFF\n";
	}
	cout<<ans<<"\n";
	return 0;
}