#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
#define pii pair<int,bool>
#define fi first
#define se second
const int N=21;
int n;
struct Bracket_String{
    vector<int>ans;
    int Min,sum;
    string s;
    inline pii query(int x,bool o){
	return o?pii{0,1}:pii{x<(int)ans.size()?ans[x]:0,Min+x<0};
    }
    inline void calc(){
	vector<int>b;
	for(auto i:s){
	    i=='('?sum++:sum--;
	    b.push_back(sum);
	}
	Min=min(0,*min_element(b.begin(),b.end()));
	vector<vector<int> >pos(-Min+1);
	for(int i=0;i<(int)s.size();i++)
	    if(b[i]<=0)pos[-b[i]].push_back(i);
	ans.resize(-Min+1);
	for(int i=0;i<(int)ans.size();i++){
	    int lst=1e9;if(i!=-Min)lst=pos[i+1][0];
	    ans[i]=lower_bound(pos[i].begin(),pos[i].end(),lst)-pos[i].begin();
	}
    }
}a[N];
int f[1<<N][2],cnt[1<<N];
int main(){
    n=read();
    for(int i=0;i<n;i++)cin>>a[i].s,a[i].calc();
    int U=(1<<n)-1;
    for(int s=0;s<=U;s++)
	for(int i=0;i<n;i++)
	    if(s>>i&1)cnt[s]+=a[i].sum;
    for(int s=0;s<=U;s++)
	for(int o=0;o<2;o++)f[s][o]=-1e9;
    f[0][0]=0;
    for(int s=0;s<=U;s++)
	for(int o=0;o<2;o++)
	    if(f[s][o]>=0){
		for(int i=0;i<n;i++)
		    if(!(s>>i&1)){
			pii res=a[i].query(cnt[s],o);
			f[s^(1<<i)][res.se]=max(f[s^(1<<i)][res.se],f[s][o]+res.fi);
		    }
	    }
    printf("%d\n",max(f[U][0],f[U][1]));
    return 0;
}