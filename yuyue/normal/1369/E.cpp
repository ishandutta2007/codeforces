#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=(j);i<=(k);i++)
#define DF(i,j,k) for(int i=(j);i>=(k);i--)
#define M make_pair
#define P pair
#define dui priority_queue
#define SZ(x) ((int)x.size()-1)
using namespace std;
template<typename T>inline void read(T &n){
    T w=1;n=0;char ch=getchar();
    while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
    while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch^48);ch=getchar();}
    n*=w;
}
template<typename T>inline void write(T x){
    ull y=0;
    T l=0;
    if(x<0){x=-x;putchar('-');}
    if(!x){putchar(48);return;}
    while(x){y=y*10+x%10;x/=10;l++;}
    while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
    write(x);
    puts("");
}
template<typename T>inline void writes(T x){
    write(x);
    putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=a>b?a:b;}
template<typename T>inline void checkmin(T &a,T b){a=a<b?a:b;}
const int N=4e5+100;
vector<P<int,int> > v[N];
int w[N],d[N],ans[N],cnt;
bool h[N*2],vis[N];
void dfs(int x){
	vis[x]=1;
	F(i,0,SZ(v[x]))
		if(!vis[v[x][i].first]){
			ans[++cnt]=v[x][i].second;
			d[v[x][i].first]--;
		}
	F(i,0,SZ(v[x]))if(!vis[v[x][i].first]&&d[v[x][i].first]<=w[v[x][i].first])dfs(v[x][i].first);
}
int main(){
 	//freopen(".in","r",stdin);
 	//freopen(".out","w",stdout);
// 	cout<<v[1].size()<<endl;
 	int n,m;read(n);read(m);
 	for(int i=1;i<=n;i++)read(w[i]);
 	F(i,1,m){
 		int x,y;read(x);read(y);
 		d[x]++;
 		d[y]++;
 		v[x].push_back(M(y,i));
 		v[y].push_back(M(x,i));
 	}
 	for(int i=1;i<=n;i++)
	 	if(d[i]<=w[i]&&!vis[i])dfs(i);
	if(cnt<m)puts("DEAD");
	else {
		puts("ALIVE");
		DF(i,m,1)writes(ans[i]);
		puts("");
	}
    return 0;
}