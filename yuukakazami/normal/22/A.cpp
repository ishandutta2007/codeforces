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
int main()
{
    //freopen("in","r",stdin);
    set<int> A;
    int n,x;cin>>n;rep(i,n)cin>>x,A.insert(x);
    if(A.size()==1){cout<<"NO"<<endl;}
    else cout<<*(++A.begin())<<endl;
}