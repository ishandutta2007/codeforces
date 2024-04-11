//what? why "__int128" is banned?
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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (x>y)
		x=y;
}
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
const int N=600005,mask=(1<<30)-1;
const LL base=1e17;
int n;
char s[N];
int Log[N];
LL a[N],st[N][20];
int Fail[N],Link[N];
LL fuck26=0,fuck30=0,fuck1=0,fuck2=0;
LL sum=0;
map <int,int> S;
int querymin(int L,int R){
	int d=Log[R-L+1];
	return min(st[L+(1<<d)-1][d],st[R][d]);
}
int main(){
	n=read();
	For(i,2,n)
		Log[i]=Log[i/2]+1;
	For(i,1,n){
		scanf("%s%lld",s+i,&a[i]);
		s[i]='a'+(s[i]-'a'+fuck26)%26;
		a[i]=a[i]^(fuck30&mask);
		st[i][0]=a[i];
		For(j,1,19){
			st[i][j]=st[i][j-1];
			if (i-(1<<(j-1))>0)
				ckmin(st[i][j],st[i-(1<<(j-1))][j-1]);
		}
		int p=Fail[i-1];
		while (p&&s[p+1]!=s[i])
			p=Fail[p];
		if (p+1<i&&s[p+1]==s[i])
			p++;
		Fail[i]=p;
		Link[i-1]=s[i]==s[Fail[i-1]+1]?Link[Fail[i-1]]:Fail[i-1];
		for (p=i-1;p;){
			if (s[p+1]==s[i])
				p=Link[p];
			else {
				int val=querymin(i-p,i-1);
				sum-=val,S[val]--;
				p=Fail[p];
			}
		}
		int cnt=s[1]==s[i];
		while (!S.empty()&&prev(S.end())->fi>a[i]){
			cnt+=prev(S.end())->se;
			sum-=(LL)prev(S.end())->fi*prev(S.end())->se;
			S.erase(prev(S.end()));
		}
		sum+=(LL)cnt*a[i];
		S[a[i]]+=cnt;
		fuck26=(fuck26+sum)%26;
		fuck30=(fuck30+sum)&mask;
		fuck1+=sum;
		while (fuck1>=base)
			fuck1-=base,fuck2++;
		if (fuck2)
			printf("%lld%017lld\n",fuck2,fuck1);
		else
			printf("%lld\n",fuck1);
	}
	return 0;
}