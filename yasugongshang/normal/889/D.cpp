#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<ll,ll>
#define fi first
#define se second
#define ld long double
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
inline void writeln(ll a){write(a); putchar('\n');}
inline void wri(ll a){write(a); putchar(' ');}
const int N=100005;
int x[N],y[N],lx,ly,Ans;
set<pair<int,int> > M;
ll q[N];
PI ans[N];
bool vis[N];
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
	}
	int ho=0;
	if(n%2==0){
		n--; ho=1;
	}
	for(int i=1;i<=n;i++){
		ll tx=ho?x[i]+x[n+1]:x[i]*2,ty=ho?y[i]+y[n+1]:y[i]*2;
		if(M.count(mp(tx,ty)))continue; else M.insert(mp(tx,ty));
		ll sumx=0,sumy=0;
		for(int j=1;j<=n;j++)if(i!=j){sumx+=x[j]; sumy+=y[j];}
		if(sumx!=tx*((n-1)/2)||sumy!=ty*((n-1)/2)){
			ll S=ty*(n-1)/2-sumy,T=sumx-tx*(n-1)/2; *q=0; 
			for(int j=1;j<=n;j++)if(i!=j)q[++*q]=(x[j])*S+(y[j])*T;
			sort(&q[1],&q[*q+1]);
			int f=1;
			ll t=tx*S+ty*T;
			for(int j=1;j<=*q/2&&f;j++)if(q[j]+q[*q-j+1]!=t)f=0;
			if(f)ans[Ans++]=mp(S,T);
		}else{
			int fff=1; vis[i]=1;
			for(int j=1;j<=n;j++)if(!vis[j]){
				int f=1;
				for(int k=j+1;k<=n&&f;k++)if(x[k]+x[j]==tx&&y[k]+y[j]==ty&&!vis[k]){
					vis[k]=vis[j]=1; f=0; 
				}
				if(f){
					fff=0;
					for(int k=j;k<=n;k++)if(!vis[k]){
						ll S=y[j]+y[k]-ty,T=tx-x[j]-x[k]; *q=0;
						
						for(int l=j;l<=n;l++)if(!vis[l]){
							q[++*q]=S*x[l]+T*y[l];
						}
						sort(&q[1],&q[*q+1]);
						
						ll t=tx*S+ty*T;
						int f=1;
						for(int j=1;j<=*q/2&&f;j++)if(q[j]+q[*q-j+1]!=t)f=0; //cout<<f<<" "<<j<<" "<<k<<" "<<S<<" "<<T<<endl;
						if(f)ans[Ans++]=mp(S,T);
					}
					break;
				}
			}
			if(fff){
				puts("-1"); return 0;
			}
		}
	}
	int tot=0;
	for(int i=0;i<Ans;i++){
		int f=1;
		for(int j=0;j<i&&f;j++)if(ans[i].fi*ans[j].se==ans[i].se*ans[j].fi)f=0;
		tot+=f;
	}
	cout<<tot<<endl;
}