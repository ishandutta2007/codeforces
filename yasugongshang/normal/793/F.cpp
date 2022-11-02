#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();
	while(c<'0' || c>'9')
		c=getchar();
	int x=0;
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
const int maxn=(1<<21)+3;
const int INF=0x3f3f3f3f;
struct segtree{
	int n;
	int tag[maxn],mmin[maxn];
	int ul,ur,uv;
	void update(int o,int l,int r){
		if (ul<=l && ur>=r){
			tag[o]=max(tag[o],uv);
			mmin[o]=max(mmin[o],uv);
			return;
		}
		int mid=(l+r)/2;
		if (ul<=mid)
			update(o*2,l,mid);
		if (ur>mid)
			update(o*2+1,mid+1,r);
		mmin[o]=max(min(mmin[o*2],mmin[o*2+1]),tag[o]);
	}
	void modify(int l,int r,int v){
		if (l>r)
			return;
//		printf("modify %d %d %d\n",l,r,v);
		ul=l,ur=r,uv=v;
		update(1,1,n);
	}
	/*int ql,qr;
	int query(int o,int l,int r){
		if (ql<=l && qr>=r)
			return mmin[o];
		int mid=(l+r)/2,ans=INF;
		if (ql<=mid)
			ans=min(ans,query(o*2,l,mid));
		if (qr>mid)
			ans=min(ans,query(o*2+1,mid+1,r));
		return max(ans,tag[o]);
	}
	int query(int l,int r){
		if (l>r)
			return INF;
		ql=l,qr=r;
		int ans=query(1,1,n);
//		printf("query %d %d %d\n",l,r,ans);
		return ans;
	}*/
	int p,x; //>=p,<x
	int query2(int o,int l,int r){
		if (max(tag[o],mmin[o])>=x)
			return n+1;
		if (l==r)
			return l;
		int mid=(l+r)/2;
		if (mmin[o*2]<x)
			return query2(o*2,l,mid);
		else return query2(o*2+1,mid+1,r);
	}
	int query(int o,int l,int r){
		if (max(tag[o],mmin[o])>=x)
			return n+1;
		if (l==r)
			return l;
		int mid=(l+r)/2;
		if (p>mid)
			return query(o*2+1,mid+1,r);
		else{
			int ans=query(o*2,l,mid);
			if (ans!=n+1)
				return ans;
			else return query2(o*2+1,mid+1,r);
		}
	}
	int query(int p,int x){
		if (p>n)
			return n+1;
		this->p=p,this->x=x;
		return query(1,1,n);
	}
}t;
struct edge{
	int l,r;
	bool operator <(const edge& rhs)const{
		return r<rhs.r;
	}
}e[maxn];
struct query{
	int id,x,y;
	bool operator <(const query& rhs)const{
		return y<rhs.y;
	}
}q[maxn];
int ans[maxn];
void write(int x){
	if (x>=10)
		write(x/10);
	putchar(x%10+'0');
}
void writeln(int x){
	write(x);
	putchar('\n');
}
int main(){
//	freopen("gemo.in","r",stdin);freopen("gemo.out","w",stdout);
	int n=t.n=read(),k=read();
	for(int i=1;i<=k;i++)	
		e[i].l=read(),e[i].r=read();
	sort(e+1,e+k+1); int m=read();
	for(int i=1;i<=m;i++)
		q[i].id=i,q[i].x=read(),q[i].y=read();
	sort(q+1,q+m+1);
	int now=1;
//	puts("WTF");
	for(int i=1;i<=m;i++){
		while(now<=k && e[now].r<=q[i].y){
			t.modify(e[now].l+1,e[now].r,e[now].l);
			now++;
		}
//		puts("WTF");
		/*int l=q[i].x+1,r=q[i].y+1;
		while(l<r){
			int mid=(l+r)/2;
			if (t.query(q[i].x+1,mid)<q[i].x)
				r=mid;
			else l=mid+1;
		}*/
		ans[q[i].id]=t.query(q[i].x+1,q[i].x)-1;
	}
	for(int i=1;i<=m;i++)
		writeln(ans[i]);
//	fprintf(stderr,"%d",clock());
}