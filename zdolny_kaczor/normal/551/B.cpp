# include <cstdio>
# include <set>
using namespace std;
const int MN=100100;
char str[3][MN];
int amo[3][26];
int main()
{
	for (int i=0; i<3; ++i)
		scanf("%s", str[i]);
	for (int i=0; i<3; ++i)
		for (int n=0; str[i][n]; ++n)
			amo[i][str[i][n]-'a']++;
	int max=0, wh;
	for (int tr=0; tr<MN; ++tr)
	{
		int oth=MN;
		bool poss=true;
		for (int i=0; i<26; ++i)
		{
			if (amo[1][i]*tr>amo[0][i])
				poss=false;
			oth=min(oth, amo[2][i]?(amo[0][i]-amo[1][i]*tr)/amo[2][i]:MN);
		}
		if (!poss)
			break;
		if (oth+tr>max)
		{
			max=oth+tr;
			wh=tr;
		}
	}
	if (max==0)
		printf("%s\n", str[0]);
	else
	{
		for (int i=0; i<wh; ++i)
			printf("%s", str[1]);
		for (int i=0; i<max-wh; ++i)
			printf("%s", str[2]);
		for (int i=0; i<26; ++i)
			for (int k=0; k<amo[0][i]-amo[1][i]*wh-amo[2][i]*(max-wh); ++k)
				putchar('a'+i);
		putchar(10);
	}
}