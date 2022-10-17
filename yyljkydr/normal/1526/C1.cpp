#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int a[N];

multiset<int>s;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	long long S=0;
	for(int i=1;i<=n;i++)
	{
		if(S+a[i]>=0)
			s.insert(a[i]),S+=a[i];
		else
		{
			if(*s.begin()<a[i])
				s.insert(a[i]),S-=*s.begin(),s.erase(s.begin()),S+=a[i];
		}
	}
	printf("%d\n",s.size());
}