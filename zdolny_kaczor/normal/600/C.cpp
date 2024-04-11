# include <cstdio>
const int A = 26, MN = 2*1000*100+42;
char str[MN];
int cou[MN];
int main()
{
	scanf("%s", str);
	for (int i=0; str[i]; ++i)
		cou[str[i]-'a']++;
	int odd=0;
	for (int i=0; i<A; ++i)
		if (cou[i]%2)
			odd++;
	int ch=0;
	for (int i=0; i<A; ++i)
		if (cou[i]%2)
		{
			if (ch*2<odd-1)
				cou[i]++;
			else if (ch*2>odd-1)
				cou[i]--;
			ch++;
		}
	for (int i=0; i<A; ++i)
		for (int k=0; k<cou[i]/2; ++k)
			putchar('a'+i);
		for (int i=0; i<A; ++i)
			if (cou[i]%2)
				putchar('a'+i);
	for (int i=A-1; i>=0; --i)
		for (int k=0; k<cou[i]/2; ++k)
			putchar('a'+i);
	
}