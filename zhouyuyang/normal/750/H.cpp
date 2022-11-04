#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(j);i<=(k);i++)
using namespace std;
const int L=1005;
const int N=L*L;
const int dx[8]={-1,-1,-1, 0,0, 1,1,1};
const int dy[8]={-1, 0, 1,-1,1,-1,0,1};
char s[L][L];
vector<int> V[N];
set<int> mp[N];
int id[L][L],fa[N];
int n,m,q,S,T;
int X[N],Y[N];
int top,cnt;
int sta[N*2]; 
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int get2(int x){
	for (;x!=fa[x];x=fa[x]);
	return x;
}
void merge(int x,int y){
	x=get(x); y=get(y);
	if (x!=y) fa[x]=y;
}
void merge2(int x,int y){
	x=get2(x); y=get2(y);
	if (x!=y){
		sta[++top]=x;
		sta[++top]=-y;
		fa[x]=y;
		V[y].push_back(-x);
	}
}
void dfs(int x,vector<int> &v){
	For(i,0,V[x].size()-1){
		int y=V[x][i];
		if (y>0) v.push_back(y);
		else dfs(-y,v);
	}
}
int solve(){
	int p;
	scanf("%d",&p);
	For(i,1,p){
		int x,y;
		scanf("%d%d",&x,&y);
		if (s[x][y]=='#') continue;
		For(k,0,7){
			int X=x+dx[k],Y=y+dy[k];
			if (s[X][Y]!='#') continue;
			merge2(id[x][y],id[X][Y]);
		}
		if (x==n||y==1)
			merge2(S,id[x][y]);
		if (x==1||y==m)
			merge2(T,id[x][y]);
		s[x][y]='#';
		X[++X[0]]=x;
		Y[X[0]]=y;
	}
	if (get2(S)==get2(T))
		return 0;
	vector<int> Vs,Vt;
	dfs(get2(S),Vs);
	dfs(get2(T),Vt);
	For(i,0,Vs.size()-1)
		For(j,0,Vt.size()-1){
			int a=Vs[i],b=Vt[j];
			if (a>b) swap(a,b);
			if (mp[a].find(b)!=mp[a].end())
				return 0;
		}
	For(i,1,X[0]){
		int x=X[i],y=Y[i];
		For(p,x-2,x+2) For(q,y-2,y+2){
			if (p<0||p>n+1||q<0||q>m+1) continue;
			if (get2(id[x][y])==get2(S)&&get2(id[p][q])==get2(T)) return 0;
			if (get2(id[x][y])==get2(T)&&get2(id[p][q])==get2(S)) return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	For(i,1,n) scanf("%s",s[i]+1);
	if (s[1][1]=='#'||s[n][m]=='#'){
		For(i,1,q) puts("NO");
		return 0;
	}
	S=++cnt; T=++cnt;
	For(i,2,n) id[i][0]=S,s[i][0]='#';
	For(i,1,m-1) id[n+1][i]=S,s[n+1][i]='#';
	For(i,2,m) id[0][i]=T,s[0][i]='#';
	For(i,1,n-1) id[i][m+1]=T,s[i][m+1]='#';
	For(i,1,n) For(j,1,m) id[i][j]=++cnt;
	For(i,1,cnt) fa[i]=i;
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='#')
			For(k,0,7){
				int x=i+dx[k],y=j+dy[k];
				if (s[x][y]=='#') merge(id[i][j],id[x][y]);
			}
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='.'){
			if (i+j==2) continue;
			if (i+j==n+m) continue;
			For(k,0,7){
				int x=i+dx[k],y=j+dy[k];
				if (s[x][y]!='#') continue;
				For(l,k+1,7){
					int X=i+dx[l],Y=j+dy[l];
					if (s[X][Y]!='#') continue;
					int a=get(id[x][y]),b=get(id[X][Y]);
					if (a==b) continue;
					if (a>b) swap(a,b);
					mp[a].insert(b);
				}
			}
		}
	For(i,1,cnt)
		if (get(i)==i) V[i].push_back(i);
	For(i,1,q){
		puts(solve()?"YES":"NO");
		fflush(stdout);
		For(j,1,X[0])
			s[X[j]][Y[j]]='.';
		X[0]=0;
		for (;top;top--){
			int x=sta[top];
			if (x>0) fa[x]=x;
			else V[-x].pop_back();
		}
	}
}