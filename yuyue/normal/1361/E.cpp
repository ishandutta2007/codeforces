#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
vector<int> v[M];
int n,m,dep[M],t[M],s[M],stk[M];
bool bad[M],flag,in[M];
void clr(){
	F(i,1,n) v[i].clear(),bad[i]=0;
}
void dfs(int x,int fa){
	in[x]=1; dep[x]=dep[fa]+1;
//	cout<<x<<" "<<dep[x]<<" "<<in[3]<<"  dfs\n";
	bool fl=0;
	for (int y:v[x]){

			 if (dep[y]){
			 	if (!in[y]){
//			 		cout<<x<<" "<<y<<"    ggggg\n";
			 		flag=1;
			 	}
			 	else{
			 		if (dep[y]<dep[x]){
//				 		cout<<x<<" "<<y<<" "<<dep[x]<<"   hh\n";
				 		t[x]=min(t[x],dep[y]);
				 		s[x]++; s[y]--;
			 		}
			 		
			 	}
			 }
			 else dfs(y,x);


	}
	in[x]=0;
}
void ga(int x,int fa){
//	cerr<<x<<" ";
	for (int y:v[x]){
		if (dep[y]>dep[x]){
			ga(y,x);
			t[x]=min(t[y],t[x]);
			s[x]+=s[y];			
		}
	}
}
int num;
void dfs1(int x,int fa){
	stk[dep[x]]=x;
	if (s[x]>=2) bad[x]=1;
	else if (t[x]<1e9) bad[x]=bad[stk[t[x]]];
	num+=!bad[x];
	for (int y:v[x]){
		if (dep[y]>dep[x]){
			dfs1(y,x);
		}
	}
}
void doit(int x){
//	cout<<x<<"\n";
	num=0;
	ga(x,0);
	dfs1(x,0);
	int lim=n/5;
	if (n%5==0) lim--;
	if (num<=lim){
		puts("-1");
		return ;
	}
	F(i,1,n){
		if (!bad[i]) cout<<i<<" ";
	}
	cout<<"\n";
}
void work(){
	clr();
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
	}
//	dfs(1,0);
//	cout<<flag<<"\n";
	F(T,1,188){
		int x=1ll*rand()*rand()%n+1;
		flag=0;
		F(i,1,n) dep[i]=s[i]=0,t[i]=1e9;
		//cout<<x<<"  bg\n";
		dfs(x,0);
		if (!flag){		
			doit(x);
			return ;
		}
		//else cout<<" failed\n";
	}
	puts("-1");
}
int main(){
	int T=read(); srand(19260817);
	while (T--) work();
	return 0; 
}
/*
1
3 3
1 2
2 3
3 1

1
3 6
1 2
2 1
2 3
3 2
1 3
3 1

1
6 8
1 2
2 3
3 4
4 5
5 6
6 1
6 2
5 1
*/