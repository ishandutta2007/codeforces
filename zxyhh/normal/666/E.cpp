/*
	>Author: zxy_hhhh
	>blog: zxy-hhhh.cn
	>date: 2019/01/26
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
using namespace std;
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=-1;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f*_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 500005
int n;
struct Tree {
	int mx,w;
	Tree *ls,*rs;
	Tree():mx(0),w(0) {ls=rs=NULL;}
	void pushup() {
		mx=0,w=0;
		if (ls!=NULL) mx=ls->mx,w=ls->w;
		if (rs!=NULL && rs->mx>mx) mx=rs->mx,w=rs->w;
	}
};
void insert(Tree *&now,int l,int r,int x) {
	if (now==NULL) now=new Tree;
	if (l==r) {now->mx++,now->w=x;return ;}
	int mid=(l+r)>>1;
	if (x<=mid) insert(now->ls,l,mid,x);
	else insert(now->rs,mid+1,r,x);
	now->pushup();
}
Tree *merge(Tree *u,Tree *v,int l,int r) {
	if (u==NULL) return v; if (v==NULL) return u;
	Tree *now=new Tree;
	if (l==r) now->mx=u->mx+v->mx,now->w=u->w;
	else {
		int mid=(l+r)>>1;
		now->ls=merge(u->ls,v->ls,l,mid),now->rs=merge(u->rs,v->rs,mid+1,r);
		now->pushup();
	}
	return now;
}
pair<int , int> query(Tree *u,int l,int r,int ql,int qr) {
	if (u==NULL||(l>qr||r<ql)) return make_pair(0,-n);
	if (l>=ql&&r<=qr) return make_pair(u->mx,-u->w);
	int mid=(l+r)>>1;
	return max(query(u->ls,l,mid,ql,qr),query(u->rs,mid+1,r,ql,qr));
}
struct node {
	int len,link,nx[26];
	int jump[20];
	Tree *rt;
}st[maxn<<1];
int t[maxn<<1],buf[maxn<<1];
int sz,last;
inline void init(){st[0].link=-1;}
void extend(int c,int X) {
	if (st[last].nx[c] && st[st[last].nx[c]].len==st[last].len+1) {
		last=st[last].nx[c],insert(st[last].rt,1,n,X);
		return ;
	}
	int cur=++sz,p=last;
	st[cur].rt=NULL,insert(st[cur].rt,1,n,X);
	st[cur].len=st[last].len+1;
	for(;p!=-1 && !st[p].nx[c];p=st[p].link) st[p].nx[c]=cur;
	if (p==-1) st[cur].link=0;
	else {
		int q=st[p].nx[c];
		if (st[p].len+1==st[q].len) st[cur].link=q;
		else {
			int clone=++sz;
			st[clone]=st[q],st[clone].len=st[p].len+1,st[clone].rt=NULL;
			for(;p!=-1 && st[p].nx[c]==q;p=st[p].link) st[p].nx[c]=clone;
			st[cur].link=st[q].link=clone;
		}
	}
	last=cur;
}
inline void build() {
	rep(i,0,sz) buf[st[i].len]++;
	rep(i,1,sz) buf[i]+=buf[i-1];
	rep(i,0,sz) t[buf[st[i].len]--]=i;
	drp(i,sz+1,2){
		int x=t[i];
		st[st[x].link].rt=merge(st[st[x].link].rt,st[x].rt,1,n);
		//wrt(x,' '),wrt(st[x].len,'\n');
	}
	rep(_i,2,sz+1) {
		int x=t[_i]; st[x].jump[0]=st[x].link;
		rep(i,1,19) 
			if (st[x].jump[i-1]!=-1)
				st[x].jump[i]=st[st[x].jump[i-1]].jump[i-1];
			else st[x].jump[i]=-1;
	}
}
char s[maxn];
int Len;
int at[maxn],gt[maxn];
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	init();
	scanf("%s",s+1);
	n=rd();
	rep(i,1,n){
		char ch=getchar(); last=0;
		for(;!(ch>='a'&&ch<='z'); ch=getchar()) ;
		for(;ch>='a'&&ch<='z';ch=getchar()) extend(ch-'a',i);
	}
	build();
	Len=strlen(s+1);
	int now=0,nowl=0;
	rep(i,1,Len) {
		int ch=s[i]-'a';
		for(;now!=-1 && !st[now].nx[ch];now=st[now].link,nowl=st[now].len);
		if (now==-1) now=0,nowl=0;
		else now=st[now].nx[ch],nowl++;
		at[i]=now,gt[i]=nowl;
	}
	int Q=rd();
	while(Q--){
		int ql=rd(),qr=rd(),L=rd(),R=rd();
		int len=R-L+1;
		if (gt[R]<len){ 
			wrt(ql,' '),wrt(0,'\n');
			continue;
		}
		now=at[R];
		drp(i,19,0)
			if (st[now].jump[i]!=-1&&st[st[now].jump[i]].len>=len) 
				now=st[now].jump[i];
		pair<int,int> ans=query(st[now].rt,1,n,ql,qr);
		if (ans.first==0) wrt(ql,' '),wrt(0,'\n'); 
		else wrt(-ans.second,' '),wrt(ans.first,'\n');
	}
}