#include<bits/stdc++.h>
#define ll long long
#define base 127
#define INF 0x3f3f3f3f
#define N 100100
using namespace std;

int n,num[N];
map<int,bool>in;
map<ll,int>cz;

inline ll hsh(vector<int>num)
{
    ll i,res=0;
    for(i=0;i<num.size();i++) res=res*base+num[i];
    return res;
}

int dfs(vector<int>num)
{
    if(!num.size()) return 0;
    int i,a,b;
    ll h=hsh(num);
    for(i=0;i<num.size();i++) if(num[i]&1) break;
    if(i==num.size())
    {
	for(i=0;i<num.size();i++) num[i]/=2;
	cz[h]=0;
	return dfs(num);
    }
    vector<int>tmp;
    tmp.clear();
    for(i=0;i<num.size();i++)
    {
	if(num[i]&1)
	{
	    if((num[i]+1)/2&&(!tmp.size() || (num[i]+1)/2!=tmp.back()))
		tmp.push_back((num[i]+1)/2);
	}
	else if(!tmp.size() || num[i]/2!=tmp.back()) tmp.push_back(num[i]/2);
    }
    if(tmp!=num) a=dfs(tmp)+1;
    else a=INF;
    
    tmp.clear();
    for(i=0;i<num.size();i++)
    {
	if(num[i]&1)
	{
	    if((num[i]-1)/2&&(!tmp.size() || (num[i]-1)/2!=tmp.back()))
		tmp.push_back((num[i]-1)/2);
	}
	else if(!tmp.size() || num[i]/2!=tmp.back()) tmp.push_back(num[i]/2);
    }
    if(tmp!=num) b=dfs(tmp)+1;
    else b=INF;
    if(a<b) cz[h]=1;
    else cz[h]=-1;
    return min(a,b);
}

void out(vector<int>num,int cs)
{
    if(!num.size()) return;
//    printf(" ");for(int i=0;i<num.size();i++) cout<<num[i]<<" ";cout<<":"<<cz[hsh(num)];puts("");
    int i;
    ll h=hsh(num);
    if(!cz[h])
    {
	for(i=0;i<num.size();i++) num[i]/=2;
	out(num,cs<<1);
    }
    else if(cz[h]==1)
    {
	vector<int>tmp;
	tmp.clear();
	for(i=0;i<num.size();i++)
	{
	    if(num[i]&1)
	    {
		if((num[i]+1)/2&&(!tmp.size() || (num[i]+1)/2!=tmp.back()))
		    tmp.push_back((num[i]+1)/2);
	    }
	    else if(!tmp.size() || num[i]/2!=tmp.back()) tmp.push_back(num[i]/2);
	}
	printf("%d ",-cs);
	out(tmp,cs<<1);
    }
    else
    {
	vector<int>tmp;
	tmp.clear();
	for(i=0;i<num.size();i++)
	{
	    if(num[i]&1)
	    {
		if((num[i]-1)/2&&(!tmp.size() || (num[i]-1)/2!=tmp.back()))
		    tmp.push_back((num[i]-1)/2);
	    }
	    else if(!tmp.size() || num[i]/2!=tmp.back()) tmp.push_back(num[i]/2);
	}
	printf("%d ",cs);
	out(tmp,cs<<1);
    }
}

int main()
{
    int i,j;
    vector<int>tmp;
    tmp.clear();
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%d",&num[i]);
	if(in.count(num[i])) continue;
	in[num[i]]=1;
	if(num[i]) tmp.push_back(num[i]);
    }
    sort(tmp.begin(),tmp.end());
    cout<<dfs(tmp)<<endl;
    out(tmp,1);
}