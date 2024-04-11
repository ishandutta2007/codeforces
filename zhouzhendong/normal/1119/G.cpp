#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define real __zzd001
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
#define outarr(a,L,R) printf(#a"[%d...%d] = ",L,R);\
						For(_v2,L,R)printf("%d ",a[_v2]);puts("");
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1000005;
int n,m,k,ub;
int a[N];
LL s=0;
int nows=0;
int ans[N];
vector <int> opt[N];
struct Node{
	int id,v;
	Node(){}
	Node(int _id,int _v){
		id=_id,v=_v;
	}
	friend bool operator < (Node a,Node b){
		return a.v<b.v;
	}
};
priority_queue <Node> Q;
Node bak[N];
int check(int x){
	int cnt=0,tot=0;
	For(i,1,ub)
		if ((tot+=bak[i].v/x)>=k||bak[i].v<x)
			break;
	return tot>=k;
}
int get(){
	int cnt=0;
	For(i,1,ub)
		bak[++cnt]=Q.top(),Q.pop();
	int L=1,R=n-nows,ans=0;
	while (L<=R){
		int mid=(L+R)>>1;
		if (check(mid))
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
	while (cnt)
		Q.push(bak[cnt--]);
	return ans;
}
vector <Node> vec;
int main(){
	n=read(),m=read();
	For(i,1,m)
		a[i]=read(),s+=a[i];
	k=(s+n-1)/n;
	ub=min(k,m);
	a[1]+=k*n-s;
	For(i,1,m)
		Q.push(Node(i,a[i]));
	For(i,1,m)
		opt[i].clear();
	For(i,1,m){
		int now=get();
		ans[i]=now;
		nows+=ans[i];
		vec.clear();
		For(j,1,ub){
			Node v=Q.top();
			Q.pop();
			while (v.v>=now&&(int)opt[i].size()<k){
				v.v-=now;
				a[v.id]-=now;
				opt[i].pb(v.id);
			}
			vec.pb(v);
			if ((int)opt[i].size()==k)
				break;
		}
		while ((int)opt[i].size()<k)
			opt[i].pb(1);
		while (!vec.empty())
			Q.push(vec.back()),vec.pop_back();
	}
	printf("%d\n",k);
	For(i,1,m)
		printf("%d ",ans[i]);
	puts("");
	For(i,0,k-1){
		For(j,1,m)
			printf("%d ",opt[j][i]);
		puts("");
	}
	return 0;
}