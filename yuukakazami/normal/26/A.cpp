#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <cstring>
#include <time.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define Debug(x) cout<<#x<<"="<<x<<endl;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<pre-clock()<<endl;pre=clock();
const int inf=~0U>>1;
using namespace std;
int n;
bool check(int a)
{
    int cnt=0;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            cnt++;while(a%i==0)a/=i;
        }
    }
    if(a>1)cnt++;
    return cnt==2;
}
int main()
{
    //freopen("in","r",stdin);
    int ans=0;
    cin>>n;for(int i=1;i<=n;i++)ans+=check(i);
    cout<<ans<<endl;
}