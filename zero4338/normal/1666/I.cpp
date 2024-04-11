#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=998244353;
int T;
int n,m;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
struct matrix
{
	int num[4][5];
	int*operator[](const int &i){return num[i];}
	void solve()
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<5;j++)if(num[i][j]<0)num[i][j]+=mod;
		for(int i=0;i<4;i++)
		{
			int pos=i;
			for(int j=i;j<4;j++)if(num[j][i]){pos=j;break;}
			swap(num[i],num[pos]);
			int inv=qpow(num[i][i],mod-2);
			for(int j=i;j<5;j++)num[i][j]=(ll)num[i][j]*inv%mod;
			for(int j=0;j<4;j++)
				if(j!=i&&num[j][i])
				{
					int tmp=num[j][i];
					for(int k=i;k<5;k++)(num[j][k]+=mod-(ll)num[i][k]*tmp%mod)%=mod;
				}
		
		}
	}
}A;
int scan(int x,int y){printf("SCAN %d %d\n",x,y);fflush(stdout);int ret;cin>>ret;return ret;}
int dig(int x,int y){printf("DIG %d %d\n",x,y);fflush(stdout);int ret;cin>>ret;return ret;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<4;i++)
			for(int j=0;j<5;j++)A[i][j]=0;
		for(int i=0;i<4;i++)A[i][0]=-1,A[i][1]=-1,A[i][2]=1,A[i][3]=1;
		A[0][4]=scan(1,1);
		A[1][4]=scan(1,m);
		A[0][0]+=2;A[0][1]+=2;A[0][4]+=4;
		A[1][0]+=2;A[1][4]+=2;A[1][3]-=2;A[1][4]-=2*m;
		int x=(A[0][4]+A[1][4])/4,y=(A[0][4]-A[1][4])/4;
		A[2][4]=scan(x,1);
		A[2][1]+=2;A[2][4]+=2;
		A[3][4]=scan(1,y);
		A[3][0]+=2;A[3][4]+=2;
		A.solve();
		if(dig(A[0][4],A[1][4]))dig(A[2][4],A[3][4]);
		else dig(A[0][4],A[3][4]),dig(A[2][4],A[1][4]);
	}
	return 0;
}