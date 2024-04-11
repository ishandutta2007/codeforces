#include<stdio.h>
#define q c[0]==
#define z q'a'||q'e'||q'i'||q'o'||q'u'||q'n'
using namespace std;
char c[2]={'a','a'};
int main()
{
	while(1)
	{
		c[0]=c[1];
		c[1]=getchar();
		if(c[1]=='\n')
		{
			if(z)printf("YES");
			else printf("NO");
			return 0;
		}
		if(!(z)&&!(c[1]=='a'||c[1]=='e'||c[1]=='i'||c[1]=='o'||c[1]=='u'))
		{
			printf("NO");
			return 0;
		}
	}
}