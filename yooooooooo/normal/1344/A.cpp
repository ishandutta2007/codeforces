#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int T,n,a[100005],ok;
set<int>st;
set<int>::iterator it;
int M(int x,int y){return (x%y+y)%y;}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
	
		scanf("%d",&n);
		st.clear();ok=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			int res=M(a[i]+i,n);
			it=st.find(res);
			if(it!=st.end())ok=1;
			st.insert(res);
		}
		if(ok)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}