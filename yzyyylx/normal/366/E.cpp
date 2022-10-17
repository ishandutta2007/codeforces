#include<bits/stdc++.h>
#define N 2005
using namespace std;

int m,n,k,len,hmx[10],cmx[10],hmn[10],cmn[10],s,ans,last,jl1,jl2,jl3,jl4;
bool jl[10][10];

int MAX(int a,int b,int c,int d)
{
	return max(max(a,b),max(c,d));
}

int main()
{
	ios_base::sync_with_stdio(0);
	int i,j;
	cin>>m>>n>>k>>len;
//	memset(xmn,2005,sizeof(xmn));
//	memset(ymn,2005,sizeof(ymn));
	
	for(i=1;i<=10;i++)
	{
		hmn[i]=cmn[i]=2005;
	}
//	return 0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>s;
//			num[i][j]=s;
			hmn[s]=min(hmn[s],i+j);
			hmx[s]=max(hmx[s],i+j);
			cmn[s]=min(cmn[s],j-i);
			cmx[s]=max(cmx[s],j-i);
		}
	}
	/*
	for(i=1;i<=k;i++)
	{
		cout<<hmn[i]<<" "<<hmx[i]<<" "<<cmn[i]<<" "<<cmx[i]<<endl;
	}
	return 0;
	//*/
	cin>>last;
	for(i=2;i<=len;i++)
	{
		cin>>s;
		if(jl[s][last]==false)
		{
			jl1=hmx[s]-hmn[last];
			jl2=cmx[s]-cmn[last];
			jl3=cmx[last]-cmn[s];
			jl4=hmx[last]-hmn[s];
			ans=max(ans,MAX(jl1, jl2, jl3, jl4));
			jl[s][last]=jl[last][s]=true;
		}
		last=s;
//		cout<<ans<<endl;
	}
	cout<<ans;
}
/*
| x1 - x2 | - | y1 - y2 |=4
one:
x1-x2+y1-y2   ---> (x1+y1) - (x2+y2)
two:
-(x1-x2) + (y1-y2)  --->  (x2-y2) - (x1-y1)
three:
(x1-x2) - (y1-y2)  ---> (x1-y1) - (x2-y2)
four:
-( x1-x2 ) - (y1-y2) ---> (x2+y2) - (x1+y1)
 
*/