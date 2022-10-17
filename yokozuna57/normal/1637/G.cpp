#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int f(int n){
	int ret=1;
	while(ret<n)ret<<=1;
	return ret;
}

vector<pair<int,int>> solve(int n){
	vector<pair<int,int>> ret;
	if(n==3||n==4){
		ret.push_back(mp(1,3));
		ret.push_back(mp(2,2));
		return ret;
	}
	if(n==5){
		ret.push_back(mp(3,5));
		ret.push_back(mp(2,2));
		ret.push_back(mp(1,4));
		ret.push_back(mp(3,5));
		ret.push_back(mp(2,4));
		ret.push_back(mp(2,6));
		ret.push_back(mp(0,4));
		ret.push_back(mp(4,4));
		return ret;
	}
	if(n==6){
		ret.push_back(mp(2,6));
		ret.push_back(mp(3,5));
		ret.push_back(mp(4,4));
		ret.push_back(mp(1,2));
		ret.push_back(mp(1,3));
		ret.push_back(mp(2,4));
		ret.push_back(mp(2,6));
		ret.push_back(mp(0,4));
		ret.push_back(mp(4,4));
		return ret;
	}
	if(n==7||n==8){
		ret.push_back(mp(1,7));
		ret.push_back(mp(2,6));
		ret.push_back(mp(3,5));
		ret.push_back(mp(2,6));
		ret.push_back(mp(4,4));
		ret.push_back(mp(0,4));
		ret.push_back(mp(4,4));
		return ret;
	}
	int k=0,x=1;
	while(2*x<n){ x*=2; k++; }
	int l=n-x;
	if(l==1){
		for(int i=1;i<=l;i++){
			ret.push_back(mp(x-i,x+i));
		}
		auto temp=solve(x-l-1);
		ret.insert(ret.end(),temp.begin(),temp.end());
		auto y=f(x-l-1);
		while(y<x){
			for(int i=0;i<x-l-2;i++){
				ret.push_back(mp(y,0));
				ret.push_back(mp(y,y));
			}
			y*=2;
		}
		for(int t=1;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		for(int i=1;i<=x-l-1;i++){
			ret.push_back(mp(x,0));
			ret.push_back(mp(x,x));
		}
		return ret;
	}
	if(l==2){
		for(int i=1;i<=l;i++){
			ret.push_back(mp(x-i,x+i));
		}
		auto temp=solve(x-l-1);
		ret.insert(ret.end(),temp.begin(),temp.end());
		auto y=f(x-l-1);
		while(y<x){
			for(int i=0;i<x-l-2;i++){
				ret.push_back(mp(y,0));
				ret.push_back(mp(y,y));
			}
			y*=2;
		}
		for(int t=1;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		for(int t=2;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		for(int i=1;i<=x-l-1;i++){
			ret.push_back(mp(x,0));
			ret.push_back(mp(x,x));
		}
		return ret;
	}
	if(l==x)l--;
	if(l==x-1){
		for(int i=1;i<=l;i++){
			ret.push_back(mp(x-i,x+i));
		}
		auto temp=solve(l);
		auto z=f(l)*2;
		while(z<x){
			for(int i=0;i<l-1;i++){
				ret.push_back(mp(0,z));
				ret.push_back(mp(z,z));
			}
			z*=2;
		}
		for(auto p: temp){
			ret.push_back(mp(p.fr*2,p.sc*2));
		}
		ret.push_back(mp(x,0));
		ret.push_back(mp(x,x));
		return ret;
	}
	if(l==x-2){
		for(int i=1;i<=l;i++){
			ret.push_back(mp(x-i,x+i));
		}
		auto temp=solve(l);
		for(auto p: temp){
			ret.push_back(mp(p.fr*2,p.sc*2));
		}
		auto z=f(l)*2;
		while(z<2*x){
			for(int i=0;i<l-1;i++){
				ret.push_back(mp(0,z));
				ret.push_back(mp(z,z));
			}
			z*=2;
		}
		for(int t=0;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		ret.push_back(mp(x,0));
		ret.push_back(mp(x,x));
		return ret;
	}
	if(l==x-3){
		for(int i=1;i<=l;i++){
			ret.push_back(mp(x-i,x+i));
		}
		auto temp=solve(l);
		for(auto p: temp){
			ret.push_back(mp(p.fr*2,p.sc*2));
		}
		auto z=f(l)*2;
		while(z<2*x){
			for(int i=0;i<l-1;i++){
				ret.push_back(mp(0,z));
				ret.push_back(mp(z,z));
			}
			z*=2;
		}
		for(int t=0;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		for(int t=1;t<=k;t++){
			ret.push_back(mp(1<<t,0));
			ret.push_back(mp(1<<t,1<<t));
		}
		ret.push_back(mp(x,0));
		ret.push_back(mp(x,x));
		return ret;
	}
	for(int i=1;i<=l;i++){
		ret.push_back(mp(x-i,x+i));
	}
	auto temp=solve(l);
	for(auto p: temp){
		ret.push_back(mp(p.fr*2,p.sc*2));
	}
	auto z=f(l)*2;
	while(z<2*x){
		for(int i=0;i<l-1;i++){
			ret.push_back(mp(0,z));
			ret.push_back(mp(z,z));
		}
		z*=2;
	}
	temp=solve(x-l-1);
	ret.insert(ret.end(),temp.begin(),temp.end());
	auto y=f(x-l-1);
	while(y<x){
		for(int i=0;i<x-l-2;i++){
			ret.push_back(mp(y,0));
			ret.push_back(mp(y,y));
		}
		y*=2;
	}
	ret.push_back(mp(2*x,0));
	for(int i=1;i<=x-l-1;i++){
		ret.push_back(mp(x,0));
		ret.push_back(mp(x,x));
	}
	return ret;
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int n;
		scanf("%d",&n);
		if(n==2)puts("-1");
		else {
			auto ret=solve(n);
			ret.push_back(mp(0,f(n)));
			printf("%d\n",(int)ret.size());
			for(auto p: ret){
				printf("%d %d\n",p.fr,p.sc);
			}
		}
	}
}