#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
char a[100010];
long long th(long long o, long long i)
{
        long long s=1;
        while (i)
        {
                if (i&1!=0)
                {       s=s*o;
                        s=s%1000000007;
                }
                i=i>>1;
                o=o*o;
                o=o%1000000007;}
        return s;
        }
int main()
{
        long long i,len,ans=0,k,tem1,tem2;
  cin>>a>>k;
        len=strlen(a);
        for (i=0;i<len;i++)
                if (a[i]=='0'||a[i]=='5')
      ans=ans+th(2,i)%1000000007;
        ans%=1000000007;
        tem1 = (th(2,len*k)-1)%1000000007;
        tem2 = th(th(2,len)-1,1000000005)%1000000007;
        ans*=tem1;
        ans%=1000000007;
        ans*=tem2;
        ans%=1000000007;
        cout<<ans<<endl;     
        return 0;
}