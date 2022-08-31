#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define ALP 26
#define SIZE 300005

using namespace std;
typedef long long int ll;

int fs[ALP],now[ALP];
char str[SIZE];
ll cnt[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<ALP;i++) fs[i]=n;
	for(int i=n-1;i>=0;i--)
	{
		fs[str[i]-'a']=i;
		for(int j=0;j<ALP;j++) now[j]=fs[j];
		sort(now,now+ALP);
		for(int j=0;j<ALP;j++)
		{
			if(j==ALP-1) cnt[j]+=(ll) n-now[j];
			else cnt[j]+=(ll) now[j+1]-now[j];
		}
	}
	int lim=0;
	for(int i=0;i<ALP;i++)
	{
 		if(cnt[i]==0) break;
		lim=i;
	}
	printf("%d\n",lim+1);
	for(int j=0;j<=lim;j++) printf("%I64d\n",cnt[j]);
	return 0;
}