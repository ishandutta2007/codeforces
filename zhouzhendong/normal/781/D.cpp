#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=505;
const LL INF=1000000000000000000LL;
int n,m;
struct Mat{
	bitset <N> v[N];
	Mat(){}
	Mat(int x){
		for (int i=1;i<=n;i++)
			v[i].reset();
		for (int i=1;i<=n;i++)
			v[i][i]=x;
	}
	friend Mat operator * (Mat a,Mat b){
		Mat ans(0);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a.v[i][j])
					ans.v[i]|=b.v[j];
		return ans;
	}
}M[2][35];
int main(){
	n=read(),m=read();
	M[0][0]=M[1][0]=Mat(0);
	for (int i=1;i<=m;i++){
		int a=read(),b=read(),t=read();
		M[t][0].v[a][b]=1;
	}
	int k=0;
	while (M[0][k].v[1].count()&&(1LL<<(k<<1))<=INF){
		k++;
		M[0][k]=M[0][k-1]*M[1][k-1]*M[1][k-1]*M[0][k-1];
		M[1][k]=M[1][k-1]*M[0][k-1]*M[0][k-1]*M[1][k-1];
	}
	LL s=0,p=0;
	Mat now(0);
	now.v[1][1]=1;
	while (k>0&&s<=INF){
		k--;
		if ((now*M[p][k]).v[1].count()){
			now=now*M[p][k];
			s+=1LL<<(k<<1);
			p^=1;
			if ((now*M[p][k]).v[1].count()){
				now=now*M[p][k];
				s+=1LL<<(k<<1);
				if ((now*M[p][k]).v[1].count()){
					now=now*M[p][k];
					s+=1LL<<(k<<1);
					p^=1;
				}
			}
		}
	}
	if (s>INF)
		puts("-1");
	else
		cout << s << endl;
	return 0;
}