#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int BIT[MAXN+1];

void add(int p){
	for(;p<=MAXN;p+=p&-p)
		BIT[p]++;
}

int query(int p){
	int res=0;
	for(;p>0;p-=p&-p)
		res+=BIT[p];
	return res;
}

int a[MAXN];

pair<int,pair<int,int> > q[MAXN];

int k[MAXN],pos[MAXN];

int ans[MAXN];
vector<pair<int,int> > v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.emplace_back(make_pair(-a[i],i));
	}
	sort(v.begin(),v.end());
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].first>>q[i].second.first;
		q[i].second.second=i;
	}
	sort(q+1,q+m+1);
	int po=0;
	for(int i=1;i<=m;i++){
		while(q[i].first>po){
			add(v[po].second);
			po++;
		}
		int l=1,r=n;
		int x=q[i].second.first;
		while(l<r){
			int mid=(l+r)>>1;
			if(query(mid)<x)
				l=mid+1;
			else
				r=mid;
		}
		ans[q[i].second.second]=a[l];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
}