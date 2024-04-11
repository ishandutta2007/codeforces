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
typedef long long ll;
typedef unsigned long long ull;
map<string,int> s,in,out;
int n;
vector<string> Names;
bool cmp(const string&a,const string&b)
{
    if(s[a]!=s[b])return s[a]<s[b];
    int A=out[a]-in[a],B=out[b]-in[b];
    if(A!=B)return A<B;
    return out[a]<out[b];
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n;string tmp;
    rep(i,n)cin>>tmp,s[tmp]=in[tmp]=out[tmp]=0,Names.pb(tmp);
    rep(i,n*(n-1)/2)
    {
        cin>>tmp;
        string a,b;
        int split=tmp.find('-');
        a=tmp.substr(0,split);
        b=tmp.substr(split+1);
        int A,B;char c;
        cin>>A>>c>>B;
        if(A>B)s[a]+=3;
        if(A==B)s[a]++,s[b]++;
        if(A<B)s[b]+=3;
        out[a]+=A;out[b]+=B;
        in[a]+=B;in[b]+=A;
    }
    sort(Names.begin(),Names.end(),cmp);
    vector<string> Ans;
    For(i,n/2,n-1)Ans.pb(Names[i]);
    sort(Ans.begin(),Ans.end());
    rep(i,Ans.size())cout<<Ans[i]<<endl;
}