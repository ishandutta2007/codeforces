#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=110,oo=1000000000;
int i,j,k,l,p,n,m,ch,ans;
int f[N][N][2];
struct cc {
	int a,l;
	bool operator < (const cc &n) const {
		return a<n.a;
	}
} A[N];
void Up(int &x,const int &y) {
	if (y>x) x=y;
}
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d%d",&A[i].a,&A[i].l);
	sort(A+1,A+n+1);
	A[0].a=-oo;
	memset(f,-1,sizeof f);
	f[0][0][0]=0;
	for (i=0;i<n;i++)
		for (j=0;j<=i;j++)
			for (k=0;k<2;k++) if (f[i][j][k]!=-1) {
				int Pos=A[j].a+k*A[j].l;
				int ma=Pos,t1=j,t2=k;
				for (l=i+1;l<=n;l++) {
					for (p=0;p<2;p++) {
						int pos=A[l].a+p*A[l].l;
						if (pos>ma) ma=pos,t1=l,t2=p;
						int tmp=min(pos-Pos,A[l].l)+ma-pos;
						Up(f[l][t1][t2],f[i][j][k]+tmp); 
					}
				}
			}
	for (j=1;j<=n;j++) Up(ans,f[n][j][0]),Up(ans,f[n][j][1]);
	printf("%d\n",ans);
}