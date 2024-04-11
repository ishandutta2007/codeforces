#include <stdio.h>
#include <stdlib.h>
#define eps 1e-10

int n,i,tot,s,now,kind[500005];
double l,v1,v2,max,t2,time,pos[100005];
double ans[100005],a[500005];

int bj(double a,double b);
void sort(int l,int r);

int main()
{
    scanf("%d %lf %lf %lf",&n,&l,&v1,&v2);
    time=l/(v1+v2);
    max=time*v2;
    t2=l*2/v1;
    for(i=1;i<=n;i++)
    {
		scanf("%lf",&pos[i]);
    	if (bj(pos[i],max)<0)
    	{
			a[++tot]=0,kind[tot]=1;
			a[++tot]=(max-(pos[i]))/v1,kind[tot]=-1;
			a[++tot]=t2-(pos[i])/v1,kind[tot]=1;
			a[++tot]=t2,kind[tot]=-1;
		}
		else
		{
			a[++tot]=(l*2-pos[i])/v1,kind[tot]=1;
			tot++,a[tot]=a[tot-1]+max/v1,kind[tot]=-1;
		}
	}
	sort(1,tot);
	for(i=1;i<=tot;)
	{
		now=i;
		if (i!=1)
			ans[s]+=((a[i]-a[i-1])/t2);
		while (bj(a[now],a[i])==0)
			s+=kind[now],now++;
		i=now;
	}
	ans[0]=1;
	for(i=1;i<=n;i++)
		ans[0]-=ans[i];
	for(i=0;i<=n;i++)
		printf("%.12lf\n",ans[i]);
    return 0;
}

void sort(int l,int r)
{
     int i=l,j=r,k,mid,midk;
     double mida,temp;
     mid=l+rand()%(r-l+1);
     mida=a[mid];
     midk=kind[mid];
     while (i<=j)
     {
           while (i<=j && (bj(a[i],mida)==-1 || (bj(a[i],mida)==0 && kind[i]<midk))) i++;
           while (i<=j && (bj(a[j],mida)==1 || (bj(a[j],mida)==0 && kind[j]>midk))) j--;
           if (i<=j)
           {
              k=kind[i],kind[i]=kind[j],kind[j]=k;
              temp=a[i],a[i]=a[j],a[j]=temp;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}

int bj(double a,double b)
{
	if (a-b>0-eps && a-b<eps) return 0;
	if (a>b) return 1;
	return -1;
}