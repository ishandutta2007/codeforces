#include"bits/stdc++.h"
using namespace std;
#pragma warning(disable:4996)
using pa=pair<int,int>;

struct UnionFind {
	using Value=pair<int,int>;
	Value INI=make_pair(-1,-1);
	vector<Value> data;
	stack<pair<int,pair<int,int>>>sta;
	UnionFind(int size) : data(size, INI) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			sta.push(make_pair(y,data[y]));
			data[x].first += data[y].first;
			data[x].second+=data[y].second;
			data[y] = make_pair(x,x);
		}
		else {
			sta.push(make_pair(-7777777,make_pair(-1,-1)));
		}
		return x != y;
	}
	void roll_back() {
		assert(!sta.empty());
		auto p=sta.top();
		sta.pop();
		if(p.first==-7777777)return;

		int y=p.first;
		pair<int,int> y_sz=p.second;
		int x=root(y);
		data[x].first-=y_sz.first;
		data[x].second-=y_sz.second;
		data[y]=y_sz;
	}
	int root(int x) {
		if (data[x].first+data[x].second < 0) {
			return x;
		}
		else {
			int ro = root(data[x].first);
			return ro;

		}
	}
	pair<int,int> size(int x) {
		return make_pair(-data[root(x)].first,-data[root(x)].second);
	}
};

int MAX_N=1<<19;
vector<vector<pair<int,int>>>qs(MAX_N*2);
void dfs(int k,int l,int r,pair<int,int>place,pair<int,int>p){
    //cout<<k<<" "<<l<<r<<" "<<place.first<<place.second<<endl;
    if(r<=place.first||place.second<=l)return ;
    else if(place.first<=l&&r<=place.second){
        //cout<<3<<endl;
        //cout<<l<<" "<<r<<" "<<p.first<<" "<<p.second<<endl;
        qs[k].push_back(p);
    }else{
        int m((l+r)/2);
        dfs(2*k+1,l,m,place,p);
        dfs(2*k+2,m,r,place,p);
    }
}
long long cc(pair<int,int>p){
    long long aa=p.first;
    return aa*p.second;
}
vector<long long int>anss;
void solve(int k,int l,int r,long long &sum,UnionFind&uf){
    int cnt=0;
    vector<long long int>pluss;
    long long int memo=sum;
    for(auto q:qs[k]){
        int a=q.first,b=q.second;
        if(uf.root(a)==uf.root(MAX_N+b)){

        }else{
            cnt++;
            int aplus=0;
            aplus-=cc(uf.size(a));
            aplus-=cc(uf.size(MAX_N+b));

            uf.unionSet(a,MAX_N+b);
            aplus+=cc(uf.size(a));
            //cout<<l<<" "<<r<<endl;
            //cout<<a<<" "<<b<<endl;
            pluss.push_back(aplus);
            sum+=aplus;
            //cout<<aplus<<endl;
        }
    }
    if(l+1==r){
        anss.push_back(sum);
    }else{
        int m((l+r)/2);
        solve(2*k+1,l,m,sum,uf);
        solve(2*k+2,m,r,sum,uf);
    }
    while(cnt--){
        
        uf.roll_back();
    }
    sum=memo;
}

int main() {
	//test();
	int Q;cin>>Q;
    map<pair<int,int>,vector<int>>mp;
    for(int i=0;i<Q;++i){
        int u,v;scanf("%d %d",&u,&v);
        u--;v--;
        mp[make_pair(u,v)].push_back(i);
    }
    for(auto m:mp){
        auto v(m.second);
        for(int i=0;i<v.size();i+=2){
            int l=v[i];
            int r=v.size()==i+1?Q:v[i+1];
           // cout<<m.first.first<<" "<<m.first.second<<" "<<l<<" "<<r<<endl;
            //cout<<"a"<<endl;
            dfs(0,0,MAX_N,make_pair(l,r),m.first);
        }
    }
    UnionFind uf(2*MAX_N);
    for(int i=0;i<MAX_N;++i){
        uf.data[i]=make_pair(-1,0);
        uf.data[MAX_N+i]=make_pair(0,-1);
    }
    long long int sum=0;
    solve(0,0,MAX_N,sum,uf);
   // cout<<anss.size()<<endl;
    for(int i=0;i<Q;++i){
        printf("%lld ",anss[i]);
    }
    cout<<endl;
	return 0;
}