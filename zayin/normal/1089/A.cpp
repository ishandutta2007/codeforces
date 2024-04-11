#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

typedef long long LL;

const int maxn=1e5+5;

int a,b;
pair<int,int> ans[10],pt[10];

int q;
int main()
{
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d %d",&a,&b);
		
		int ansa=-10, ansb=0, resa=0, resb=0;
		fo(i,0,3)
			fo(j,0,3) if ((i==3 || j==3) && i+j<=5)
			{
				int aa=a, bb=b, fuck=0, fucknum=0;
				if (i==3)
				{
					fo(k,1,j) pt[k]=make_pair(0,25);
					fo(k,1,i) pt[k+j]=(k+j==5) ?make_pair(15,0) :make_pair(25,0);
					resa=j*23, resb=(j==2) ?59 :69 ;
					aa-=(j==2) ?65 :75, bb-=j*25;
				} else
				{
					fo(k,1,i) pt[k]=make_pair(25,0);
					fo(k,1,j) pt[k+i]=(k+i==5) ?make_pair(0,15) :make_pair(0,25);
					resb=i*23, resa=(i==2) ?59 :69 ;
					aa-=i*25, bb-=(i==2) ?65 :75 ;
				}
				if (aa<0 || bb<0) continue;
				if (aa>resa || bb>resb)
				{
					if (aa-resa>bb-resb)
					{
						fo(k,1,i+j) if (pt[k].first<pt[k].second) {fuck=k; break;}
					} else
					{
						fo(k,1,i+j) if (pt[k].first>pt[k].second) {fuck=k; break;}
					}
					if (!fuck) fuck=1;
					fucknum=max(aa-resa,bb-resb);
					aa-=fucknum, bb-=fucknum;
					if (aa<0 || bb<0) continue;
					if (pt[fuck].first<pt[fuck].second && aa<23) continue;
						else if (pt[fuck].first>pt[fuck].second && bb<23) continue;
				}
				fo(k,1,i+j) if (pt[k].first>pt[k].second && bb)
				{
					int now=min((k==5 ?13 :23),bb);
					pt[k].second=now, bb-=now;
				} else if (pt[k].first<pt[k].second && aa)
				{
					int now=min((k==5 ?13 :23),aa);
					pt[k].first=now, aa-=now;
				}
				if (fuck) pt[fuck].first+=fucknum, pt[fuck].second+=fucknum;
				if (i-j>ansa-ansb)
				{
					ansa=i, ansb=j;
					fo(k,1,i+j) ans[k]=pt[k];
				}
			}
		
		if (ansa==-10) puts("Impossible"); else
		{
			printf("%d:%d\n",ansa,ansb);
			fo(i,1,ansa+ansb) printf("%d:%d ",ans[i].first,ans[i].second);
			puts("");
		}
	}
}