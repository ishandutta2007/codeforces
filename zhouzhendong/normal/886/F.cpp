#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
#define double long double
const double Eps=1e-6;
int Dcmp(double x){
	if (fabs(x)<Eps)
		return 0;
	return x<0?-1:1;
}
const int N=2005;
int n;
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){x=_x,y=_y;}
	friend Point operator + (Point A,Point B){return Point(A.x+B.x,A.y+B.y);}
	friend Point operator - (Point A,Point B){return Point(A.x-B.x,A.y-B.y);}
	friend Point operator * (Point A,double x){return Point(A.x*x,A.y*x);}
	friend Point operator / (Point A,double x){return Point(A.x/x,A.y/x);}
	friend bool operator == (Point A,Point B){
		return !Dcmp(A.x-B.x)&&!Dcmp(A.y-B.y);
	}
	friend bool operator < (Point A,Point B){
		if (Dcmp(A.x-B.x))
			return A.x<B.x;
		return A.y<B.y;
	}
}p[N],G(0,0);
int vis[N];
void del(){
	int _n=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
			p[++_n]=p[i];
	n=_n;
}
Point ans[N];
int tot=0;
multiset <double> S;
multiset <double> :: iterator sp;
void solve(Point L){
	L=Point(L.y,-L.x);
	double Sin=L.y/sqrt(L.x*L.x+L.y*L.y);
	double Cos=L.x/sqrt(L.x*L.x+L.y*L.y);
//	cout << L.x << " " << L.y << endl;
//	cout << "Sin = " << Sin << ", Cos = " << Cos << endl;
	if (Sin<0)
		Sin=-Sin,Cos=-Cos;
	if (fabs(Sin)<Eps)
		Sin=fabs(Sin),Cos=fabs(Cos);
	S.clear();
	double dG=L.x*G.x+L.y*G.y;
//	cout << "dG = " << dG << endl;
	for (int i=1;i<=n;i++){
		double d=L.x*p[i].x+L.y*p[i].y;
//		cout << "d" << i << " = " << d << endl;
		if (!Dcmp(d-dG))
			continue;
		sp=S.lower_bound(dG*2-d-1e-7);
		if (sp!=S.end()&&!Dcmp(d+*sp-dG*2))
			S.erase(sp);
		else
			S.insert(d);
	}
	if (S.empty())
		ans[++tot]=Point(Sin,Cos);
//	for (auto d : S)
//		cout << d << " ";
//	cout << "\n------------------------\n";
}
int Main(){
	n=read();
	for (int i=1;i<=n;i++){
		p[i].x=read(),p[i].y=read();
		G=G+p[i];
	}
	G=G/n;
	for (int i=1;i<=n;i++){
		if (vis[i])
			continue;
		for (int j=1;j<=n;j++)
			if (G*2-p[i]==p[j]){
				vis[i]=vis[j]=1;
				break;
			}
	}
	del();
	if (!n)
		return puts("-1"),0;
	for (int i=1;i<=n;i++)
		solve((p[1]+p[i])/2-G);
	sort(ans+1,ans+tot+1);
	int res=min(tot,1);
	for (int i=2;i<=tot;i++)
		if (!(ans[i]==ans[i-1]))
			res++;
	cout << res << endl;
	return 0;
}
int main(){
	int T=1;
	while (T--){
		tot=0;
		G=Point(0,0);
		Main();
	}
}
/*
4
2 4
1 2
0 0
-2 -4
*/