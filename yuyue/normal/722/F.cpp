#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
LL lcm(LL x,LL y){
	return x/__gcd(x,y)*y;
}
struct node{
	int x,y;
};
vector<node> pf[50];
LL pw[50][50];
void init(){
	F(o,1,40){
		int x=o;
		for (int i=2;i*i<=x;i++){
			int ind=0;
			while (x%i==0) ind++,x/=i;
			if (ind) pf[o].pb({i,ind});
		}
		if (x>1) pf[o].pb((node){x,1});
	}
	F(i,1,40){
		pw[i][0]=1;
		F(j,1,40) pw[i][j]=pw[i][j-1]*i;
	}
}
struct Dynamic_Lcm{
	int h[41][10],mx[50];
	LL now=1;
	void add(int X){
//		cout<<"add "<<X<<"\n";
		for (auto O:pf[X]){
			int x=O.x,y=O.y;
			if (y>mx[x]) now=now*pw[x][y-mx[x]],mx[x]=y;
			h[x][y]++;
		}
	}
	void del(int X){
		for (auto O:pf[X]){
//			cerr<<"del "<<X<<"\n";
			int x=O.x,y=O.y;
			h[x][y]--;
			while (mx[x] && !h[x][mx[x]]){
				mx[x]--;
				now/=x;
			}
		}
	}
}Lcm;
const int M=2e5+10;
vector<node> v[M];
LL d;
void Exgcd(LL a,LL b,LL &x,LL &y){
	if (!b) {
		d=a;
		x=1;
		y=0;
		return ;
	}
	Exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
LL mul(LL x,LL y,LL mod){
	LL ret=0;
	int sig=(y<0); y=abs(y);
	for (;y;y>>=1,x=(x+x)%mod) if (y&1) ret=(ret+x)%mod;
	return (sig ? -ret : ret);
}
LL mm,aa;
bool Combine(LL a1,LL m1,LL a2,LL m2){
	LL k1,k2;
	Exgcd(m1,m2,k1,k2);
	if ((a2-a1)%d!=0) return 0;
	mm=m1/d*m2;
	LL ti=(a2-a1)/d%mm;
	k1=mul(k1,ti,mm);
	aa=(mul(k1,m1,mm)+a1)%mm;
	aa=(aa+mm)%mm;
	return 1;
}
void cesi(){
	int ret=Combine(0,4,3,4);
	cout<<"OK : "<<ret<<"\n";
	cout<<" = "<<aa<<" mod "<<mm<<"\n";
	exit(0);
}
int n,m,num[M];
int main(){
//	freopen("cycle.in","r",stdin);
//	freopen("cycle.out","w",stdout);
	init(); 
//	cesi();
	n=read(); m=read();
	F(i,1,n){
		num[i]=read();
		F(j,0,num[i]-1){
			int x=read();
			v[x].pb((node){i,j});
		}
	}
	F(col,1,m){
		int las=-1,ans=0,j=1;
		for (auto O:v[col]){
			int ps=O.x,rem=O.y;
//			cerr<<ps<<" "<<las<<" "<<num[ps]<<" "<<rem<<" "<<mm<<" "<<aa<<"    oooo\n";
			if (ps!=las+1){			
//				cerr<<j<<" "<<las<<"   omg \n";
				while (j<=las) Lcm.del(num[j]),j++;
				j=ps;
				mm=num[ps];
				aa=rem;
				Lcm.add(num[ps]);
			}
			else{
				while (1){
					bool ret=Combine(aa,mm,rem,num[ps]);
					if (!ret){
//						assert(Lcm.now==mm);
//						cerr<<Lcm.now<<" "<<aa<<" "<<j<<"       ppp\n";
						Lcm.del(num[j]);
						mm=Lcm.now;
						aa%=mm;
						j++;
					}
					else break;
				}
				Lcm.add(num[ps]);
			}
			las=ps;
			ans=max(ans,ps-j+1);
//			cerr<<"----\n";
		}
		while (j<=las) Lcm.del(num[j]),j++;
		cout<<ans<<"\n";
	}
	return 0;
}