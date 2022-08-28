#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#define SIZE 500005
#define SQR 700
#define MX 800

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

set <P> st[MX];
set <P>::iterator it;
ll add[MX],A[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		st[i/SQR].insert(P(a,i));
		A[i]=a;
	}
	int sz=(n-1)/SQR;
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			l--;r--;
			int L=l/SQR,R=r/SQR;
			if(L==R)
			{
				while(l<=r)
				{
					st[L].erase(P(A[l],l));
					A[l]+=x;
					st[L].insert(P(A[l],l));
					l++;
				}
			}
			else
			{
				bool ok=l%SQR==0;
				while(l%SQR!=0)
				{
					st[L].erase(P(A[l],l));
					A[l]+=x;
					st[L].insert(P(A[l],l));
					l++;
				}
				if(!ok) L++;
				ok=(r+1)%SQR==0;
				while((r+1)%SQR!=0)
				{
					st[R].erase(P(A[r],r));
					A[r]+=x;
					st[R].insert(P(A[r],r));
					r--;
				}
				if(!ok) R--;
				while(L<=R) add[L++]+=x;
			}
		}
		else
		{
			ll y;
			scanf("%I64d",&y);
			int left=-1,right=-1;
			for(int j=0;j<=sz;j++)
			{
				it=st[j].lower_bound(P(y-add[j],-1));
				if(it!=st[j].end())
				{
					P p=*it;
					if(p.first==y-add[j])
					{
						left=p.second;
						break;
					}
				}
			}
			if(left==-1) puts("-1");
			else
			{
				for(int j=sz;j>=0;j--)
				{
					it=st[j].upper_bound(P(y-add[j]+1,-1));
					if(it!=st[j].begin());
					{
						it--;
						P p=*it;
						if(p.first==y-add[j])
						{
							right=p.second;
							break;
						}
					}
				}
				printf("%d\n",right-left);
			}
		}
	}
	return 0;
}