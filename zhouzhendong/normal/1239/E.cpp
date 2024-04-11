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
const int N=26,S=N*50000;
int n,s;
vector <int> a,b;
bitset <S> va[N],vb[N];
int sta[N][S],stb[N][S];
void SolveA(int k,int cnt,int sum,int st){
	if (k==n-1){
		if (!va[cnt][sum]){
			va[cnt][sum]=1;
			sta[cnt][sum]=st;
		}
		return;
	}
	SolveA(k+1,cnt,sum,st);
	SolveA(k+1,cnt+1,sum+a[k],st|1<<k);
}
void SolveB(int k,int cnt,int sum,int st){
	if (k==n-1){
		if (!vb[cnt][sum]){
			vb[cnt][sum]=1;
			stb[cnt][sum]=st;
		}
		return;
	}
	SolveB(k+1,cnt,sum,st);
	SolveB(k+1,cnt+1,sum+b[k],st|1<<k);
}
int ans=1e9,ansa,ansb;
int res[2][N];
void chkans(int i,int j,int ap,int bp){
	int val=max(ap+bp,s-ap-bp);
	if (val<ans){
		ans=val;
		ansa=sta[i][ap];
		ansb=stb[j][bp];
	}
}
int main(){
	n=read();
	For(i,1,n*2)
		a.pb(read());
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	res[0][1]=a.back(),a.pop_back();
	res[1][n]=a.back(),a.pop_back();
	s=0;
	for (auto i : a)
		s+=i;
	For(i,1,n-1)
		b.pb(a.back()),a.pop_back();
	SolveA(0,0,0,0);
	SolveB(0,0,0,0);
//	For(i,0,n-1){
//		outarr(va[i],0,s);
//		outarr(vb[i],0,s);
//	}
	For(i,0,n-1){
		int j=n-1-i;
		vector <int> bp;
		For(k,0,s)
			if (vb[j][k])
				bp.pb(k);
		For(k,0,s){
			if (!va[i][k])
				continue;
			while (bp.size()>=2&&(bp[bp.size()-2]+k)*2>=s)
				bp.pop_back();
			if (bp.size()>0)
				chkans(i,j,k,bp.back());
			if (bp.size()>=2)
				chkans(i,j,k,bp[bp.size()-2]);
		}
	}
	int t0=1,t1=0;
	For(i,0,n-2)
		if (ansa>>i&1)
			res[0][++t0]=a[i];
		else
			res[1][++t1]=a[i];
	For(i,0,n-2)
		if (ansb>>i&1)
			res[0][++t0]=b[i];
		else
			res[1][++t1]=b[i];
	sort(res[0]+2,res[0]+n+1);
	sort(res[1]+1,res[1]+n);
	reverse(res[1]+1,res[1]+n);
	For(i,0,1){
		For(j,1,n)
			printf("%d ",res[i][j]);
		puts("");
	}
	return 0;
}