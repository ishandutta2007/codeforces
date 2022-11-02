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
const int N=205*2;
int n,m,b;
vector <int> e[N];
char s[N];
int id(int a,int t){
	return a+t*n;
}
int g[N][N];
void dfs(int s,int x){
	if (g[s][x])
		return;
	g[s][x]=1;
	for (auto y : e[x])
		dfs(s,y);
}
string mis,str;
int stp=0;
void solve(int i,string S,int flag){
//	cout<<"Solve("<<i<<","<<S<<","<<flag<<")\n";
	if (i==n){
		cout<<S<<endl;
		exit(0);
	}
	For(c,flag?'a':mis[i],'a'+b-1){
		if (S[i]!=' '&&s[c-'a']!=S[i])
			continue;
		string ss=S;
		ss[i]=c;
		int x=id(i+1,s[c-'a']=='V');
		int f=0;
		For(y,1,n)
			if (g[x][y])
				if (y>i+1){
					f|=ss[y-1]=='V';
					ss[y-1]='C';
					f|=stp==1;
				}
		For(y,n+1,n*2)
			if (g[x][y])
				if (y-n>i+1){
					f|=ss[y-n-1]=='C';
					ss[y-n-1]='V';
					f|=stp==-1;
				}
		if (f)
			continue;
		solve(i+1,ss,flag||c>mis[i]);
	}
}
void gettp(){
	For(i,1,b-1)
		if (s[i]!=s[0])
			return;
	if (s[0]=='C')
		stp=-1;
	else
		stp=1;
}
int main(){
	cin>>s;
	b=strlen(s);
	gettp();
	n=read(),m=read();
	For(i,1,m){
		char at[2],bt[2];
		int p1,p2;
		cin>>p1>>at>>p2>>bt;
		int t1=at[0]=='V',t2=bt[0]=='V';
		e[id(p1,t1)].pb(id(p2,t2));
		e[id(p2,t2^1)].pb(id(p1,t1^1));
	}
	For(i,1,n*2)
		dfs(i,i);
//	For(i,1,n*2){outarr(g[i],1,n*2);}
//	For(i,1,n*2)
//		For(j,1,n*2)
//			if (i!=j&&g[i][j])
//				printf("(%d,%d)\n",i,j);
	cin>>mis;
	For(i,1,n)
		if (g[i][i+n]&&g[i+n][i])
			return puts("-1"),0;
	str="";
	For(i,1,n)
		str+=" ";
	solve(0,str,0);
	puts("-1");
	return 0;
}