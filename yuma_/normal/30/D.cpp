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
ld dis(pair<int,int>a,pair<int,int>b){
	ld dx=a.first-b.first;
	ld dy=a.second-b.second;
	return sqrt(dx*dx+dy*dy);
}

int main() {
	
	ios::sync_with_stdio(false);

	int N,K;cin>>N>>K;
	K--;
	vector<pair<int,int>>ids;
	for(int i=0;i<N;++i){
		int x;cin>>x;
		ids.push_back(make_pair(x,i));
	}
	sort(ids.begin(),ids.end());
	int place=-1;
	for(int i=0;i<N;++i){
		if(ids[i].second==K){
			place=i;
			break;
		}
	}
	pair<int,int>start;
	vector<pair<int,int>>coors;
	for(int i=0;i<N;++i){
		coors.push_back(make_pair(ids[i].first,0));
	}
	int X,Y;cin>>X>>Y;

	coors.push_back(make_pair(X,Y));

	//WHATS(coors)
	// while(true){
	// 	int an;cin>>an;
	// 	vector<int>v(an);
	// 	for(int i=0;i<an;++i)cin>>v[i];
	// 	ld sum=0;
	// 	for(int i=0;i<an-1;++i){
	// 		sum+=dis(coors[v[i]],coors[v[i+1]]);
	// 	}
	// 	WHATS(sum);
	// }
	ld answer=1e18;
	if(place!=-1){
		{
			vector<int>low_ids;
			low_ids.push_back(0);
			for(int k=place+1;k<N;++k){
				low_ids.push_back(k);
			}
			//WHATS(low_ids)
			for(int up_id=0;up_id<low_ids.size();++up_id){
				int up=low_ids[up_id];
				ld sum=dis(coors[place],coors[0]);
				sum+=dis(coors[0],coors[up]);
				sum+=dis(coors[up],coors[N]);
				//WHATS(sum)
				if(up_id!=low_ids.size()-1){
					sum+=min(dis(coors[N],coors[N-1]),dis(coors[N],coors[low_ids[up_id+1]]));
					sum+=dis(coors[low_ids[up_id+1]],coors[N-1]);
				}
				//WHATS(sum)
				answer=min(answer,sum);
				
			}
			for(int up_id=1;up_id<low_ids.size();++up_id){
				int up=low_ids[up_id];
				ld sum=dis(coors[place],coors[up]);
				sum+=dis(coors[0],coors[up]);
				sum+=dis(coors[0],coors[N]);
				//WHATS(sum)
				if(up_id!=low_ids.size()-1){
					sum+=min(dis(coors[N],coors[N-1]),dis(coors[N],coors[low_ids[up_id+1]]));
					sum+=dis(coors[low_ids[up_id+1]],coors[N-1]);
				}
				//WHATS(sum)
				answer=min(answer,sum);
				
			}
		}
		{
			vector<int>low_ids;
			low_ids.push_back(N-1);
			for(int k=place-1;k>=0;--k){
				low_ids.push_back(k);
			}
			for(int up_id=0;up_id<low_ids.size();++up_id){
				int up=low_ids[up_id];
				ld sum=dis(coors[place],coors[N-1]);
				sum+=dis(coors[N-1],coors[up]);
				sum+=dis(coors[up],coors[N]);
				//WHATS(sum)

				if(up_id!=low_ids.size()-1){
					sum+=min(dis(coors[N],coors[0]),dis(coors[N],coors[low_ids[up_id+1]]));
					sum+=dis(coors[low_ids[up_id+1]],coors[0]);
				}
				//WHATS(sum)
				answer=min(answer,sum);
				
			}
			for(int up_id=1;up_id<low_ids.size();++up_id){
				int up=low_ids[up_id];
				ld sum=dis(coors[place],coors[up]);
				sum+=dis(coors[N-1],coors[up]);
				sum+=dis(coors[N-1],coors[N]);
				//WHATS(sum)

				if(up_id!=low_ids.size()-1){
					sum+=min(dis(coors[N],coors[0]),dis(coors[N],coors[low_ids[up_id+1]]));
					sum+=dis(coors[low_ids[up_id+1]],coors[0]);
				}
				//WHATS(sum)
				answer=min(answer,sum);
				
			}
		}
	}else{
		answer=min(dis(coors[N],coors[0]),dis(coors[N],coors[N-1]))+dis(coors[0],coors[N-1]);
	}
	
	
	cout<<setprecision(10)<<fixed<<answer<<endl;
	return 0;
}