# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e6+14;
vector <vector <int> > cycles[MN];
int p[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", p+i);
	for (int st=1; st<=n; ++st)
	{
		if (p[st])
		{
			vector <int> curr;
			int wh = st;
			do
			{
				curr.push_back(wh);
				int next = p[wh];
				p[wh]=0;
				wh = next;
			}
			while (p[wh]);
			cycles[curr.size()].push_back(curr);
		}
	}
	for (int i=1; i<=n; ++i)
		if (i%2)
		{
			int jump = (i+1)/2;
			for (int k=0; k<cycles[i].size(); ++k)
				for (int l=0; l<i; ++l)
					p[cycles[i][k][l]]=cycles[i][k][(l+jump)%i];
		}
		else
		{
			if (cycles[i].size()%2)
			{
				printf("-1\n");
				return 0;
			}
			for (int k=0; k<cycles[i].size(); k+=2)
			{
				for (int l=0; l<i; ++l)
				{
					p[cycles[i][k][l]]=cycles[i][k+1][l];
					p[cycles[i][k+1][l]]=cycles[i][k][(l+1)%i];
				}
			}
		}
	for (int i=1; i<=n; ++i)
		printf("%d ", p[i]);
	printf("\n");
}