//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
char a[333333],b[34];
bool sgn[333333];
int ans=0;
int main()
{
	scanf("%s%s",a,b);
	int n=strlen(a),bn=strlen(b);
	for(int i=0;i+bn<=n;i++)
	{
		bool ok=1;
		for(int j=0;j<bn;j++)
		{
			if(a[i+j]!=b[j]) ok=0;
		}
		if(!ok) continue;
		bool tged=0;
		for(int j=0;j<bn;j++)
		{
			if(sgn[i+j]) tged=1;
		}
		if(!tged) ++ans, sgn[i+bn-1]=1;
	}
	printf("%d\n",ans);
}