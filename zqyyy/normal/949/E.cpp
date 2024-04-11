#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+7;
vector<pii>solve(vector<int>a,int d){
    if(d>18){vector<pii>res(27);return res;}
    vector<int>b;bool fl=1;
    for(int x:a)if(x)b.push_back(x);
    if(b.empty())return {};
    sort(b.begin(),b.end()),b.erase(unique(b.begin(),b.end()),b.end());
    a=b;
    for(int x:a)fl&=abs(x)%2==0;
    if(fl){
	for(int &x:a)x/=2;
	return solve(a,d+1);
    }
    b=a;
    for(int &x:b){
	if(abs(x)&1)x++;
	x>>=1;
    }
    vector<pii>neg=solve(b,d+1);
    neg.push_back({-1,d});
    b=a;
    for(int &x:b){
	if(abs(x)&1)x--;
	x>>=1;
    }
    vector<pii>pos=solve(b,d+1);
    pos.push_back({1,d});
    return neg.size()<pos.size()?neg:pos;
}
int main(){
    int n=read();vector<int>a(n);
    for(int i=0;i<n;i++)a[i]=read();
    vector<pii>ans=solve(a,0);
    printf("%lu\n",ans.size());
    for(auto x:ans)printf("%d ",x.fi*(1<<x.se));
    return 0;
}