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
#define printTime cout<<"Time:"<<clock()-pre<<endl;pre=clock();
const int inf=~0U>>1;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    //freopen("in","r",stdin);
    int n,d;int A[10000];
    cin>>n>>d;
    rep(i,n)
    {
        cin>>A[i];
    }
    int ans=0;
    rep(i,n)rep(j,n)if(i!=j)
        if(abs(A[i]-A[j])<=d)ans++;
    cout<<ans<<endl;

}