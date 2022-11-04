#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
using namespace std;
const int N=205;
int n;
struct Mat{
	double a[N][N];
	Mat(){
		memset(a,0,sizeof(a));
	}
	void init(){
		For(i,1,n) a[i][i]=1;
	}
	Mat operator *(const Mat &b)const{
		Mat c;
		For(i,1,n) For(j,1,n) For(k,1,n)
			c.a[i][k]+=a[i][j]*b.a[j][k];
		return c;
	}
}big[105],small[105];
struct P{
	int x,y;
	P operator -(const P &a){
		return (P){x-a.x,y-a.y};
	}
	int operator *(const P &a){
		return x*a.y-y*a.x;
	}
}p[N];
bool vis[N][N];
vector<vector<int>> lines;
vector<int> be[N];
double val[N],tmp[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	For(i,1,n) For(j,i+1,n) if (!vis[i][j]){
		vector<int> line;
		For(k,1,n)
			if ((p[k]-p[i])*(p[k]-p[j])==0)
				line.push_back(k);
		for (auto &x:line)
			be[x].push_back((int)lines.size());
		for (auto &x:line)
			for (auto &y:line)
				vis[x][y]=1;
		lines.push_back(line);
	}
	small[0].init();
	For(i,0,n) for (auto &t:be[i]){
		double tmp=1.0/be[i].size()/lines[t].size();
		for (auto &j:lines[t])
			small[1].a[i][j]+=tmp;
	}
	For(i,2,100) small[i]=small[i-1]*small[1];
	big[0].init(); big[1]=small[100];
	For(i,2,100) big[i]=big[i-1]*big[1];
	int Q; scanf("%d",&Q);
	while (Q--){
		int t,m;
		scanf("%d%d",&t,&m); m--;
		memset(val,0,sizeof(val));
		For(i,1,n) For(j,1,n)
			val[i]+=big[m/100].a[i][j]*small[m%100].a[j][t];
		double ans=0;
		for (auto &line:lines){
			double now=0;
			for (auto &x:line)
				now+=val[x];
			now/=line.size();
			ans=max(ans,now);
		}
		printf("%.15lf\n",ans);
	}
}