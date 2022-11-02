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
#define tr(e,x) for(set<string>::iterator e=x.begin();e!=x.end();e++)
#define printTime cout<<"Time:"<<clock()-pre<<endl;pre=clock();
const int inf=~0U>>3,maxn=30+10;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string a[maxn];
int n;
map<string,int> Time;
int val(char c){return c-'a'+1;}
int score(string a)
{
    int M=0,S=0;
    rep(i,a.size())
    {
        S+=val(a[i]);
        M=max(M,val(a[i]));
    }
    int ret=S*M;
    if(Time.count(a))ret+=Time[a];
    return ret;
}
struct Data
{
    bool Win;
    int me,op;
    Data(){}
    Data(bool _w,int _m,int _o):
        Win(_w),me(_m),op(_o){}
    Data step(int val)
    {
        Data ret=*this;
        ret.Win^=1;
        swap(ret.me,ret.op);
        ret.me+=val;
        return ret;
    }
    bool operator>(const Data&that)
    {
        if(Win!=that.Win)return Win;
        if(me!=that.me)return me>that.me;
        return op<that.op;
    }
}null(false,0,0);
map<string,Data> Map;
Data dfs(string a)
{
    if(Map.count(a))return Map[a];
    //begin
    Data ret=null;
    for(char c='a';c<='z';c++)
    {
        string b=c+a;
        if(Time.count(b))
        {
            Data tmp=dfs(b).step(score(b));
            if(tmp>ret)ret=tmp;
        }
    }
    //end
    for(char c='a';c<='z';c++)
    {
        string b=a+c;
        if(Time.count(b))
        {
            Data tmp=dfs(b).step(score(b));
            if(tmp>ret)ret=tmp;
        }
    }
    return Map[a]=ret;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n;rep(i,n)cin>>a[i];
    rep(i,n)
    {
        set<string>se;
        rep(l,a[i].size())
            for(int s=1;l+s<=a[i].size();s++)
            {
                string ret=a[i].substr(l,s);
                se.insert(ret);
            }
        tr(e,se)Time[*e]++;
    }
    Data ans=dfs("");
    if(ans.Win)puts("First");else puts("Second");
    cout<<ans.me<<" "<<ans.op<<endl;
}