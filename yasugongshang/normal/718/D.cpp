#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
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
const int N=100005;
int n,tot;
vector<int> v[N];
map<int,int> M[N];
set<int> ans;
map<vector<int>,int> S;
int dfs(int p,int fa){
	if(M[p].count(fa))return M[p][fa];
	vector<int> V;
	for(auto i:v[p])if(i!=fa)V.push_back(dfs(i,p));
	sort(V.begin(),V.end());
	if(S.count(V))return M[p][fa]=S[V];
	else return S[V]=M[p][fa]=++tot;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read(); 
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++)if(v[i].size()<4)ans.insert(dfs(i,0));
	cout<<ans.size()<<endl;
}