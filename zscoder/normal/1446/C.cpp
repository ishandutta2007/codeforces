#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class MinXorQuery {

private:
    
    vector<vector<int> > jump;
    vector<int> newNode;
 
public:
 
    vector<int> numbers;
    
    MinXorQuery () {
        jump.resize(1);
        jump[0].resize(2);
        jump[0][0] = jump[0][1] = 0;
        newNode.resize(2);
        newNode[0] = newNode[1] = 0;
    }
    
    void swapWith (MinXorQuery& other) {
        jump.swap(other.jump);
        newNode.swap(other.newNode);
        numbers.swap(other.numbers);
    }
    
    void addNumber (int number) {
        int pos = 0;
        for(int i = 30; i + 1; i--) {
            int bit = ((number & (1 << i)) > 0);
            if (jump[pos][bit] == 0) {
                jump.push_back(newNode);
                jump[pos][bit] = (int)jump.size() - 1;
                pos = (int)jump.size() - 1;
            } else
                pos = jump[pos][bit];
        }
        numbers.push_back(number);
    }
    
    void clear () {
        jump.size();
        numbers.size();
    }
    
    int getMinXorWith (int number) {
        int pos = 0;
        int result = 0;
        for(int i = 30; i + 1; i--) {
            int bit = ((number & (1 << i)) > 0);
            if (jump[pos][bit] != 0) {
                pos = jump[pos][bit];
                //result += (1 << i);
            } else
            {
                pos = jump[pos][bit^1];
                result^=(1<<i);
			}
        }
        return result;
    }
    
    size_t size () {
        return numbers.size();
    }
    
};

int a[222222];
int fred[222222];
int id[222222];
int ans=2;

void solve(vi a, int bit, int ext=0)
{
	if(a.empty()) return ;
	if(bit<0)
	{
		ans=max(ans,ext+int(a.size())); return ;
	}
	vi L,R;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]&(1<<bit)) L.pb(a[i]);
		else R.pb(a[i]);
	}
	solve(L,bit-1,ext+min(int(R.size()),1));
	swap(L,R);
	solve(L,bit-1,ext+min(int(R.size()),1));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vi vec;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		vec.pb(a[i]);
	}
	solve(vec,30);
	cout<<n-ans<<'\n';
	/*
	MinXorQuery M1,M2;
	for(int i=0;i<n;i++) fred[i]=int(2e9);
	for(int i=0;i<n;i++)
	{
		int res = M1.getMinXorWith(a[i]);
		fred[i]=min(fred[i],res);
		M1.addNumber(a[i]);
		//cerr<<"M1: "<<i<<' '<<res<<'\n';
	}
	for(int i=n-1;i>=0;i--)
	{
		int res = M2.getMinXorWith(a[i]);
		fred[i]=min(fred[i],res);
		M2.addNumber(a[i]);
		//cerr<<"M2: "<<i<<' '<<res<<'\n';
	}
	map<int,int> ma;
	for(int i=0;i<n;i++) 
	{
		fred[i]^=a[i];
		//cerr<<"FRIEND "<<i<<" = "<<fred[i]<<'\n';
	}
	for(int i=0;i<n;i++) ma[a[i]]=i;
	for(int i=0;i<n;i++)
	{
		assert(ma.find(fred[i])!=ma.end());
		id[i]=ma[fred[i]];
		//cerr<<"ID: "<<id[i]<<'\n';
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		assert(id[i]!=i);
		if(id[id[i]]==i) cnt++;
	}
	assert(cnt%2==0);
	//cerr<<cnt<<'\n';
	cout<<cnt/2-1<<'\n';
	*/
	
}