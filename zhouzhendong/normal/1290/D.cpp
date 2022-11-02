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
const int N=1024+5;
int n,k;
int Ask(int c){
	if (c==-1)
		return 0;
	printf("? %d\n",c+1);
	fflush(stdout);
	string s;
	cin>>s;
	return s=="Y";
}
void R(){
	printf("R\n");
	fflush(stdout);
}
void Answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int a[N],las,b,c;
void Ins_block(int c){
	int cnt=0;
	For(i,c*b,(c+1)*b-1)
		if (!a[i]){
			a[i]|=Ask(i);
			las=i;
		}
		else
			++cnt;
	while (cnt--)
		Ask(las);
}
int main(){
	n=read(),k=read();
	b=max(k/2,1),c=n/b;
	For(s,0,c-1){
		if (c>1&&c/2-(s>=c/2)<=0)
			continue;
		int t=s;
		las=-1;
		Ins_block(t);
		For(i,1,c/2-(s>=c/2)){
			if (i&1)
				t=(t+i)%c;
			else
				t=(t-i+c)%c;
			Ins_block(t);
		}
		R();
	}
	int ans=0;
	For(i,0,n-1)
		if (!a[i])
			ans++;
	Answer(ans);
	return 0;
}