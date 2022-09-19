# include <cstdio>
bool mat[1000][1000];
int n=2;
int next_free()
{
	return n++;
}
void adde(int x, int y)
{
	mat[x][y]=mat[y][x]=true;
}
int main()
{
	int r;
	scanf("%d", &r);
	int len=20;
	
	int pow=1, exp=0;
	while (pow<=r)
	{
		pow*=3;
		exp++;
	}
	for (; r; pow/=3, exp--)
	{
		if (pow<=r)
		{
// 			printf("exp=%d\n", exp);
			int fr1=0, fr2=0, fr3=0;
			int u, m, d;
			for (int k=0; k<=len; ++k)
			{
				if (k<exp)
				{
					u=next_free();
					m=next_free();
					d=next_free();
				}
				else if (k==len)
					u=m=d=1;
				else if (k==exp)
				{
					if (pow*2<=r)
					{
						u=m=next_free();
						d=next_free();
					}
					else
						u=m=d=next_free();
				}
				else
					u=m=d=next_free();
// 				printf("%d %d %d -> %d %d %d\n", fr1, fr2, fr3, u, m, d);
				adde(fr1, u);
				adde(fr1, m);
				adde(fr1, d);
				adde(fr2, u);
				adde(fr2, m);
				adde(fr2, d);
				adde(fr3, u);
				adde(fr3, m);
				adde(fr3, d);
				fr1=u;
				fr2=m;
				fr3=d;
			}
			while (pow<=r)
				r-=pow;
		}
	}
	printf("%d\n", n);
	for (int i=0; i<n; ++i)
	{
// 		printf("%d.", i);
		for (int k=0; k<n; ++k)
			if (mat[i][k])
// 				printf("%d ", k);
				printf("Y");
			else
				printf("N");
		putchar(10);
	}
}