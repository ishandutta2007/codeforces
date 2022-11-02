#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0,_t=x.size();i<_t;i++)
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef pair<int,int> P;
#define fir first
#define sec second

int n,q,k;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

vector<P> node[1<<20];
void update(int x,int l,int r,int ql,int qr,P v){
	if (ql<=l&&r<=qr) return node[x].pb(v),void();
	if (ql<=mid) update(ls,l,mid,ql,qr,v);
	if (mid<qr) update(rs,mid+1,r,ql,qr,v);
}
vector<int> qry[500010];

struct Rec{
	int *x; int y;
};

int fat[100010],siz[100010],dep[100010];
int find(int x){
	return fat[x]?find(fat[x]):x;
}

void dfs(int x,int l,int r){
	vector<Rec> S;
	forall(node[x],i){
		int u=find(node[x][i].fir),v=find(node[x][i].sec);
		if (u==v) continue;
		if (dep[u]>dep[v]) swap(u,v);
		S.pb((Rec){fat+u,fat[u]});
		S.pb((Rec){siz+v,siz[v]});
		S.pb((Rec){dep+v,dep[v]});
		fat[u]=v; siz[v]+=siz[u]; dep[v]=max(dep[v],dep[u]+1);
	}
	if (l==r){
		forall(qry[l],i){
			int x=find(qry[l][i]);
			printf("%d\n",siz[x]);
		}
	}
	else{
		dfs(ls,l,mid); dfs(rs,mid+1,r);
	}
	for (int i=S.size()-1;i>=0;i--){
		*S[i].x = S[i].y;
	}
}

struct Bin{
	int o,x,y;
}bin[500010];

int tim[500010];
int main()
{
	n=read(),q=read(),k=read();
	int L=1,R=q,C=0;
	for (int i=1;i<=q;i++){
		int &o=bin[i].o,&x=bin[i].x,&y=bin[i].y;
		o=read();
		if (o==1) x=read(),y=read();
		else if (o==2) x=read();
		else C++;
		tim[i]=C;
	}
	for (int i=1;i<=q;i++){
		int &o=bin[i].o;
		if (o==1){
			int x=bin[i].x,y=bin[i].y;
			int t=upper_bound(tim+1,tim+q+1,tim[i]+k-1)-tim-1;
//			printf("update %d - %d\n",i,t);
			update(1,L,R,i,t,(P){x,y});
		}
		else if (o==2){
			qry[i].pb(bin[i].x);
		}
	}
	for (int i=1;i<=n;i++) siz[i]=1,dep[i]=1;
	dfs(1,L,R);
	return 0;
}