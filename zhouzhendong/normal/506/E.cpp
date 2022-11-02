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
const int N=205*2,mod=10007;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%mod)
		if (y&1)
			ans=ans*x%mod;
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
int n,m,k,d;
char s[N];
int dp[N][N][N],s0[N],s1[N];
LL tmp[N][N];
struct Mat{
	int v[N][N];
	Mat(){}
	Mat(int x){
		clr(v);
		For(i,1,d)
			v[i][i]=x;
	}
	friend Mat operator * (Mat a,Mat b){
		clr(tmp);
		For(i,1,d)
			For(j,1,d)
				For(k,1,d)
					tmp[i][j]+=a.v[i][k]*b.v[k][j];
		Mat c(0);
		For(i,1,d)
			For(j,1,d)
				c.v[i][j]=tmp[i][j]%mod;
		return c;
	}
}mat,mtk,Mtk;
Mat Pow(Mat x,int y){
	static Mat ans;
	ans=Mat(1);
	for (;y;y>>=1,x=x*x)
		if (y&1)
			ans=ans*x;
	return ans;
}
int main(){
	cin>>(s+1);
	m=strlen(s+1);
	n=read();
	k=n+m;
	dp[1][m][0]=1;
	Fod(len,m,2){
		For(i,1,m-len+1){
			int j=i+len-1;
			For(k,0,m){
				int v=dp[i][j][k];
				if (!v)
					continue;
				if (s[i]==s[j])
					Add(dp[i+1][j-1][k+1],v);
				else {
					Add(dp[i+1][j][k],v);
					Add(dp[i][j-1][k],v);
				}
			}
		}
	}
	For(i,0,m){
		s0[i]=0;
		For(j,1,m-1)
			Add(s0[i],dp[j+1][j][i]);
		s1[i+1]=0;
		For(j,1,m)
			Add(s1[i+1],dp[j][j][i]);
	}
	int c=(m+1)/2;
	d=m+c*2;
	mat=Mat(0);
	For(i,1,m){
		mat.v[i][i]=24;
		mat.v[i][i+1]=1;
	}
	For(i,m+1,m+c){
		mat.v[i][i]=25;
		mat.v[i][i+c]=1;
		mat.v[i+c][i+c]=26;
		if (i<m+c)
			mat.v[i][i+1]=1;
	}
	mtk=Pow(mat,(k+1)/2-1);
	Mtk=mtk*mat;
	int ans=0;
	For(i,1,c){
		int x=m+1-i*2,y=i;
		Add(ans,s1[i]*Mtk.v[m-x+1][m+y+c]%mod);
	}
	For(i,0,c){
		int x=m-i*2,y=i;
		if (k&1)
			Add(ans,s0[i]*mtk.v[m-x+1][m+y+c]%mod*26%mod);
		else
			Add(ans,s0[i]*Mtk.v[m-x+1][m+y+c]%mod);
	}
	cout<<ans<<endl;
	return 0;
}