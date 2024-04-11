#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
const int N=300005;
int n,m,tt,tong[N],pos[N],vis[N],dist[N],last[N],tot,an[N],que[N];
queue<int> q;
vector<int> v[N];
vector<int>::iterator it;
bitset<N> s[N/50];
inline bool count(int a,int b){
	if(v[a].size()>100)return s[pos[a]][b]; else if(v[b].size()>100)return s[pos[b]][a];
	it=lower_bound(v[a].begin(),v[a].end(),b); return it!=v[a].end()&&*it==b;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
		if(s==1||t==1)tong[s+t-1]=1;
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	for(int i=1;i<=n;i++)if(v[i].size()>100){
		pos[i]=++tt;
		for(unsigned j=0;j<v[i].size();j++)s[tt][v[i][j]]=1;
	}
	q.push(1); vis[1]=1;
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(unsigned i=0;i<v[t].size();i++)if(!vis[v[t][i]]){
			vis[v[t][i]]=1; q.push(v[t][i]); dist[v[t][i]]=dist[t]+1; last[v[t][i]]=t;
		}
	}
	int ans=vis[n]?dist[n]:1e9,pos;
	for(int i=2;i<=n;i++)if(vis[i]&&!tong[i]&&dist[i]+2<ans){
		ans=min(ans,dist[i]+2); pos=i;
	}
	ll sum=0;
	if(ans>5){
		for(int i=2;i<=n;i++)if(tong[i]){
			int tot=0;
			for(unsigned j=0;j<v[i].size();j++)if(tong[v[i][j]])que[++tot]=v[i][j];
			for(int j=1;j<=tot;j++)for(int k=j+1;k<=tot;k++)if(!count(que[j],que[k])){
				cout<<5<<endl<<1<<" "<<que[j]<<" "<<i<<" "<<que[k]<<" "<<que[j]<<" "<<n<<endl; return 0;
			}
		}
	}
	if(ans<=n){
		if(vis[n]&&dist[n]==ans){
			for(int i=n;i;i=last[i]){
				an[++tot]=i;
			}
		}else{
			an[++tot]=n; an[++tot]=1; an[++tot]=pos; an[++tot]=last[pos]; an[++tot]=1;
		}
		writeln(tot-1);
		for(int i=tot;i;i--){
			write(an[i]); putchar(' ');
		}
	} else puts("-1");
}
/*
5 5
1 2
1 3
1 4
2 3
3 4
*/