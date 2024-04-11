#include <cstring>
#include <iostream>
using namespace std;
char s[1000005],t[2000005];
int f[2000005];
void init()
{
 t[0]=t[1]='#';
 int len=strlen(s);
 for(int i=0;i<len;i++)
 {
  t[2*i+2]=s[i];
  t[2*i+3]='#';
 }
 t[2*len+2]=0;
}
int main()
{
 int T;
 cin>>T;
 while(T--)
 {
  cin>>s;
  init();
  int len=strlen(t+1),l=1,r=len;
  while(l<=r)
  {
   if(t[l]==t[r])l++,r--;
   else break;
  }
  int ans=0,nl=l,nr=l,maxr=l,mid=l;
  for(int i=l;i<=r;i++)
  {
   if(i<maxr)
    f[i]=min(f[mid]+(mid-i),f[mid*2-i]);
   else
    f[i]=1;
   while(t[i+f[i]]==t[i-f[i]]&&i+f[i]<=r&&i-f[i]>=l)
    f[i]++;
   if(f[i]+i>maxr)
   {
    maxr=f[i]+i;
    mid=i;
   }
   if((i-f[i]<l||i+f[i]>r)&&f[i]>ans)
   {
    nl=i-f[i]+1;
    nr=i+f[i]-1;
    ans=f[i];
   }
  }
  if(l>r)
  {
   cout<<s<<endl;
   continue;
  }
  for(int i=1;i<l;i++)
   if(t[i]!='#')cout<<t[i];
  for(int i=nl;i<=nr;i++)
   if(t[i]!='#')cout<<t[i];
  for(int i=r+1;i<=len;i++)
   if(t[i]!='#')cout<<t[i];
  cout<<endl;
 }
 return 0;
}