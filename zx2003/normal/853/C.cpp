#include<cstdio>
#include<cctype>
const int N=200010;
struct node{
	int l,r,s;
}a[N*20];
int l,d,r,u,n,q,i,rt[N],x,xb;
long long x1,x2,x3,x4,x5,x6,x7,x8,x9;
void ins(int x,int&y,int l,int r,int v){
	a[y=++xb].s=a[x].s+1;
	if(l==r)return;
	int m=(l+r)>>1;
	if(v>m)a[y].l=a[x].l,ins(a[x].r,a[y].r,m+1,r,v);
		else a[y].r=a[x].r,ins(a[x].l,a[y].l,l,m,v);
}
int query(int x,int y,int rl,int rr,int l,int r){
	if(!y || r<l)return 0;
	if(l==rl && r==rr)return a[y].s-a[x].s;
	int m=(rl+rr)>>1;
	if(l>m)return query(a[x].r,a[y].r,m+1,rr,l,r);
		else if(r<=m)return query(a[x].l,a[y].l,rl,m,l,r);
				else return query(a[x].l,a[y].l,rl,m,l,m)+query(a[x].r,a[y].r,m+1,rr,m+1,r);
}
inline void print(long long x){
	if(!x)putchar('0');	
		else{
			static int buf[30],xb;
			for(xb=0;x;x/=10)buf[++xb]=x%10;
			while(xb)putchar(buf[xb--]^48);
		}
}
int main(){
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		ins(rt[i-1],rt[i],1,n,x);
	}
	while(q--){
		scanf("%d%d%d%d",&l,&d,&r,&u);
		x1=query(0,rt[l-1],1,n,u+1,n);
		x2=query(0,rt[l-1],1,n,d,u);
		x3=query(0,rt[l-1],1,n,1,d-1);
		x4=query(rt[l-1],rt[r],1,n,u+1,n);
		x5=query(rt[l-1],rt[r],1,n,d,u);
		x6=query(rt[l-1],rt[r],1,n,1,d-1);
		x7=query(rt[r],rt[n],1,n,u+1,n);
		x8=query(rt[r],rt[n],1,n,d,u);
		x9=query(rt[r],rt[n],1,n,1,d-1);
		print((x1+x4)*(x5+x6+x8+x9)+x2*(x4+x5+x6+x7+x8+x9)+x3*(x4+x5+x7+x8)+x5*(x5-1)/2+
			x5*(x6+x7+x8+x9)+x6*(x7+x8));
		putchar('\n');
	}
	return 0;
}