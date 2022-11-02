#include<bits/stdc++.h>
#define N 400010
using namespace std;
int n,I,types,ans,s[N];
int cal(int val)
{
  int res=log2(val);
  while(val%2==0)val/=2;
  if(val>1)res++;
  return res;
} 

int main()
{
  scanf("%d%d",&n,&I);
  types=I*8/n;ans=n;
  for(int i=1;i<=n;i++)scanf("%d",&s[i]);
  sort(s+1,s+n+1);
  for(int i=1,j=2,cnt=1;i<=n;)
  {
  	if(j<=i)j=i+1,cnt=1;
    for(;j<=n;j++)
    {
	  if(s[j]!=s[j-1])cnt++;
	  if(cal(cnt)>types){cnt--;break;}
	}
	ans=min(ans,i-1+n-j+1); 
	int val=s[i];
	for(;i<=n&&s[i]==val;i++);cnt--;
  }
  printf("%d\n",ans);
  return 0;
}