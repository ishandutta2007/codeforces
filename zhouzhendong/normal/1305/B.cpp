#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=1005;
int n;
char s[N];
vi lp,rp,res;
int main(){
	cin>>s+1;
	n=strlen(s+1);
	For(i,1,n){
		if (s[i]=='(')
			lp.pb(i);
		else
			rp.pb(i);
	}
	reverse(lp.begin(),lp.end());
	while (!lp.empty()&&!rp.empty()&&lp.back()<rp.back()){
		res.pb(lp.back()),lp.pop_back();
		res.pb(rp.back()),rp.pop_back();
	}
	if (res.empty())
		puts("0");
	else {
		puts("1");
		sort(res.begin(),res.end());
		cout<<res.size()<<endl;
		for (auto i : res)
			printf("%d ",i);
		puts("");
	}
	return 0;
}