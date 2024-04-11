#include<bits/stdc++.h>
using namespace std;
int a[26],n,i,c=0,b=0;
int main()
{
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++)a[getchar()-'a']+=1;
	for(i=0;i<=25;i++){if(a[i]>=2)b+=1;if(a[i])c++;}
	if(b||c==1)printf("Yes");
	else printf("No");
}