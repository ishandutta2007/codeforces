#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-9,pi=acos(-1.);
struct point
{
	long long x,y;
	bool operator <(const point &temp)const
	{
	    if(x==temp.x)
	        return y<temp.y;
		return x<temp.x;
	}
};
double adj[5201][5201];
int ix[5201][5201];
point pt[5500],now;
int n,num[5201],per[5201];
bool no[5201][5201];
vector<point>candi;
void norm(double &theta)
{
	while(theta<-eps)
		theta+=pi;
	while(theta>pi-eps)
	    theta-=pi;
}
bool binary(int left,int right,point now)
{
	int mid;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(pt[mid]<now)
		   left=mid+1;
		else if(now<pt[mid])
		   right=mid-1;
		else
		   return true;
	}
	return false;
}
bool check(point awp)
{
	int i,j,s,p,q,left,right,mid;
    for(int ii=0;ii<2*n;ii++)
    {
    	i=per[ii];
    	left=0;
    	right=num[i]-1;
    	double theta=atan2(awp.y-pt[i].y,awp.x-pt[i].x);
    	norm(theta);
    	while(left<=right)
    	{
    		mid=(left+right)>>1;
    		if(adj[i][mid]<theta-eps)
    		    left=mid+1;
    		else if(theta<adj[i][mid]-eps)
    		    right=mid-1;
    		else
    		    break;
    	}
    	if(left>right)
    	     return false;
    }
    return true;
}
void inter(point a,point b,point c,point d)
{
	long long A,B;
	A=(b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
	B=(c.x-a.x)*(d.y-c.y)-(c.y-a.y)*(d.x-c.x);
	if(A==0)
	    return;
	if(B*(b.x-a.x)%A!=0||(B*(b.y-a.y))%A!=0)
	    return;
//	ru1=B/A;
	now.x=a.x+B*(b.x-a.x)/A;
	now.y=a.y+B*(b.y-a.y)/A;
	
    if(abs(now.x)>1e6||abs(now.y)>1e6)
        return; 
    if(binary(0,2*n-1,now))
       return;
    candi.push_back(now);
   // if(check(now))
    //{
    //	puts("Yes");
    //	printf("%lld %lld\n",now.x,now.y);
    //	exit(0);
   // }
}
int main()
{
	scanf("%d",&n);
	int i,j,s,p,q;
	for(i=0;i<2*n;i++)
		scanf("%lld%lld",&pt[i].x,&pt[i].y);
	sort(pt,pt+2*n);
	for(i=0;i<2*n;i++)
	{
		num[i]=0;
		for(j=0;j<2*n;j++)
		{
			if(j==i)
			   continue;
			ix[i][num[i]]=j;
			adj[i][num[i]++]=atan2(1.*pt[j].y-pt[i].y,pt[j].x-pt[i].x);
			norm(adj[i][num[i]-1]);
		}
		//printf("i=%d\n),i;
		sort(adj[i],adj[i]+num[i]);
		int u=0;
		for(j=0;j<num[i];)
		{
			for(s=j;s<num[i];s++)
			{
				if(fabs(adj[i][j]-adj[i][s])>eps)
				    break;
			}
			if((s-j)==1)
			    adj[i][u++]=adj[i][j];	 
		    else
		    {
		    	for(p=j;p<s;p++)
		    	    no[i][ix[i][j]]=true;
		    }
			j=s;
		} 
		num[i]=u;
	}
	for(i=0;i<2*n;i++)
	   per[i]=i; 
	for(i=1;i<2*n;i++)
	   for(j=2;j<2*n;j++)
	   {
	   	    if(i==j)
	   	       continue;
	   	    int id[4];
	   	    id[0]=0; 
	   	    if(i>1)
	   	    {
	   	       id[1]=1;
	   	       id[2]=i;
	   	       id[3]=j;
			}
			else
			{
	   	       id[1]=2;
	   	       if(j==2)
	   	          continue;
	   	       id[2]=i;
	   	       id[3]=j; 
	      	}
	      	if(no[id[0]][id[2]]||no[id[1]][id[3]])
	      	    continue; 
	      	inter(pt[id[0]],pt[id[2]],pt[id[1]],pt[id[3]]); 
	   }
	sort(candi.begin(),candi.end()); 
	random_shuffle(per,per+n);
	for(i=candi.size()-1;i>=0;i--)
	{
		if(i&&!(candi[i-1]<candi[i]))
		    continue; 
		if(check(candi[i]))
		{
			puts("Yes");
			printf("%lld %lld\n",candi[i].x,candi[i].y);
			return 0;
		}
	}//
	puts("No");
	return 0;
}