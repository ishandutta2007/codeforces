#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
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
int n=8;
bool check(int a,int b)
{
    a=abs(a);b=abs(b);
    if(a>b)swap(a,b);
    return a==1&&b==2;
}
bool ex[8][8]={};
int x1,y1;
int x2,y2;
int main()
{
    //freopen("in","r",stdin);
    string a;cin>>a;x1=a[0]-'a';y1=a[1]-'1';ex[x1][y1]=true;
    cin>>a;x2=a[0]-'a';y2=a[1]-'1';ex[x2][y2]=true;
    int ret=0;
    rep(i,8)
        rep(j,8)if(!ex[i][j])
        {
            if(i!=x1&&j!=y1)
            {
                if(!check(i-x2,j-y2)&&!check(i-x1,j-y1))
                    ret++;
            }
        }
    cout<<ret<<endl;
}