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
const int inf=100,N=100005,M=256;
int ans,tong[8][M],n,vis[8],d[N],alb[8][8],f[N][8],zt[N];
char ch[N];
ll tot;
vector<int> v[8];
void bfs(int id){
	queue<int> q; memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){if(ch[i]==id){d[i]=0; q.push(i);} else d[i]=inf;}
	while(q.size()){
		int t=q.front(); q.pop();
		if(!vis[ch[t]]){
		     vis[ch[t]]=1;
			for(auto j:v[ch[t]])if(d[j]==inf){d[j]=d[t]+1; q.push(j);}
		}
		if(t>1&&d[t-1]==inf){
			d[t-1]=d[t]+1; q.push(t-1);
		}
		if(t<n&&d[t+1]==inf){
			d[t+1]=d[t]+1; q.push(t+1);
		}
	}
	for(int i=1;i<=n;i++)f[i][id]=d[i];
}
inline int get(int x,int y){
	int mn=inf;
	for(int i=0;i<8;i++)mn=min(mn,f[x][i]+f[y][i]+1);
	return min(mn,abs(x-y));
}
int main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){ch[i]-='a'; v[ch[i]].push_back(i);}
	for(int i=0;i<8;i++){for(int j=0;j<8;j++)alb[i][j]=inf; bfs(i);}
	for(int i=1;i<=n;i++){
		for(int j=0;j<8;j++){
			alb[ch[i]][j]=min(alb[ch[i]][j],f[i][j]);
		}
	}
	/*for(int i=0;i<8;i++){for(int j=0;j<8;j++){
		wri(alb[i][j]);
	}puts("");}*/
	for(int i=1;i<=n;i++)for(int j=0;j<8;j++)if(f[i][j]>alb[ch[i]][j])zt[i]|=1<<j;
	for(int i=1;i<=n;i++){
		int t=max(i-15,1);
		for(int j=i-1;j>=t;j--){
			int t=get(i,j);
			if(t>ans){
				ans=t; tot=1;
			}else if(t==ans)tot++;
		}
		if(i<=16)continue;
		tong[ch[i-16]][zt[i-16]]++;
		for(int o=0;o<8;o++)for(int j=0;j<M;j++)if(tong[o][j]){
			int mn=inf;
			for(int k=0;k<8;k++)mn=min(alb[o][k]+(j>>k&1)+f[i][k]+1,mn); 
			//if(ch[i]==3&&j==zt[1]){for(int k=0;k<8;k++)cout<<alb[k][ch[i]]+(j>>k&1)+f[i][k]+1<<endl; cout<<mn<<endl; return 0;}
			if(mn>ans){
				ans=mn; tot=tong[o][j];
			}else if(mn==ans)tot+=tong[o][j];
		}
	}
	cout<<ans<<" "<<tot<<endl;
}