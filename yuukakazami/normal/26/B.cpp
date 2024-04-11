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
int st;
int main()
{
    //freopen("in","r",stdin);
    string A;cin>>A;
    int ans=A.size();st=0;
    rep(i,A.size())
    {
        if(A[i]=='(')st++;
        else
        {
            if(st==0)ans--;
            else st--;
        }
    }
    ans-=st;
    cout<<ans<<endl;
}