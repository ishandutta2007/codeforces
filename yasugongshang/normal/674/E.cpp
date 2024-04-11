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
const int N=500005;
int father[N],tot;
double dp[N][101];
inline void solve(int nod,int dep){
	if(!father[nod]||dep>=100)return; solve(father[nod],dep+1);
	dp[father[nod]][dep+1]/=0.5*(dp[nod][dep]+1);
}
int main(){
	int q=read(); tot=1; for(int i=0;i<=100;i++)dp[tot][i]=1;
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==1){
			father[++tot]=read(); 
			solve(father[tot],0);
			dp[father[tot]][0]/=2;
			for(int i=0;i<=100;i++)dp[tot][i]=1;
			//cout<<dp[2][0]<<endl;
			for(int i=father[tot],j=0;father[i]&&j<100;i=father[i],j++){
				dp[father[i]][j+1]*=0.5*(dp[i][j]+1);
			}
		}else{
			int p=read();
			double ans=0;
			//cout<<dp[2][0]<<endl;
			for(int i=1;i<=100;i++)ans+=(dp[p][i]-dp[p][i-1])*i;
			printf("%.7lf\n",ans);
		}
	}
}