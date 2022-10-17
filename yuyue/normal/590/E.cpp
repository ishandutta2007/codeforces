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
const int M=1e7+10,N=1550,E=N*N/4; 
string str[M]; 
int t[M][2],fail[M],tot,id[M]; 
void ins(string c,int x){
	int len=c.size(),p=0;
	F(i,0,len-1){
		int o=c[i]-'a';
		if (!t[p][o]) t[p][o]=++tot; 
		p=t[p][o];
	}
	id[p]=x; 
}
int q[M];
void build(){
	int l=1,r=0; 
	if (t[0][0]) q[++r]=t[0][0]; 
	if (t[0][1]) q[++r]=t[0][1]; 
	while (l<=r){
		int x=q[l++];
		if (t[x][0]){
			fail[t[x][0]]=t[fail[x]][0];
			q[++r]=t[x][0]; 
		}
		else t[x][0]=t[fail[x]][0];
		if (t[x][1]){
			fail[t[x][1]]=t[fail[x]][1];
			q[++r]=t[x][1]; 
		}
		else t[x][1]=t[fail[x]][1];
		if (!id[x]) id[x]=id[fail[x]];
	} 
}
bitset<N/2> c[N];
int n;
int to[E],nxt[E],head[N],cnt,w[E],S,T,fr[E];  
void add(int x,int y,int fl){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; w[cnt]=fl; fr[cnt]=x;
}
int dep[N];
bool bfs(bool out){
	ms(dep,0); int l=1,r=1; q[1]=S; dep[S]=1;
	while (l<=r){
		int x=q[l++];
//		cout<<x<<"   fuc\n";
		for (int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if (w[i] && !dep[y]){
				dep[y]=dep[x]+1;
				q[++r]=y;
			}
		}
	}
	return dep[T];
}
int cur[N]; 
int dfs(int x,int flow){
	if (x==T || !flow) return flow;
	int res=flow;  
	for (int &i=cur[x];i;i=nxt[i]){
		int y=to[i]; 
		if (w[i] && dep[y]==dep[x]+1){
			int ff=dfs(y,min(res,w[i]));
			w[i]-=ff; w[i^1]+=ff;
			res-=ff; 
			if (!res) return flow; 
		}
	}
	return flow-res;
}
int mf(){
	int ret=0;
	while (bfs(0)){
		memcpy(cur,head,sizeof cur); 
		ret+=dfs(S,1e9); 
	}
	return ret;
}
bool iS(int x){
	return dep[x];
}
bool ind[N];
int main(){
	ios::sync_with_stdio(0); 
	cin>>n; cnt=1;
	F(i,1,n){
		cin>>str[i];
		ins(str[i],i);  
	}
	build();
	F(i,1,n){
		int p=0;
		F(j,0,SZ(str[i])){
			p=t[p][str[i][j]-'a'];
			if (id[p]) c[id[p]][i]=1;
			if (id[fail[p]]) c[id[fail[p]]][i]=1; 
//			cout<<i<<" <<-- "<<id[p]<<" "<<id[fail[p]]<<"  fuck \n"; 
		}
	}
//	F(i,1,n) F(j,1,n) if (c[j][i]) c[j]|=c[i]; 
	S=0; T=2*n+1;
	F(i,1,n){
		F(j,1,n){
			if (i==j) continue; 
			if (c[i][j]) add(j,i+n,1e9),add(i+n,j,0);//,cout<<j<<" -> "<<i+n<<"  fuck \n";
		}
		add(S,i,1); add(i,S,0); 
		add(i+n,T,1); add(T,i+n,0); 
		add(i+n,i,1e9); add(i,i+n,0);
	}
	int ans=n-mf(); bfs(1);
	F(i,2,cnt){
		if (fr[i]<to[i] && (fr[i]==S || to[i]==T)){
//			cout<<fr[i]<<" "<<to[i]<<" "<<w[i]<<" "<<iS(fr[i])<<" "<<iS(to[i])<<"   ggg \n"; 
			if (w[i] || iS(fr[i])==iS(to[i])){
				if (fr[i]==S) ind[to[i]]=1;
				else ind[fr[i]]=1; 
			}
//			else {
////				cout<<(fr[i]==S ? to[i] : fr[i])<<" mincover \n";
//			}
		}
	}	
	cout<<ans<<"\n"; 
	F(i,1,n) if (ind[i] && ind[i+n]) cout<<i<<" ";
	return 0;
}