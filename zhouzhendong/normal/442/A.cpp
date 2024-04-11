#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
					For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){	
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
const int N=105;
int n;
char a[N][10];
map <char,int> mp;
int main(){
	n=read();
	For(i,1,n)
		scanf("%s",a[i]);
	mp['R']=0;
	mp['G']=1;
	mp['B']=2;
	mp['Y']=3;
	mp['W']=4;
	mp['1']=5;
	mp['2']=6;
	mp['3']=7;
	mp['4']=8;
	mp['5']=9;
	int ans=10;
	For(i,0,1023){
		int t[10];
		int cnt=0;
		For(j,0,9){
			cnt+=i>>j&1;
			t[j]=i>>j&1;
		}
		int flag=1;
		For(x,1,n)
			For(y,1,n)
				if (a[x][0]!=a[y][0]||a[x][1]!=a[y][1]){
					if (a[x][0]==a[y][0]){
						if (!t[mp[a[x][1]]]&&!t[mp[a[y][1]]])
							flag=0;
					}
					else if (a[x][1]==a[y][1]){
						if (!t[mp[a[x][0]]]&&!t[mp[a[y][0]]])
							flag=0;
					}
					else {
						if (!t[mp[a[x][0]]]&&
							!t[mp[a[y][0]]]&&
							!t[mp[a[x][1]]]&&
							!t[mp[a[y][1]]])
							flag=0;
					}
				}
		if (flag)
			ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}