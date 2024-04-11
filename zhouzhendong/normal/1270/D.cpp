#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
//const int mod=;
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=505;
int n,k;
pii query(vi v){
	printf("?");
	assert((int)v.size()==k);
	for (auto i : v)
		printf(" %d",i);
	puts("");
	fflush(stdout);
	int p=read(),pp=read();
	return mp(p,pp);
}
void Answer(int m){
	printf("! %d\n",m);
	fflush(stdout);
	exit(0);
}
int a[N];
vi s;
int main(){
	memset(a,-1,sizeof a);
	n=read(),k=read();
	if (k==1)
		Answer(1);
	vi v;
	int rp=0;
	{
		For(i,1,k)
			v.pb(i);
		For(i,k,n){
			pii res=query(v);
			a[res.fi]=res.se;
			s.pb(res.fi);
			if (i<n){
				for (auto &j : v)
					if (j==res.fi)
						j=i+1;
			}
			else
				rp=res.fi;
		}
	}//n-k+1
	sort(s.begin(),s.end(),[&](int x,int y){
		return a[x]<a[y];
	});
	outarr(s,0,(int)s.size()-1);
	if ((int)s.size()>=k){
		outtag();
		s.resize(k);
		pii p=query(s);
		For(i,0,k-1)
			if (p.fi==s[i])
				Answer(i+1);
		return 0;
	}
	int tp=rp==s.back()?0:rp==s[0]?1:0;
	int cnt=0;
	for (auto &i : v){
		if (a[i]==-1){
			if (tp==0){
				swap(i,s[0]);
				if (query(v).fi==rp)
					cnt++;
				swap(i,s[0]);
			}
			else {
				swap(i,s.back());
				if (query(v).fi!=rp)
					cnt++;
				swap(i,s.back());
			}
		}
	}
	Answer(cnt+1);
	return 0;
}