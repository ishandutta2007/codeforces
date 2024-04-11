#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005;
int k,n,m;
int a[N];
struct Node{
	int type,k,b,id;
	LL v0,v1;
}o[N];
int cov[N];
vector <int> add[N];
bool cmp(int a,int b){
	return o[a].b>o[b].b;
}
vector <Node> op;
bool cmpop(Node x,Node y){
	// x.v0/x.v1 > y.v0/y.v1
	return x.v0*y.v1>y.v0*x.v1;
}
bool cmptp(Node x,Node y){
	return x.type<y.type;
}
int main(){
	k=read(),n=read(),m=read();
	For(i,1,k)
		a[i]=read();
	For(i,1,n){
		o[i].type=read();
		o[i].k=read();
		o[i].b=read();
		o[i].id=i;
		if (o[i].type==1){
			if (!cov[o[i].k]||o[cov[o[i].k]].b<o[i].b)
				cov[o[i].k]=i;
		}
		else if (o[i].type==2){
			add[o[i].k].pb(i);
		}
		else if (o[i].type==3){
			o[i].v0=o[i].b,o[i].v1=1;
		}
	}
	For(i,1,k){
		if (cov[i]&&o[cov[i]].b>a[i]){
			o[cov[i]].b-=a[i];
			add[i].pb(cov[i]);
		}
		else 
			cov[i]=0;
		sort(add[i].begin(),add[i].end(),cmp);
		LL s=a[i];
		for (auto id : add[i]){
			o[id].v1=s;
			s+=o[id].b;
			o[id].v0=s;
		}
	}
	For(i,1,n)
		if (o[i].type!=1||cov[o[i].k]==i){
			o[i].v0-=o[i].v1;
			op.pb(o[i]);
		}
	sort(op.begin(),op.end(),cmpop);
	m=min(m,(int)op.size());
	sort(op.begin(),op.begin()+m,cmptp);
	printf("%d\n",m);
	For(i,0,m-1)
		printf("%d ",op[i].id);
	puts("");
	return 0;
}