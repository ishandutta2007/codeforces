//CF 167 B
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
int n,k,l;
struct p
{
	 double a[210][210][410];
	 p()
	 {
	 	memset(a,0,sizeof a);
	 }
	 void add(int i,int j,int k,double v)
	 {
	 	if(k<-n)
	 		k=-n;
	 	if(k>n)
	 		k=n;
	 	a[i][j][k+200]+=v;
	 }
	 double get(int i,int j,int k)
	 {
	 	if(k<-n)
	 		k=-n;
	 	if(k>n)
	 		k=n;
	 	return a[i][j][k+200];
	 }
};
p f;
double q[10010];
int a[10010];
int main()
{
	int i,j,o,x;
	scanf("%d%d%d",&n,&l,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q[i]=x/100.;
	}
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f.add(0,0,k,1);
	for(i=0;i<n;i++)
		for(j=0;j<=n;j++)
			for(o=-n;o<=n;o++)
			{
				f.add(i+1,j+1,o+a[i+1],f.get(i,j,o)*q[i+1]);
				f.add(i+1,j,o,f.get(i,j,o)*(1-q[i+1]));
			}
	double ans=0;
	for(i=l;i<=n;i++)
		for(j=0;j<=n;j++)
			ans+=f.get(n,i,j);
	printf("%.6lf\n",ans);
	return 0;
}