#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int>mp;
map<int,int>::iterator it,it2;

struct A{
	int val,id;
}a[1001000];
bool bbb(A a1,A a2){
	return a1.val>a2.val;
}
bool sss(A a1,A a2){
	return a1.val<a2.val;
}
int n;
ll ans=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;scanf("%d",&a[i++].val)) a[i].id=i;
	
	mp.clear();
	mp[0]=1;mp[n+1]=1;
	sort(a+1,a+n+1,sss);
	for (int i=1;i<=n;i++){
		it=mp.lower_bound(a[i].id);
		it2=it--;
		ans-=(ll)a[i].val*(it2->first-a[i].id)*(a[i].id-it->first);
		mp[a[i].id]=1;
	}
	
	mp.clear();
	mp[0]=1;mp[n+1]=1;
	sort(a+1,a+n+1,bbb);
	for (int i=1;i<=n;i++){
		it=mp.lower_bound(a[i].id);
		it2=it--;
		ans+=(ll)a[i].val*(it2->first-a[i].id)*(a[i].id-it->first);
		mp[a[i].id]=1;
	}
	
	cout<<ans;
}