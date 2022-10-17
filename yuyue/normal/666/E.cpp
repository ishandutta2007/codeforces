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
const int M=5e5+10;
int head[M],to[M],nxt[M],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
char ch[M],s[M];
struct seg{
	int l,r,mx,pos;
	seg (){
		l=r=mx=pos=0;
	}
}a[M*20];
int tt,rt[M];
#define mid (l+r>>1)
void pushup(seg &A,seg B,seg C){
	if (B.mx>=C.mx) A.mx=B.mx,A.pos=B.pos; 
	else A.mx=C.mx,A.pos=C.pos; 
}
void update(int &x,int l,int r,int p){
	x=++tt;
	if (l==r) {
		a[x].mx++;
		a[x].pos=p;
		return ;
	}
	if (p<=mid) update(a[x].l,l,mid,p);
	else update(a[x].r,mid+1,r,p);
	pushup(a[x],a[a[x].l],a[a[x].r]);
}
int MG(int x,int y,int l,int r){
	if (!x || !y) return x|y;
	int temp=++tt;
	if (l==r) {
		a[temp].mx=a[x].mx+a[y].mx;
		a[temp].pos=l;
		return temp;
	}
	a[temp].l=MG(a[x].l,a[y].l,l,mid);
	a[temp].r=MG(a[x].r,a[y].r,mid+1,r);
	pushup(a[temp],a[a[temp].l],a[a[temp].r]);
	return temp;
}
seg query(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return a[x];
	if (rr<=mid) return query(a[x].l,l,mid,ll,rr);
	if (ll>mid) return query(a[x].r,mid+1,r,ll,rr);
	seg A=query(a[x].l,l,mid,ll,mid),B=query(a[x].r,mid+1,r,mid+1,rr);
	seg ret;
	pushup(ret,A,B);
	return ret;
}
struct node{
	int len,fa,ch[30];
}t[M];
int last=1,tot=1;
int n,m;
void extend(int c,int bl){
	int p=last,np=++tot; last=tot; t[np].len=t[p].len+1;
	update(rt[np],1,m,bl);
	for (;p&&!t[p].ch[c];p=t[p].fa) t[p].ch[c]=np;
	if (!p) t[np].fa=1;
	else {
		int q=t[p].ch[c];
		if (t[q].len==t[p].len+1) t[np].fa=q;
		else {
			int nq=++tot;
			t[nq]=t[q]; t[nq].len=t[p].len+1;
			t[q].fa=t[np].fa=nq;
			for (;p&&t[p].ch[c]==q;p=t[p].fa) t[p].ch[c]=nq;
		}
	}
}
int f[M][23];
void dfs(int x){
	for (int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		dfs(y);
		rt[x]=MG(rt[x],rt[y],1,m);
	}	

}
vector<int> v[M];
int pos[M],mxl[M];
struct Q{
	int l,r,pl,pr;
}q[M];

int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1); 
	m=read();
	for (int i=1;i<=m;i++){
		scanf("%s",s+1);
		int ll=strlen(s+1);
		last=1;
		for (int j=1;j<=ll;j++) extend(s[j]-'a',i);
	}
	for (int i=2;i<=tot;i++) f[i][0]=t[i].fa,add(t[i].fa,i);
	dfs(1);

	int now=1,nl=0;
	for (int i=1;i<=n;i++){
		int c=ch[i]-'a';
		for (;now && !t[now].ch[c];now=t[now].fa,nl=t[now].len);
		if (!now){now=1;nl=0;}
		else now=t[now].ch[c],nl++;
		pos[i]=now; mxl[i]=nl;
	}

	int qt=read();
	while (qt--){
		int l=read(),r=read(),pl=read(),pr=read();
		if (mxl[pr]<pr-pl+1) {
			cout<<l<<" "<<0<<"\n";
			continue;
		}
		int x=pos[pr];
		for (int i=20;~i;i--) 
		if (f[x][i] && t[f[x][i]].len>=pr-pl+1) x=f[x][i];
		seg ANS=query(rt[x],1,m,l,r);	
		if (!ANS.pos) ANS.pos=l;
		cout<<ANS.pos<<" "<<ANS.mx<<"\n";
	}
	
	return 0;
}