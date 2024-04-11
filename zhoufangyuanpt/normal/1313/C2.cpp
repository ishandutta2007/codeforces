#include<cstdio>
#include<cstring>
using namespace std;
int a[510000],sta[510000],top;
long long f[510000],ff[510000];
int ft[510000],fft[510000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	f[0]=0;sta[0]=0;
	f[1]=a[1];sta[top=1]=1;ft[1]=0;
	for(int i=2;i<=n;i++)
	{
		while(top>0&&a[sta[top]]>=a[i])top--;
		ft[i]=sta[top];
		f[i]=1ll*a[i]*(i-sta[top])+f[sta[top]];
		sta[++top]=i;
	}
	ff[n+1]=0;sta[0]=n+1;
	ff[n]=a[n];sta[top=1]=n;fft[n]=n+1;
	for(int i=n-1;i>=1;i--)
	{
		while(top>0&&a[sta[top]]>=a[i])top--;
		fft[i]=sta[top];
		ff[i]=1ll*a[i]*(sta[top]-i)+ff[sta[top]];
		sta[++top]=i;
	}
	long long ss=0,p;
	for(int i=1;i<=n;i++)
	{
		if(f[i]+ff[i]-a[i]>ss)
		{
			ss=f[i]+ff[i]-a[i];
			p=i;
		}
	}
	int i=p;
	while(i>0)
	{
		for(int j=i;j>ft[i];j--)a[j]=a[i];
		i=ft[i];
	}
	i=p;
	while(i<=n)
	{
		for(int j=i;j<fft[i];j++)a[j]=a[i];
		i=fft[i];
	}
	for(int i=1;i<n;i++)printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}