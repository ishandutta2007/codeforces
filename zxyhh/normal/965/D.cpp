#include<cstdio>
int n,a[100005],l;
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<n;i++) scanf("%d",&a[i]);
	int Min=1E9+7,sum=0;
	for(int i=1;i<=l;i++) sum+=a[i];
	if (sum<Min) Min=sum;
	for(int i=l+1;i<n;i++) sum+=a[i]-a[i-l],Min=sum<Min?sum:Min;
	if (sum<Min) Min=sum;
	printf("%d\n",Min); 
}