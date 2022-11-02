#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=10005;
int n;
map <int,int> mpa[N],mpb[N];
vector <int> a[N],b[N];
int p[N];
void Getp(vector <int> &A,vector <int> &B){
	static int ga[10][10],gb[10][10],ya[N],yb[N];
	clr(ga),clr(gb);
	memset(ya,-1,sizeof ya);
	memset(yb,-1,sizeof yb);
	int m=A.size(),cnt=1;
	for (int i=1;i<=m;i++)
		cnt*=i;
	for (int i=0;i<m;i++)
		ya[A[i]]=i;
	for (int i=0;i<m;i++)
		yb[B[i]]=i;
	for (int i=0;i<m;i++){
		int x=A[i];
		for (auto y : a[x])
			if (ya[y]!=-1)
				ga[i][ya[y]]=1;
	}
	for (int i=0;i<m;i++){
		int x=B[i];
		for (auto y : b[x])
			if (yb[y]!=-1)
				gb[i][yb[y]]=1;
	}
	vector <int> id(0);
	for (int i=0;i<m;i++)
		id.push_back(i);
	while (cnt--){
		int flag=1;
		for (int i=0;i<m&&flag;i++)
			for (int j=0;j<m&&flag;j++)
				if (ga[i][j]&&gb[id[i]][id[j]])
					flag=0;
		if (flag){
			for (int i=0;i<m;i++)
				p[A[i]]=B[id[i]];
			return;
		}
		next_permutation(id.begin(),id.end());
	}
	assert(0);
}
void vec_remove(vector <int> &v,int u){
	int flag=0;
	for (int i=0;i<(int)v.size();i++)
		if (v[i]==u){
			swap(v[i],v.back());
			v.pop_back();
			flag=1;
		}
	assert(flag);
}
vector <int> A,B;
int ctag[N];
int solve(){
	A.clear(),B.clear();
	int ra=0,rb=0;
	for (int i=1;i<=n;i++){
		if (!a[i].empty())
			A.push_back(i);
		if (!b[i].empty())
			B.push_back(i);
		if (a[i].size()>a[ra].size())
			ra=i;
		if (b[i].size()>b[rb].size())
			rb=i;
	}
	int m=A.size();
	if ((int)a[ra].size()+1==m||(int)b[rb].size()+1==m)
		return 0;
	if (m<=5)
		return Getp(A,B),1;
	if ((int)a[ra].size()+1==m-1){
		int ai=0;
		for (int i=0;i<m&&!ai;i++)
			if (a[A[i]].size()==1&&a[A[i]][0]!=ra)
				ai=A[i];
		int bi=0;
		for (int i=0;i<m&&!bi;i++)
			if (b[B[i]].size()==1)
				bi=B[i];
		p[ra]=bi;
		assert(!b[bi].empty());
		int bf=p[ai]=b[bi][0];
		int af=a[ai][0],afp=0;
		vec_remove(A,ra);
		vec_remove(A,ai);
		vec_remove(B,bi);
		vec_remove(B,bf);
		clr(ctag);
		for (auto by : b[bf])
			ctag[by]=1;
		for (int i=0;i<m-2&&!afp;i++)
			if (!ctag[B[i]])
				afp=B[i];
		p[af]=afp;
		vec_remove(A,af);
		vec_remove(B,afp);
		for (int i=0;i<m-3;i++)
			p[A[i]]=B[i];
		return 1;
	}
	if ((int)b[rb].size()+1==m-1){
		int ai=0;
		for (int i=0;i<m&&!ai;i++)
			if (a[A[i]].size()==1)
				ai=A[i];
		int bi=0;
		for (int i=0;i<m&&!bi;i++)
			if (b[B[i]].size()==1&&b[B[i]][0]!=rb)
				bi=B[i];
		p[ai]=rb;
		assert(!a[ai].empty());
		p[a[ai][0]]=bi;
		int af=a[ai][0];
		int bf=b[bi][0],bfp=0;
		vec_remove(B,rb);
		vec_remove(B,bi);
		vec_remove(A,ai);
		vec_remove(A,af);
		clr(ctag);
		for (auto ay : a[af])
			ctag[ay]=1;
		for (int i=0;i<m-2&&!bfp;i++)
			if (!ctag[A[i]])
				bfp=A[i];
		p[bfp]=bf;
		vec_remove(B,bf);
		vec_remove(A,bfp);
		for (int i=0;i<m-3;i++)
			p[A[i]]=B[i];
		return 1;
	}
	int xa=0,ya=0,xb=0,yb=0;
	int xza=0,yza=0,xzb=0,yzb=0;
	for (int i=0;i<m&&!xa;i++)
		if (a[A[i]].size()==1&&a[A[i]][0]!=ra)
			xa=A[i];
	if ((int)a[ra].size()+2==m-1){
		for (int i=0;i<m&&!ya;i++)
			if (a[A[i]].size()==1&&a[A[i]][0]==ra)
				ya=A[i];
	}
	else {
		for (int i=0;i<m;i++)
			if (a[A[i]].size()==1&&(a[A[i]][0]!=ra||!ya)&&a[A[i]][0]!=a[xa][0])
				ya=A[i];
	}
	for (int i=0;i<m&&!xb;i++)
		if (b[B[i]].size()==1&&b[B[i]][0]!=rb)
			xb=B[i];
	if ((int)b[rb].size()+2==m-1){
		for (int i=0;i<m&&!yb;i++)
			if (b[B[i]].size()==1&&b[B[i]][0]==rb)
				yb=B[i];
	}
	else {
		for (int i=0;i<m;i++)
			if (b[B[i]].size()==1&&(b[B[i]][0]!=rb||!yb)&&b[B[i]][0]!=b[xb][0])
				yb=B[i];
	}
	xza=a[xa][0];
	yza=a[ya][0];
	xzb=b[xb][0];
	yzb=b[yb][0];
	#define rm vec_remove
	#define rme(a,x,y) rm(a[x],y),rm(a[y],x)
	rme(a,xa,xza);
	rme(a,ya,yza);
	rme(b,xb,xzb);
	rme(b,yb,yzb);
	#undef rme
	#undef rm
	int res=solve();
	if (!res)
		return 0;
	if ((p[xza]==xzb&&mpa[xa][xza]&&mpb[xb][xzb])||(p[yza]==yzb&&mpa[ya][yza]&&mpb[yb][yzb]))
		swap(xb,yb),swap(xzb,yzb);
	assert(!(p[xza]==xzb&&mpa[xa][xza]&&mpb[xb][xzb])&&!(p[yza]==yzb&&mpa[ya][yza]&&mpb[yb][yzb]));
	p[xa]=xb,p[ya]=yb;
	return 1;
}
int main(){
	n=read();
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		a[x].push_back(y);
		a[y].push_back(x);
		mpa[x][y]=mpa[y][x]=1;
	}
	for (int i=1;i<n;i++){
		int x=read()-n,y=read()-n;
		b[x].push_back(y);
		b[y].push_back(x);
		mpb[x][y]=mpb[y][x]=1;
	}
	int res=solve();
	if (!res)
		puts("No");
	else {
		puts("Yes");
		for (int i=1;i<=n;i++)
			printf("%d ",p[i]+n);
	}
	return 0;
}