#include<cmath> 
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define ll long long 
using namespace std;
int main(){
	vector<ll> v,k,p;
	ll n,va=0,vk=0,x;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		va+=x;
	}
	for (int i=0;i<n;i++){
		cin>>x;
		k.push_back(x);
		vk+=x;
	}
	for (int i=0;i<n;i++)
		p.push_back(i);
	ll len=n/2+1;
	while (1){
		random_shuffle(p.begin(),p.end());
		ll s1=0,s2=0;
		for (int i=0;i<len;i++){
			s1+=v[p[i]];
			s2+=k[p[i]];
		}
		if (2*s1>va&&2*s2>vk) break;
	}
	cout<<len<<endl;
	for (int i=0;i<len;i++)
		cout<<p[i]+1<<' ';
}