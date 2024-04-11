#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<fstream>
#include<cmath>
#include<cctype>
#include<stack>
#include<cstdlib>
#include<ctime>
#include<ext/pb_ds/priority_queue.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> SI;
typedef unsigned int ui;
typedef double db;
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
const int N=55,M=3000;
const ll mo=1000000007;
int d[N],i,n;
map<ll,ll> f;
inline ll pow(ll x,int y){
	if(!y)return 1;
	ll u=pow(x,y>>1);
	if(y&1)return u*u%mo*x%mo;
		else return u*u%mo;
}
inline ll C2(int x){
	return x*(x-1)>>1;
}
ll dp(int v,int a,int b,int cc,int dd){
	int w=v*n*n*n*n+a*n*n*n+b*n*n+cc*n+dd;
	if(a<0 || b<0 || cc<0 || dd<0)return 0;
	if(v>n)return !a && !b && !cc && !dd; 
	if(f.count(w))return f[w];
	ll&ans=f[w];
	if(a==0 && b==0){
		ans=(dp(v+1,cc-1,dd,d[v]==2,d[v]==3)*cc+dp(v+1,cc+1,dd-1,d[v]==2,d[v]==3)*dd)%mo;
	}else{
		if(d[v]==2){
			ans=(ans+dp(v+1,a-1,b,cc+1,dd)*a)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc+1,dd)*b)%mo;
			ans=(ans+dp(v+1,a-1,b,cc-1,dd)*a*cc)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc-1,dd)*b*cc)%mo;
			ans=(ans+dp(v+1,a-1,b,cc+1,dd-1)*a*dd)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc+1,dd-1)*b*dd)%mo;
		}else{
			ans=(ans+dp(v+1,a-1,b,cc,dd+1)*a)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc,dd+1)*b)%mo;
			ans=(ans+dp(v+1,a-1,b,cc,dd)*a*cc)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc,dd)*b*cc)%mo;
			ans=(ans+dp(v+1,a-1,b,cc+2,dd-1)*a*dd)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc+2,dd-1)*b*dd)%mo;
			ans=(ans+dp(v+1,a-1,b,cc-2,dd)*C2(cc)*a)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc-2,dd)*C2(cc)*b)%mo;
			ans=(ans+dp(v+1,a-1,b,cc,dd-1)*cc*dd*a)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc,dd-1)*cc*dd*b)%mo;
			ans=(ans+dp(v+1,a-1,b,cc+2,dd-2)*C2(dd)*a)%mo;
			ans=(ans+dp(v+1,a+1,b-1,cc+2,dd-2)*C2(dd)*b)%mo;
		}
	}
	return ans;
}
int main(){
	cin>>n;
	for(i=1;i<=n;++i)scanf("%d",d+i);
	cout<<dp(3,d[1]==2,d[1]==3,d[2]==2,d[2]==3)<<endl;
	return 0;
}