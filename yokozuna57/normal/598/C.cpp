#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

#define mp make_pair

int n;
ld x[100010],y[100010];

ld sgn(ld x){
	if(x>0.0)return 1;
	return -1;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	vector<pair<ld,int>> vec;
	for(int i=0;i<n;i++){
		vec.push_back(pair<ld,int>(atan2(y[i],x[i]),i));
	}
	sort(vec.begin(),vec.end());
	
	/*for(int i=0;i<vec.size();i++){
		cerr<<vec[i].second<<" ";
	}
	cerr<<endl;*/
	
	int s=vec[0].second;
	int t=vec[n-1].second;
	pair<ld,pair<int,int>> ret=mp(abs(atan2(x[s]*y[t]-x[t]*y[s],x[s]*x[t]+y[s]*y[t])),mp(s,t));
	//pair<ld,pair<int,int>> ret=mp(sgn(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])/(x[s]*x[s]+y[s]*y[s])/(x[t]*x[t]+y[t]*y[t]),mp(s,t));
	for(int i=0;i+1<vec.size();i++){
		s=vec[i].second;
		t=vec[i+1].second;
		ret=min(ret,mp(abs(atan2(x[s]*y[t]-x[t]*y[s],x[s]*x[t]+y[s]*y[t])),mp(s,t)));
		//cerr.precision(20);
		//cerr<<sgn(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])/(x[s]*x[s]+y[s]*y[s])/(x[t]*x[t]+y[t]*y[t])<<endl;
		//ret=max(ret,mp(sgn(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])*(x[s]*x[t]+y[s]*y[t])/(x[s]*x[s]+y[s]*y[s])/(x[t]*x[t]+y[t]*y[t]),mp(s,t)));
	}
	cout<<ret.second.first+1<<" "<<ret.second.second+1<<endl;
}