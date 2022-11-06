#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX_N=10001;

int f[MAX_N];

void upd(int pos, int x){
	for(; pos < MAX_N; pos |= pos + 1)
		f[pos] += x;
}

int get(int pos){
	int res = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		res += f[pos];
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<vector<pair<int,int>>>hs(MAX_N);
	vector<vector<pair<int,int>>>vs(MAX_N);
	for(int i=0;i<N;++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a+=5000;
		b+=5000;
		c+=5000;
		d+=5000;
		if(a>c)swap(a,c);
		if(b>d)swap(b,d);
		if(a==c){
			vs[a].push_back(make_pair(b,d));
		}else{
			hs[b].push_back(make_pair(a,c));
		}
	}
	ll answer=0;
	for(int y=0;y<MAX_N;++y){
		for(auto lr:hs[y]){
			int l=lr.first;
			int r=lr.second;
			for(int i=0;i<MAX_N;++i)f[i]=0;
			vector<vector<pair<int,int>>>querys(2*MAX_N+5);
			for(int x=l;x<=r;++x){
				for(auto ud : vs[x]){
					int u=ud.first;
					int d=ud.second;
					if(u<=y&&y<=d){
						querys[2*d+1].push_back(make_pair(x,x));
						upd(x,1);
					}
				}
			}
			for(int y2=y+1;y2<MAX_N;++y2){
				for(auto lr2:hs[y2]){
					querys[2*y2].push_back(lr2);
				}
			}
			for(int i=0;i<querys.size();++i){
				if(i%2==0){
					for(auto lr:querys[i]){
						int sum=get(lr.second)-get(lr.first-1);
						//cout<<i<<endl;
						//cout<<sum<<endl;
						answer+=sum*(sum-1)/2;
					}
				}else{
					for(auto place:querys[i]){
					//cout<<i<<endl;
						upd(place.first,-1);
					}
				}
			}
		}
	}
	cout<<answer<<endl;
	return 0;
}