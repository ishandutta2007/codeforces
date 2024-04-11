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
const int N=105;
int n;
struct cmp{
	bool operator () (string a,string b){
		if (a.size()!=b.size())
			return a.size()<b.size();
		return a<b;
	}
};
typedef multiset <string,cmp> ms;
ms query(int L,int R){
	ms res;
	if (L>R)
		return res;
	printf("? %d %d\n",L,R);
	fflush(stdout);
	string s;
	For(_,1,(R-L+2)*(R-L+1)/2){
		cin>>s;
		sort(s.begin(),s.end());
		res.insert(s);
	}
	return res;
}
void answer(char *s){
	printf("! ");
	For(i,1,n)
		putchar(s[i]);
	puts("");
	fflush(stdout);
	exit(0);
}
char s[N];
int main(){
	n=read();
	if (n==1)
		s[1]=(*query(1,1).begin())[0],answer(s);
	int mid=n/2;
	ms s0=query(1,mid-1);
	ms s1=query(1,mid);
	ms s2=query(1,n);
	for (auto i : s0)
		s1.erase(s1.find(i));
	{
		int p=mid;
		string las="";
		for (auto i : s1){
			vi cnt(26,0);
			for (auto c : i)
				cnt[c-'a']++;
			for (auto c : las)
				cnt[c-'a']--;
			For(i,0,25)
				if (cnt[i]){
					s[p--]='a'+i;
					break;
				}
			las=i;
		}
	}
	string ss=*prev(s2.end()),sl=*prev(s1.end());
	outval(sl);
	vi cs(26,0);
	for (auto c : ss)
		cs[c-'a']++;
	for (auto c : sl)
		cs[c-'a']--;
	outarr(cs,0,3);
	s2.insert("");
	Fod(i,n,mid+1){
		string now="";
		For(i,0,25)
			For(j,1,cs[i])
				now+='a'+i;
		if (i==mid+1){
//			outval(now);
			assert(now.size()==1);
			s[i]=now[0];
			answer(s);
		}
		Fod(j,mid,1){
			sort(now.begin(),now.end());
			s2.erase(s2.find(now));
			now+=s[j];
		}
		sort(now.begin(),now.end());
		s2.erase(s2.find(now));
		string snxt=*prev(s2.end());
		vi cnt(26,0);
		for (auto c : snxt)
			cnt[c-'a']++;
		for (auto c : sl)
			cnt[c-'a']--;
		For(c,0,25)
			if (cnt[c]!=cs[c]){
				s[i]='a'+c;
				break;
			}
		cs=cnt;
	}
	return 0;
}