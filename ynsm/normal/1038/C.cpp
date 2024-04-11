#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=2e5+123,inf=1e9,mod=1e9+7;
ll n,ans,x;
vector<int> v1,v2;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x;
    	v1.pb(x);
    }
    for(int i=0;i<n;i++){
    	cin>>x;
    	v2.pb(x);
    }                         
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(n--){
    	if( !v1.empty() && ( v2.empty() || v1.back()>v2.back() )  ){
    		ans+=v1.back();
    		v1.pop_back();		
    	}else{
    		v2.pop_back();		
    	}
		if( !v1.empty() && ( v2.empty() || v1.back()>v2.back() ) ){
    		v1.pop_back();		
    	}else{
    		ans-=v2.back();
    		v2.pop_back();		
    	}
    }
    cout<<ans;
    return 0;
}