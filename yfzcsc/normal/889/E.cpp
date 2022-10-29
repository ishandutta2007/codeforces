#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>st;
ll n,a[200100],lst;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	st[a[1]-1]=0,lst=a[1];
	for(int i=2;i<=n;++i)if(a[i]<lst){
		for(auto it=st.lower_bound(a[i]);it!=st.end();st.erase(it++))
			st[a[i]-1]=max(st[a[i]-1],it->second+(i-1)*(it->first-it->first%a[i]-a[i])),
			st[it->first%a[i]]=max(st[it->first%a[i]],it->second+(i-1)*(it->first-it->first%a[i]));
		lst=a[i];		
	}
	lst=0;
	for(auto it:st)lst=max(lst,it.first*n+it.second);
	cout<<lst;
}