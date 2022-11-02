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
const int N=1005*2;
int n,k,cnt=0;
bitset <N> v[N],x[N];
int y[N];
char s[4]={'.','R','Y','B'};
vi getset(){
	int n=read();
	vi res;
	while (n--)
		res.pb(read()-1);
	return res;
}
int res[N],pos[N];
int main(){
	n=read(),k=read();
	For(i,0,n*2-1)
		v[i][i]=1;
	while (k--){
		string s;
		cin>>s;
		vi a=getset();
		if (s=="mix"){
			cin>>s;
			int t=-1;
			if (s=="W")
				t=0;
			else if (s=="R")
				t=1;
			else if (s=="Y")
				t=2;
			else if (s=="B")
				t=3;
			For(d,0,1){
				y[cnt]=t>>d&1;
				for (auto i : a)
					x[cnt]^=v[i*2+d];
				cnt++;
			}
		}
		else if (s=="RY"){
			for (auto i : a)
				swap(v[i*2],v[i*2+1]);
		}
		else if (s=="RB"){
			for (auto i : a)
				v[i*2+1]^=v[i*2];
		}
		else if (s=="YB"){
			for (auto i : a)
				v[i*2]^=v[i*2+1];
		}
	}
//	For(i,0,cnt-1){
//		outarr(x[i],0,n*2-1);
//		outval(y[i]);
//	}
	int r,c;
	for (r=0,c=0;r<cnt&&c<n*2;r++,c++){
		For(j,r,cnt-1)
			if (x[j][c]==1){
				swap(x[j],x[r]);
				swap(y[j],y[r]);
				break;
			}
		if (x[r][c]==0){
			r--;
			continue;
		}
		pos[r]=c;
		For(j,r+1,cnt-1)
			if (x[j][c]==1)
				x[j]^=x[r],y[j]^=y[r];
	}
	For(i,r,cnt-1)
		if (y[i])
			return puts("NO"),0;
	clr(res);
	Fod(i,r-1,0){
		res[pos[i]]=y[i];
		Fod(j,i-1,0)
			if (x[j][pos[i]]==1)
				y[j]^=y[i];
	}
	puts("YES");
	For(i,0,n-1)
		putchar(s[res[i*2]+res[i*2+1]*2]);
	puts("");
	return 0;
}