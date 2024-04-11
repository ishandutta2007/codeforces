#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
	os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
	for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
using ll =long long int;
int froms[500][500][2];
struct sta{
	int a;
	int b;
	int c;
};
int main() {
	
	//ios::sync_with_stdio(false);
	int da,ma,ya;
	scanf("%d.%d.%d",&da,&ma,&ya);

	vector<int>v;
	{
		int d,m,y;
		scanf("%d.%d.%d",&d,&m,&y);
		v.push_back(d);
		v.push_back(m);
		v.push_back(y);
	}
	vector<int>days{
		31,28,31,30,
		31,30,31,31,
		30,31,30,31,
	};
	sort(v.begin(),v.end());
	bool ok=false;
	do{
		int by=v[0];
		int bm=v[1];
		int bd=v[2];
		if(bm>=13)continue;
		else{
			if((by%4==0)&&bm==2&&bd==29){

			}else{
				if(bd>days[bm-1]){
					continue;
				}
			}
		}

		if(by+18<ya){
			ok=true;
		}else if(by+18>ya){

		}else{
			if(bm<ma){
				ok=true;
			}else if(bm>ma){
			}else{
				if(bd<=da){
					ok=true;
				}
			}
		}
	}while(next_permutation(v.begin(),v.end()));
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}