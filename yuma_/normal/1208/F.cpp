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
using ld = __float128;
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
	
	
using ll = long long int;
const int TT=21;
const int NN=1<<TT;
vector<ll>datas(2*NN-1);

void upd2(int place){
	place+=NN-1;
	while(place){
		//WHATS(place)
		int next_place=(place-1)>>1;
		//WHATS(next_place)
		datas[next_place]=datas[(next_place<<1)+2];
		//WHATS(next_place)
		//WHATS(datas[next_place])
		//WHATS(datas[place])
		place=next_place;
	}
}

void upd(int num){
	num^=NN-1;
	//WHATS(num)
	if(datas[num+NN-1]==2)return;
	else{
		datas[num+NN-1]++;
		vector<int>places;
		places.push_back(num);
		//WHATS(num);

		for(int i=0;i<TT;++i){

			if((num&(1<<i))==0){

				vector<int>next_places;
				for(auto place:places){
					int next_place=place^(1<<i);
					if(datas[next_place+NN-1]>=2)continue;
					else{
						datas[next_place+NN-1]+=datas[place+NN-1];
						next_places.push_back(next_place);
					}
				}
				places.insert(places.end(),next_places.begin(),next_places.end());
			}
			//WHATS(num);

		}
		//WHATS(places)
		for(auto place:places){
			upd2(place);
		}
	}
}
int solve(const int num){
	int k=0;
	int place=0;
	if(datas[0]<2)return -1;
	for(int i=TT-1;i>=0;--i){
		//WHATS(k)
		////WHATS(datas[2*place+1])
		//WHATS(datas[2*place+2])
		if(num&(1<<i)){
			k+=(1<<i);
			place=place*2+2;
		}else{
			if(datas[2*place+1]>=2){
				k+=(1<<i);
				place=place*2+1;
			}else{
				place=place*2+2;
			}
		}
	}
	return k;
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i){
		cin>>v[i];
	}
	int answer=-1;
	for(int i=N-1;i>=0;--i){
		int num=v[i];
		int k=solve(num);

		//WHATS(k);
		answer=max(answer,k);
		upd(num);
	}
	cout<<answer<<endl;
	return 0;
}