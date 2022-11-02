#include <bits/stdc++.h>
#define y1 __zzd001
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=0,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
const int N=205;
int n,m;
string ans[205][205][4][4],Ans[205][205];
int sc[N][N][4][4],Sc[N][N];
vector <char> v;
string getnum(int x){
	v.clear();
	if (!x)
		return "0";
	string ans="";
	while (x>0)
		v.push_back('0'+x%10),x/=10;
	while (!v.empty())
		ans+=v.back(),v.pop_back();
	return ans;
}
vector <pair <int,int> > wi4,wi5;
int main(){
	wi4.clear(),wi5.clear();
	for (int i=0;i<=200;i++)
		for (int j=0;j<=200;j++){
			if ((i==25&&j<=23)||(i>25&&j==i-2)){
				wi4.push_back(make_pair(i,j));
				wi4.push_back(make_pair(j,i));
			}
			if ((i==15&&j<=13)||(i>15&&j==i-2)){
				wi5.push_back(make_pair(i,j));
				wi5.push_back(make_pair(j,i));
			}
		}
	for (int i=0;i<=200;i++)
		for (int j=0;j<=200;j++)
			for (int t1=0;t1<=3;t1++)
				for (int t2=0;t2<=3;t2++)
					ans[i][j][t1][t2]="Impossible",sc[i][j][t1][t2]=-10000;
	ans[0][0][0][0]="0:0\n";
	sc[0][0][0][0]=0;
	for (int t1=0;t1<3;t1++)
		for (int t2=0;t1+t2<5&&t2<3;t2++)
			for (int i=0;i<=200;i++)
				for (int j=0;j<=200;j++){
					if (sc[i][j][t1][t2]<-10)
						continue;
					int k1,k2;
					if (t1+t2<4){
						for (auto k : wi4){
							int _i=i+k.fi,_j=j+k.se;
							if (_i<=200&&_j<=200){
								k1=t1,k2=t2;
								if (k.fi>k.se) k1++; else k2++;
								if (sc[_i][_j][k1][k2]<0){
									sc[_i][_j][k1][k2]=0;
									ans[_i][_j][k1][k2]=ans[i][j][t1][t2];
									ans[_i][_j][k1][k2][0]='0'+k1;
									ans[_i][_j][k1][k2][2]='0'+k2;
									ans[_i][_j][k1][k2]+=getnum(k.fi);
									ans[_i][_j][k1][k2]+=':';
									ans[_i][_j][k1][k2]+=getnum(k.se);
									ans[_i][_j][k1][k2]+=' ';
								}
							}
						}
					}
					else {
						for (auto k : wi5){
							int _i=i+k.fi,_j=j+k.se;
							if (_i<=200&&_j<=200){
								k1=t1,k2=t2;
								if (k.fi>k.se) k1++; else k2++;
								if (sc[_i][_j][k1][k2]<0){
									sc[_i][_j][k1][k2]=0;
									ans[_i][_j][k1][k2]=ans[i][j][t1][t2];
									ans[_i][_j][k1][k2][0]='0'+k1;
									ans[_i][_j][k1][k2][2]='0'+k2;
									ans[_i][_j][k1][k2]+=getnum(k.fi);
									ans[_i][_j][k1][k2]+=':';
									ans[_i][_j][k1][k2]+=getnum(k.se);
									ans[_i][_j][k1][k2]+=' ';
								}
							}
						}
					}
				}
	for (int i=0;i<=200;i++)
		for (int j=0;j<=200;j++){
			Ans[i][j]="Impossible";
			Sc[i][j]=-10000;
			for (int t1=0;t1<=3;t1++)
				for (int t2=0;t2<=3;t2++){
					if (t1<3&&t2<3)
						continue;
					if (t1+t2>5)
						continue;
					if (sc[i][j][t1][t2]<0)
						continue;
					if (t1-t2>Sc[i][j])
						Sc[i][j]=t1-t2,Ans[i][j]=ans[i][j][t1][t2];
				}
		}
	int T=read();
	while (T--){
		int a=read(),b=read();
		cout << Ans[a][b] << endl;
	}
	return 0;
}