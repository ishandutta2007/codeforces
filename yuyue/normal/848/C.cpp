#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#pragma GCC optimize(2) 
#define ldb long double 
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
#define IT set<int>::iterator 
const int M=1e6+10;
struct Q{
	int op,x,y,z,id;
}q[M];
#define lowbit(x) (x&-x)
LL d[M];
int n,m,a[M],tot;
void Add(int x,int y){
	if (!x) return ;
	for(;x<=n;x+=lowbit(x)) d[x]+=y;
}
LL S(int x){
	LL ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
LL sum(int l,int r){
	return S(r)-S(l-1);
}
set<int> p[M];
#define mid (l+r>>1)
bool cmp(Q A,Q B){
	return A.x<B.x; 
}
bool qus[M];
LL ans[M];
void cdq(int l,int r){
	if (l==r) return ;
	cdq(l,mid); cdq(mid+1,r); 
	int j=l;
	F(i,mid+1,r){
		if (q[i].op){
			while (j<=mid && (q[j].x<=q[i].x || q[j].op) ){
				if (!q[j].op) Add(q[j].y,q[j].z); 
				j++;
			}
			ans[q[i].id]+=sum(q[i].y,n); 
		}
	}
	F(i,l,j-1) if (!q[i].op) Add(q[i].y,-q[i].z); 
	sort(q+l,q+r+1,cmp);
}
int pre[M],nxt[M];
int main(){
	n=read(); m=read();
	F(i,1,n){
		a[i]=read();
		p[a[i]].insert(i);
	}
	F(i,1,n) p[i].insert(0),p[i].insert(n+1);
	F(i,1,n){
		pre[i]=*(--p[a[i]].lower_bound(i));
		nxt[i]=*(++p[a[i]].lower_bound(i));	
		q[++tot]=(Q){0,i,pre[i],i-pre[i],0};
	}
	F(i,1,m){
		int ty=read(),x=read(),y=read();
		if(ty==1){
			//del
			q[++tot]=(Q){0,x,pre[x],pre[x]-x,0};
			q[++tot]=(Q){0,nxt[x],x,x-nxt[x],0};
			q[++tot]=(Q){0,nxt[x],pre[x],nxt[x]-pre[x],0};
			pre[nxt[x]]=pre[x];
			nxt[pre[x]]=nxt[x]; 
			p[a[x]].erase(p[a[x]].lower_bound(x));
			//add
			IT it=(--p[y].lower_bound(x));
			int op=*it,on=*(++it);			
//			cout<<op<<" "<<on<<" "<<y<<"   fuck\n";
			pre[x]=op;
			q[++tot]=(Q){0,x,pre[x],x-pre[x],0};
			q[++tot]=(Q){0,on,pre[on],pre[on]-on,0};
			q[++tot]=(Q){0,on,x,on-x,0};		
			nxt[x]=on; pre[on]=nxt[op]=x;  p[y].insert(x);
			a[x]=y;
		}
		else{
			q[++tot]=(Q){1,y,x,0,i}; qus[i]=1;
		}
	}
	cdq(1,tot);
	F(i,1,m){
		if (qus[i]) cout<<ans[i]<<"\n";
	}
    return 0;
}