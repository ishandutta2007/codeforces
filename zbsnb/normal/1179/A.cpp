#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans[2][500010];
int main(){
	int n,q;cin>>n>>q;
	list<int> L;
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		L.push_back(tmp);
	}
	for(int i=1;i<=3*n;i++){
		int a=L.front();L.pop_front();
		int b=L.front();L.pop_front();
		ans[0][i]=a,ans[1][i]=b;
		if(a<b)swap(a,b);
		L.push_front(a);L.push_back(b);
	}
	while(q--){
		ll tmp;cin>>tmp;
		if(tmp<=3*(n-1)) cout<<ans[0][tmp]<<" "<<ans[1][tmp]<<endl;
		else cout<<ans[0][tmp%(n-1)+2*(n-1)]<<" "<<ans[1][tmp%(n-1)+2*(n-1)]<<endl;
	}
}