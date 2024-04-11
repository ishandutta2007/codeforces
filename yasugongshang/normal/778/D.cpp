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
const int N=55;
char a[N][N],b[N][N];
vector<PI> ans;
int n,m;
void cao(int x,int y){
	ans.push_back(mp(x,y));
	if(a[x][y]=='L'){
		a[x][y]=a[x][y+1]='U';
		a[x+1][y]=a[x+1][y+1]='D';
	}else{
		a[x][y]=a[x+1][y]='L';
		a[x][y+1]=a[x+1][y+1]='R';
	}
}
void solve(int x,int y,char ch){
	//cout<<x<<" "<<y<<" "<<ch<<endl<<(a[4]+1)<<endl<<(a[5]+1)<<endl<<(a[6])+1<<endl;
	if(a[x][y]==ch)return;
	if(a[x][y]=='L'){
		solve(x+1,y,'L');
		cao(x,y);
		solve(x,y,ch);
	}else if(a[x][y]=='R'){
		solve(x+1,y,'R');
		cao(x,y-1);
		solve(x,y,ch);
	}else if(a[x][y]=='U'){
		
		if(ch=='L'){
			solve(x,y+1,'U');
			cao(x,y);
			solve(x,y,ch);
		}else{
			solve(x,y-1,'U');
			cao(x,y-1);
			solve(x,y,ch);
		}
	}
	/*if(a[x][y]=='U'&&ch=='L'){
		solve(x,y+1,'U');
		cao(x,y);
	}else if(a[x][y]=='U'&&ch=='R'){
		solve(x,y-1,'U');
		cao(x,y);
	}else if(a[x][y]=='L'&&ch=='U'){
		solve(x+1,y,'L');
		cao(x,y);
	}else if(a[x][y]=='R'&&ch=='L'){
		solve(x+1,y,'R');
		cao(x,y);
		solve(x,y,'L');
	}else if(a[x][y]=='L'&&ch=='R'){
		solve(x+1,y,'L');
		cao(x,y);
		solve(x,y,'R');
	}*/
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	for(int i=1;i<=n;i++){
		scanf("%s",b[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!=b[i][j]){
				solve(i,j,b[i][j]);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.first); writeln(i.second);
	}
}