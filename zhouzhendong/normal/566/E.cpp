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
const int N=1005;
typedef bitset <N> bit;
int n;
bit a[N],U,res[N],And[N];
vector <bit> rem,son[N];
void oute(int x,int y){
	printf("%d %d\n",x,y);
}
void Solve(int x,int pre){
	if (pre)
		And[x]&=res[pre];
	bit ju=And[x];
	for (int i=ju._Find_first();i!=ju.size();i=ju._Find_next(i))
		if (i!=pre&&i!=x)
			oute(i,x);
	vector <bit> _rem;
	for (auto i : rem){
		bit tmp=i&ju;
		int sz=tmp.count();
		if (sz==2){
			int a=tmp._Find_first(),b=tmp._Find_next(a);
			if (a==x)
				swap(a,b);
			son[a].pb(i),And[a]&=i;
		}
		else 
			_rem.pb(i);
	}
	swap(rem,_rem);
	for (int i=ju._Find_first();i!=ju.size();i=ju._Find_next(i))
		if (i!=pre&&i!=x){
			if (son[i].empty()){
				res[i]=ju;
				continue;
			}
			for (auto v : son[x])
				if ((v&And[i]).count()>=3){
					res[i]=v;
					break;
				}
			And[i]&=res[i];
			Solve(i,x);
		}
}
bool cmp(bit a,bit b){
	For(i,0,N-1)
		if (a[i]!=b[i])
			return a[i]<b[i];
	return 0;
}
int main(){
	n=read();
	For(i,1,n){
		U[i]=1;
		int k=read();
		while (k--)
			a[i][read()]=1;
	}
	sort(a+1,a+n+1,cmp);
	if (n==2)
		return oute(1,2),0;
	For(i,2,n)
		if ((a[i]&a[1]).count()>=3){
			swap(a[i],a[2]);
			break;
		}
	bit ju=a[1]&a[2];
	For(i,3,n)
		if ((ju&a[i]).count()>=3){
			swap(a[i],a[3]);
			break;	
		}
	ju&=a[3];
	int sz=ju.count();
	if (sz==n){
		For(i,2,n)
			oute(1,i);
		return 0;
	}
	{
		int cnt=0;
		For(i,1,n)
			if ((ju&a[i])==ju)
				swap(a[i],a[++cnt]);
		assert(cnt==sz);
	}
	bit vis,bak;
	int x=0,y=0;
	For(i,sz+1,n){
		bit tmp=a[i]&ju;
		int tsz=tmp.count();
		if (tsz==0)
			continue;
		if (tsz==1){
			bak=a[i];
			vis[tmp._Find_first()]=1;
		}
		else if (tsz==2){
			int a=tmp._Find_first();
			int b=tmp._Find_next(a);
			if (!x)
				x=a,y=b;
			else if (!y)
				assert(a==x||b==x);
			else if (a!=x||b!=y){
				if (a==x||b==x)
					y=0;
				else if (a==y||b==y)
					x=y,y=0;
			}
		}
	}
	if (y&&vis[y])
		y=0;
	else if (x&&vis[x])
		x=y,y=0;
	if (x&&y){
		oute(x,y);
		For(i,1,n)
			if (i!=x&&i!=y)
				oute(i,ju[i]?x:y);
		return 0;
	}
	if (vis.count()==0){
		int flag=0;
		For(i,1,sz)
			if (a[i]==U){
				flag=1;
				swap(a[i],a[1]);
				break;
			}
		assert(flag);
	}
	else {
		int flag=0;
		For(i,1,sz)
			if ((a[i]&bak).count()==2){
				flag=1;
				swap(a[i],a[1]);
				break;
			}
		assert(flag);
	}
	For(i,sz+1,n)
		rem.pb(a[i]);
	For(i,1,n)
		And[i]=U;
	And[x]&=a[1];
	For(i,2,sz)
		son[x].pb(a[i]),And[x]&=a[i];
	res[x]=a[1];
	Solve(x,0);
	return 0;
}