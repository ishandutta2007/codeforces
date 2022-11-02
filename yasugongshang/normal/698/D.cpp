#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=1005;
int n,k,f,X[8],Y[8],x[N],y[N],vis[10];
ll di[8][N];
vector<int> v[8][N];
bitset<N>bj;
ll dis(ll a,ll b,ll c,ll d){
	return (c-a)*(c-a)+(d-b)*(d-b);
}
bool tx(ll a,ll b,ll c,ll d){
	return a*d==b*c;
}
void dfs(int p,stack<int> q){//cout<<p<<" "<<q.size()<<" "<<vis[1]<<" "<<vis[2]<<" "<<(q.size()?v[1][q.top()].size():-1)<<endl;
	if(q.size()>k-p+1)return;
	if(!q.size())f=1; if(f)return;
	if(p>k)return;
	For(i,1,k)if(!vis[i]){
		vis[i]=1;
		stack<int> jb=q; jb.pop();// cout<<(v[i][q.top()].size()?v[i][q.top()][0]:-1)<<endl;
		for(auto j:v[i][q.top()])if(!bj[j]){jb.push(j); bj[j]=1;}
		dfs(p+1,jb); 
		vis[i]=0;
		while(jb.size()>=q.size()){bj[jb.top()]=0;  jb.pop(); }
	}
}
int main(){
	k=read(),n=read();
	For(i,1,k){X[i]=read(); Y[i]=read();}
	For(i,1,n){x[i]=read(); y[i]=read(); For(j,1,k)di[j][i]=dis(X[j],Y[j],x[i],y[i]);}
	For(i,1,k){
		For(j,1,n){
			for(int o=1;o<=n&&v[i][j].size()<k;o++)if(tx(x[j]-X[i],y[j]-Y[i],x[o]-X[i],y[o]-Y[i])&&di[i][o]<di[i][j]&&di[i][j]>dis(x[j],y[j],x[o],y[o]))v[i][j].pb(o);
		}
	}
	//cout<<tx(x[1]-X[1],y[1]-Y[1],x[2]-X[1],y[2]-Y[1])<<" "<<di[1][2]<<" "<<di[1][1]<<endl;
	//cout<<x[3]-X[1]<<" "<<y[3]-Y[1]<<" "<<x[2]-X[1]<< " "<<y[2]-Y[1]<<" "<<v[1][3][0]<<" "<<v[2][4].size()<<endl;
	int ans=0;
	For(i,1,n){
		stack<int> q;
		q.push(i); f=0;
		dfs(1,q); ans+=f;
	}
	cout<<ans<<endl;
}