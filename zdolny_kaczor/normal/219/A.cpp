# include <cstdio>
const int MN=1010;
char tab[MN];
int cou[26];
int main()
{
	int k;
	scanf("%d%s", &k, tab);
	for (int i=0; tab[i]; ++i)
		cou[tab[i]-'a']++;
	for (int i=0; i<26; ++i)
		if (cou[i]%k)
		{
			printf("-1\n");
			return 0;
		}
	for (int i=0; i<k; ++i)
	{
		for (int l=0; l<26; ++l)
			for (int x=0; x<cou[l]/k; ++x)
				putchar('a'+l);
	}
	printf("\n");
}