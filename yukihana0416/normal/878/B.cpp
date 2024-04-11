#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,q,x[100010],a[100010],b[100010],t;
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l,r;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
	  {
	   if(!t || x[i]!=a[t])
	     {
	      a[++t]=x[i];
	      b[t]=1;
		 }
	   else
	     {
		  b[t]++;
		  if(b[t]==m)
		    t--;
		 }
	  }
	if(t==0)
	  printf("0\n");
	else
	  {
	   n=t;
	   for(i=1,j=0;i<=n;i++)
	     j+=b[i];
	   for(i=1,k=0;i<n+1-i;i++)
	     if(a[i]==a[n+1-i] && b[i]+b[n+1-i]==m)
		   k+=m;
		 else
		   break;
	   if(i<n+1-i)
	     {
		  if(a[i]==a[n+1-i] && b[i]+b[n+1-i]>m)
		    k+=m;
		    
	      p=(L)j*q-(L)k*(q-1);
		 }
	   else
	     {
		  p=(L)b[i]*q%m;
		  if(p)
		    p+=j-b[i];
		 }
		 if(n==1000 && m==2 && q==1000) cout <<j <<" " <<k <<endl;
	   cout<<p;
	  }
	return 0;
}