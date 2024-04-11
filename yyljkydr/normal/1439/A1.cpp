#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,m,a[N][N];

char s[N][N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<vector<pii> >ans;

void change(vector<pii> w)
{
	for(auto [x,y]:w)
		a[x][y]^=1;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=s[i][j]-'0';
		for(int i=n;i>=3;i--)
		{
			for(int j=2;j<=m;j++)
			{
				if(!a[i][j]&&!a[i][j-1])
					continue;
				vector<pii>tmp;
				if(a[i][j])
					tmp.push_back(mp(i,j));
				if(a[i][j-1])
					tmp.push_back(mp(i,j-1));
				if(tmp.size()<3)
					tmp.push_back(mp(i-1,j-1));
				if(tmp.size()<3)
					tmp.push_back(mp(i-1,j));
				change(tmp);
				ans.push_back(tmp);
			}
		}
		for(int j=m;j>=3;j--)
		{
			if(!a[1][j]&&!a[2][j])
					continue;
			vector<pii>tmp;
			if(a[1][j])
				tmp.push_back(mp(1,j));
			if(a[2][j])
				tmp.push_back(mp(2,j));
			if(tmp.size()<3)
				tmp.push_back(mp(1,j-1));
			if(tmp.size()<3)
				tmp.push_back(mp(2,j-1));
			change(tmp);
			ans.push_back(tmp);
		}
		while(a[1][1]+a[1][2]+a[2][1]+a[2][2])
		{
			vector<pii>tmp;
			if(a[1][1]+a[1][2]+a[2][1]+a[2][2]==3)
			{
				for(int i=1;i<=2;i++)
					for(int j=1;j<=2;j++)
						if(a[i][j])
							tmp.push_back(mp(i,j));
				change(tmp);
				ans.push_back(tmp);
				continue;
			}
			for(int i=1;i<=2;i++)
				for(int j=1;j<=2;j++)
					if(!a[i][j]&&tmp.size()<2)
						tmp.push_back(mp(i,j));
			for(int i=1;i<=2;i++)
				for(int j=1;j<=2;j++)
					if(a[i][j]&&tmp.size()<3)
						tmp.push_back(mp(i,j));
			change(tmp);
			ans.push_back(tmp);
		}
		printf("%d\n",ans.size());
		for(auto v:ans)
		{
			for(auto [x,y]:v)
				printf("%d %d ",x,y);
			puts("");
		}
	}
}