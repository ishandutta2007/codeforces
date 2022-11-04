#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
#define N M
using namespace std;
const int M=200005;
const int MM=20000000;
int la=1,tot=1,ndcnt,n,Q;
int len[M],ch[M][26],fa[N];
int tg[N],rt[N];
char s[N];
vector<int> v[N];
int ls[MM],rs[MM],t[MM];
void add(int c){
	int p=la,np=++tot;
	len[la=np]=len[p]+1;
	for (;!ch[p][c]&&p;p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (len[q]==len[p]+1) fa[np]=q;
		else{
			int nq=++tot; CPY(ch[nq],ch[q]);
			len[nq]=len[p]+1;
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;ch[p][c]==q&&p;p=fa[p]) ch[p][c]=nq;
		}
	}
}
int ask(int k,int l,int r,int x,int y){
	if (!k||x>y) return 0;
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)|ask(rs[k],mid+1,r,mid+1,y);
}
int merge(int a,int b){
	if (!a||!b) return a+b;
	int k=++ndcnt;
	ls[k]=merge(ls[a],ls[b]);
	rs[k]=merge(rs[a],rs[b]);
	if (ls[k]||rs[k]) t[k]=t[ls[k]]|t[rs[k]];
	else t[k]=t[a]|t[b];
	return k;
}
void insert(int &k,int l,int r,int p,int v){
	if (!k) k=++ndcnt;
	if (l==r) return t[k]|=1<<v,void(0);
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p,v);
	else insert(rs[k],mid+1,r,p,v);
	t[k]=t[ls[k]]|t[rs[k]];
}
void init(int p){
	if (tg[p]||p==1)
		insert(rt[p],0,n-1,tg[p],s[tg[p]+1]-'a');
	for (int i=0;i<v[p].size();i++)
		init(v[p][i]),rt[p]=merge(rt[p],rt[v[p][i]]);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	For(i,1,n-1)
		add(s[i]-'a'),tg[la]=i;
	tg[1]=0;
	For(i,2,tot) v[fa[i]].push_back(i);
	init(1); scanf("%d",&Q);
	while (Q--){
		int l,r,dq=1,p1=-1,p2; scanf("%d%d",&l,&r);
		string s; cin>>s; s+='a'-1;
		for (int i=0;i<s.length()&&dq;i++){
			int t=ask(rt[dq],0,n-1,l-1+i,r-1),dd=s[i]+1-'a';
			For(j,dd,25) if ((t>>j)&1){
				p1=i; p2=j; break;
			}
			if (s[i]>='a') dq=ch[dq][s[i]-'a'];
		}
		if (p1==-1) puts("-1");
		else{
			For(i,0,p1-1) putchar(s[i]);
			putchar('a'+p2); puts("");
		}
	}
}