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
const int N=1005,D=55,S=N*D,mod=1e9+7;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,d;
string s,sa,sb;
int cnt=1;
int Next[S][10],Fail[S],f[S];
void Ins(string s){
	int x=1;
	For(i,0,d/2-1){
		int k=s[i]-'0';
		if (!Next[x][k])
			Next[x][k]=++cnt;
		x=Next[x][k];
	}
	f[x]=1;
}
void Build(){
	static int q[S];
	int head=0,tail=0;
	Fail[1]=0,Fail[0]=1;
	For(i,0,9)
		Next[0][i]=1;
	q[++tail]=1;
	while (head<tail){
		int x=q[++head];
		For(i,0,9){
			if (!Next[x][i]){
				Next[x][i]=Next[Fail[x]][i];
				continue;
			}
			int y=Next[x][i];
			Fail[y]=Next[Fail[x]][i];
			q[++tail]=y;
		}
	}
}
int v[D][S][4];
int main(){
	cin>>s>>sa>>sb;
	n=s.size(),d=sa.size();
	For(i,0,n-d/2)
		Ins(s.substr(i,d/2));
	Build();
	For(i,1,cnt)
		if (f[i])
			For(j,0,9)
				Next[i][j]=i;
	clr(v);
	v[0][1][3]=1;
	sa=" "+sa,sb=" "+sb;
	For(i,1,d){
		For(j,1,cnt)
			For(k,0,3){
				int val=v[i-1][j][k];
				if (!val)
					continue;
				int lb=k&1?sa[i]-'0':0;
				int ub=k&2?sb[i]-'0':9;
				For(t,lb,ub)
					Add(v[i][Next[j][t]][k&(int)((t==lb)+2)&(int)(((t==ub)<<1)+1)],val);
			}
	}
	int ans=0;
	For(i,1,cnt)
		if (f[i])
			For(j,0,3)
				Add(ans,v[d][i][j]);
	cout<<ans<<endl;
	return 0;
}