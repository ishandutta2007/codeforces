#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=3005;
int n,m,f[N][N],g[N][N],tot,q[N];
char ch[N][N];
ll ans;
vector<int> de[N<<1];
void clear(){
	for(int i=1;i<=tot;i++)de[q[i]].clear(); tot=0;
}
#define lowbit(i) i&-i
struct BIT{
	int tot,sz,c[N],q[N];
	inline int size(){
		return sz;
	}
	inline void change(int pos,int de){
		if(de>0)q[++tot]=pos; sz+=de;
		for(int i=pos;i<N;i+=lowbit(i))c[i]+=de;
	}
	inline int getsum(int pos){
		int ans=0; pos=max(pos,0);
		for(int i=pos;i;i-=lowbit(i))ans+=c[i];
		return ans;
	}
	void clear(){
		for(int i=1;i<=tot;i++){
			for(int j=q[i];j<N;j+=lowbit(j))c[j]=0;
		}
		sz=tot=0;
	}
}T;
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		gets(ch[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]=='z')ch[i][j]=1; else ch[i][j]=0;
			f[i][j]=ch[i][j]?f[i][j-1]+1:0;
			//h[i][j]=ch[i][j]?h[i-1][j-1]+1:0;
		}
		for(int j=m;j;j--)g[i][j]=ch[i][j]?g[i][j+1]+1:0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=i&&j<=n;j++){
			int x=j,y=1+i-j;
			if(ch[x][y]){		
				de[f[x][y]+x].push_back(x); q[++tot]=f[x][y]+x;
				for(unsigned j=0;j<de[x].size();j++)T.change(de[x][j],-1);
				T.change(x,1);
				ans+=T.size()-T.getsum(x-g[x][y]);
				//cout<<x<<" "<<y<<" "<<T.size()-T.getsum(x-g[x][y])<<" "<<de[x].size()<<" "<<f[x][y]<<endl;
			}else T.clear(),clear();
		}
		T.clear(); clear();
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n&&i+m-j>0;j++){
			int x=j,y=i+m-j;
			if(ch[x][y]){
				de[f[x][y]+x].push_back(x); q[++tot]=f[x][y]+x;
				for(unsigned j=0;j<de[x].size();j++)T.change(de[x][j],-1);
				T.change(x,1);
				ans+=T.size()-T.getsum(x-g[x][y]);
				//cout<<x<<" "<<y<<" "<<T.size()-T.getsum(x-g[x][y])<<" "<<de[x][0]<<" "<<min(f[x][y],g[x][y])+x<<endl;
			}else T.clear(),clear();
		}
		T.clear(); clear();
	}
	cout<<ans<<endl;
}
/*
i-j<f[j]&&i-g[i]<j
*/