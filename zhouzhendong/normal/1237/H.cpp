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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=4005;
int n;
int a[N],b[N];
int ta[N],tb[N];
int get(int *a,int i){
	return a[i*2]*2+a[i*2-1];
}
int R(int x){
	return (x&1)<<1|(x>>1);
}
void gettatb(){
	For(i,1,n){
		ta[i]=get(a,i);
		tb[i]=get(b,i);
	}
}
vi resa,resb;
void upda(int x){
	resa.pb(x);
	reverse(a+1,a+x*2+1);
	gettatb();
}
void updb(int x){
	resb.pb(x);
	reverse(b+1,b+x*2+1);
	gettatb();
}
void solve(){
	{
		string s,t;
		cin>>s>>t;
		n=s.size();
		For(i,0,n-1)
			a[i+1]=s[i]-'0',b[i+1]=t[i]-'0';
	}
	n/=2;
	resa.clear(),resb.clear();
	gettatb();
	{
		vi ca(4),cb(4);
		For(i,1,n){
			ca[ta[i]]++;
			cb[tb[i]]++;
		}
		if (ca[0]!=cb[0]||ca[3]!=cb[3]||ca[1]+ca[2]!=cb[1]+cb[2])
			return puts("-1"),void();
	}
	srand(114514);
	Fod(i,n,1){
		For(j,i+1,n){
			if (ta[j]!=tb[j]){
				For(t,1,n*2){
					putchar('0'+a[t]);
				}puts("");
				For(t,1,n*2){
					putchar('0'+b[t]);
				}puts("");
				For(t,i*2+1,n*2){
					putchar('0'+a[t]);
				}puts("");
				For(t,i*2+1,n*2){
					putchar('0'+b[t]);
				}puts("");
				while (1);
			}
			assert(ta[j]==tb[j]);
		}
//		outval(i);
		if (ta[i]==tb[i])
			continue;
		if (ta[i]==R(tb[1])){
			updb(i);
			continue;
		}
		if (tb[i]==R(ta[1])){
			upda(i);
			continue;
		}
		if (ta[1]==tb[1]){
			upda(i),updb(i);
			continue;
		}
		if (ta[i]==0||ta[i]==3){
			vi pos;
			For(j,1,i)
				if (tb[j]==ta[i])
					pos.pb(j);
			int j=pos[rand()%pos.size()];
			updb(j),updb(i);
			continue;
		}
		if (tb[i]==0||tb[i]==3){
			vi pos;
			For(j,1,i)
				if (ta[j]==tb[i])
					pos.pb(j);
			int j=pos[rand()%pos.size()];
			upda(j),upda(i);
			continue;
		}
		if (ta[1]==tb[i]){
			upda(1),upda(i);
			continue;
		}
		if (tb[1]==ta[i]){
			updb(1),updb(i);
			continue;
		}
		assert(i>1);
//		outtag(1);
		vi pa,pb;
		For(j,1,i-1){
			if (ta[j]==tb[i])
				pa.pb(j);
			if (tb[j]==ta[i])
				pb.pb(j);
		}
		if (!pa.empty()||!pb.empty()){
			if (pa.size()>pb.size()){
				int j=pa[rand()%pa.size()];
				upda(j),upda(i);
			}
			else {
				int j=pb[rand()%pb.size()];
				updb(j),updb(i);
			}
			continue;
		}
//		outtag(2);
		int flag=0;
		For(j,1,i-1){
			if (R(ta[j])==tb[i]&&R(ta[j+1])==tb[i-1]){
				upda(j+1),upda(2),upda(i);
				flag=1;
				break;
			}
			if (R(tb[j])==ta[i]&&R(tb[j+1])==ta[i-1]){
				updb(j+1),updb(2),updb(i);
				flag=1;
				break;
			}
		}
		if (flag)
			continue;
//		outtag(3);
		pa.clear(),pb.clear();
		For(j,1,i){
			if (ta[j]==ta[i])
				pa.pb(j);
			if (tb[j]==tb[i])
				pb.pb(j);
		}
		if (pa.size()>pb.size()){
			int j=pa[rand()%pa.size()];
			upda(j),upda(1),upda(i);
		}
		else {
			int j=pb[rand()%pb.size()];
			updb(j),updb(1),updb(i);
		}
	}
	For(i,1,n*2)
		assert(a[i]==b[i]);
	cout<<resa.size()+resb.size()<<endl;
	for (auto i : resa)
		printf("%d ",i*2);
	reverse(resb.begin(),resb.end());
	for (auto i : resb)
		printf("%d ",i*2);
	puts("");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}