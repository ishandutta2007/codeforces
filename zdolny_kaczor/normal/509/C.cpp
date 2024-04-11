# include <cstdio>
const int ML=500;
char last[ML];
void show()
{
	bool in=false;
	for (int i=0; i<ML; ++i)
	{
		if (last[i])
			in=true;
		if (in)
			putchar(last[i]+'0');
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	int lastsum=0;
	for (int i=0; i<n; ++i)
	{
		int currsum;
		scanf("%d", &currsum);
		if (currsum<=lastsum)
		{
			int pos=ML-1;
			while (lastsum+1>currsum)
			{
				lastsum-=last[pos];
				last[pos]=0;
				pos--;
			}
			while (last[pos]==9)
			{
				last[pos]=0;
				lastsum-=9;
				pos--;
			}
			last[pos]++;
			lastsum++;
// 			printf("temp:");
// 			show();
		}
		for (int k=ML-1; currsum>lastsum; )
		{
			if (last[k]==9)
				k--;
			else
			{
				last[k]++;
				lastsum++;
			}
		}
		show();
	}
}