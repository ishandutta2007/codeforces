#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=66,N=M*M;
int m,a[M],s[M],n,d[M];
int dp[M][M][N],la[M][M][N];
void gets(int x,int y,int z){
	if (!x) return ;
	s[x-1]=la[x][y][z];
	gets(x-1,a[y]!=s[x-1] ? y-1 : y,z-a[y]);
}
bool g[M][M];
int main(){
	m=read();
	F(i,1,m) a[i]=read();
	sort(a+1,a+m+1);
	dp[0][0][0]=1;
	int lin=N-100;
	F(i,0,62){
		int lim=i*(i-1)/2;
		F(j,0,m){
			F(k,lim,lin){
				if (dp[i][j][k]){
					if (j<m) dp[i+1][j+1][a[j+1]+k]=1,la[i+1][j+1][a[j+1]+k]=a[j];
					if (j) dp[i+1][j][a[j]+k]=1,la[i+1][j][a[j]+k]=a[j];
				}
			}
		}
		if (dp[i][m][lim]){
			n=i;
			s[n]=a[m];
			gets(i,m,lim);
			break;
		}
	}
	if (!n){
		puts("=)");
		return 0;
	}
	cout<<n<<"\n";
//	F(i,1,n){
//		cout<<s[i]<<"\n";
//	}
	F(i,1,n){
		d[i]=i-1;
		F(j,1,i-1) g[i][j]=1;
	}
	int i=1;
	while (1){
		while (s[i]==d[i] && i<=n) i++;
		if (i==n+1) break;
		int j=i;//s[i]>d[i]
		while (d[j]==d[j+1]) j++;
		int k=j+1;
		while (d[k]<=s[k]) k++;//d[k]>s[k]
		F(x,1,n){
			if (x^k && x^j && g[k][x] && g[x][j]){
				g[x][j]=0; g[j][x]=1; 
				g[k][x]=0; g[x][k]=1;
				d[j]++; d[k]--;
				break;
			}
		}
	}
	F(i,1,n){
		F(j,1,n){
			cout<<g[i][j];
		}
		cout<<"\n";
	}
	return 0; 
}