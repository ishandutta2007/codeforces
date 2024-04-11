# include <cstdio>
# include <cstring>
# include <set>
using namespace std;
# define MN 100
# define INF (1<<20)
char s1[MN+1], s2[MN+1], virus[MN+1];
int res[MN+1][MN+1][MN+1];
pair <int, pair <int, int> > via[MN+1][MN+1][MN+1];
# define x first
# define y second.first
# define z second.second
# define m3(a, b, c) make_pair ((a), make_pair((b), (c)))
int len1, len2, vlen;
int p[MN+1];
int main()
{
	scanf("%s%s%s", s1, s2, virus);
	len1=strlen(s1);
	len2=strlen(s2);
	vlen=strlen(virus);
	p[0]=0;
	for (int i=1; i<vlen; ++i)
	{
		int tr=p[i-1];
		while (tr && virus[i]!=virus[tr])
		{
			tr=p[tr-1];
		}
		if (virus[i]==virus[tr])
			tr++;
		p[i]=tr;
	}
	for (int i=len1; i>=0; --i)
		for (int j=len2; j>=0; --j)
			for (int k=vlen; k>=0; --k)
				if (k==vlen)
				{
					res[i][j][k]=-INF;
					via[i][j][k]=m3(-1, -1, -1);
				}
				else if (i==len1 || j==len2)
				{
					via[i][j][k]=m3(-1, -1, -1);
					res[i][j][k]=0;
				}
				else 
				{
					if (res[i+1][j][k]>res[i][j+1][k])
					{
						res[i][j][k]=res[i+1][j][k];
						via[i][j][k]=m3(i+1, j, k);
					}
					else
					{
						res[i][j][k]=res[i][j+1][k];
						via[i][j][k]=m3(i, j+1, k);
					}
					if (s1[i]==s2[j])
					{
						int cmn=k;
						char next=s1[i];
						while (cmn && virus[cmn]!=next)
							cmn=p[cmn-1];
						if (virus[cmn]==next)
							cmn++;
						if (res[i+1][j+1][cmn]+1>res[i][j][k])
						{
							res[i][j][k]=res[i+1][j+1][cmn]+1;
							via[i][j][k]=m3(i+1, j+1, cmn);
						}
					}
				}
	if (res[0][0][0])
	{
		pair <int, pair <int, int> > wh=m3(0, 0, 0);
		while (wh.x!=-1)
		{
			if (via[wh.x][wh.y][wh.z].x==wh.x+1 && via[wh.x][wh.y][wh.z].y==wh.y+1)
				putchar(s1[wh.x]);
			wh=via[wh.x][wh.y][wh.z];
		}
		putchar(10);
	}
	else
		printf("0\n");
}