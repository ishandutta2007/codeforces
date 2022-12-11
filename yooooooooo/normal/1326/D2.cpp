#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,p[2000010],lik;
char ss[2000010],s[2000010];
void change()
{
	int cnt=1;
	s[0]='$';s[1]='#';
    for(int i=0;i<n;i++)s[++cnt]=ss[i],s[++cnt]='#';
    s[++cnt]='@';
}
void manacher()
{
	int m,i,ans=0,mx=0,rh,id=0,l,r,ty=0;
	p[0]=1;
	for(i=1;s[i];i++)
	{
		p[i]=1;
		if(i<=mx)p[i]=min(mx-i,p[2*id-i]);
		while(s[i-p[i]]==s[i+p[i]])p[i]++;
		if(i+p[i]>mx)
		{
			mx=i+p[i];
			id=i;
		}
	}
	m=2*n+1;
	lik=1;
	while(lik<m/2&&s[lik+1]==s[m-lik])lik++;
	for(int i=1;i<=m;i++)
	{
		rh=min(i-p[i],m-(i+p[i])+1);
		if(rh<=lik)
		{
			if(p[i]-1+(rh/2)*2>ans)
			{
				ans=p[i]-1+(rh/2)*2;
				ty=1;
				l=rh;r=i;ty=1;	
			}
		}
	}
	if(ty==0)
	{
		for(int i=l;i<=r;i++)
		{
			if(s[i]>='a'&&s[i]<='z')printf("%c",s[i]);
		}
	}
	else
	{
		for(int i=1;i<=l;i++)
		{
			if(s[i]>='a'&&s[i]<='z')printf("%c",s[i]);
		}
		for(int i=r-p[r]+1;i<=r+p[r]-1;i++)
		{
			if(s[i]>='a'&&s[i]<='z')printf("%c",s[i]);
		}
		for(int i=m-l+1;i<=m;i++)
		{
			if(s[i]>='a'&&s[i]<='z')printf("%c",s[i]);
		}
	}
	printf("\n");
}
int T;
int main()
{
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%s",ss);
		n=strlen(ss);
		change();
		manacher();
	}
	return 0;
}