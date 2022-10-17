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
ll n,k;
int main(){
    cin>>n;
    k=n*(n+1)/2;
    for(ll i=2;i<=n;i++)
    	if( __gcd(i,k-i)!=1 ){
    		cout<<"Yes"<<endl;
    		cout<<1<<" "<<i<<endl;
    		cout<<n-1<<" ";
    		for(int j=1;j<=n;j++)
    			if(i!=j)
    				cout<<j<<" ";
    		return 0;
    	} 
    cout<<"No"<<endl;
    return 0;
}