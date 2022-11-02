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
const int N=1000005;
int go[N][26],n,dep[N],nodecnt,sz[N];
vector<int> s[N];
vector<PI> v[N];
int Merge(int a,int b){
	if(!a||!b)return a|b;
	int k=++nodecnt;
	sz[k]=1;
	for(int i=0;i<26;i++){
		go[k][i]=Merge(go[a][i],go[b][i]);
		sz[k]+=sz[go[k][i]]; //cout<<go[a][i]<<" "<<go[b][i]<<" "<<go[k][i]<<endl;
	}
	//cout<<k<<" "<<a<<" "<<b<<" "<<sz[a]<<" "<<sz[b]<<endl;
	return k;
}
void dfs(int p,int fa){
	dep[p]=dep[fa]+1;
	s[dep[p]].push_back(p);
	for(auto i:v[p])if(i.first!=fa){
		dfs(i.first,p);
		sz[p]+=sz[i.first];
		go[p][i.second]=i.first;
	}
	sz[p]++;
}
PI ans;
int main(){
	n=read();  
 	for(int i=1;i<n;i++){
		int s=read(),t=read(); char ch=getchar()-'a';
		v[s].push_back(mp(t,ch));
		v[t].push_back(mp(s,ch));
	}
	dfs(1,0); ans.first=nodecnt=n;
	for(int i=n;i>1;i--)if(s[i].size()){
		int zs=n;
		for(auto j:s[i-1]){
			int t=0;
			for(int k=0;k<26;k++)if(go[j][k]){
				zs-=sz[go[j][k]];
				t=Merge(t,go[j][k]);
			}
			if(t)zs+=sz[t]-1;
		}
		//for(auto j:s[i])cout<<j<<" "; puts("");
		//cout<<i<<" "<<t<<" "<<s[i].size()<<" "<<sz[0]<<" "<<sz[t]<<" "<<zs<<endl;
		ans=min(ans,mp(zs,i));
	}
	cout<<ans.first<<endl<<ans.second-1<<endl;
}