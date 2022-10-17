#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 998244353;

#define fr first
#define sc second

int main(){
	int n;
	ll a[100010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	vector<int> id;
	vector<P> ed;
	
	ll t = 1;
	for(int tt = 0 ; tt < 60 ; tt ++){
		vector<int> vec;
		for(int i = 0 ; i < n ; i ++){
			if(a[i]&t){
				vec.push_back(i);
			}
		}
		if(vec.size() >= 3){
			cout << 3 << endl;
			return 0;
		}
		if(vec.size() == 2){
			id.push_back(vec[0]);
			id.push_back(vec[1]);
			ed.push_back(P(vec[0],vec[1]));
		}
		t *= 2;
	}
	
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	sort(ed.begin(),ed.end());
	ed.erase(unique(ed.begin(),ed.end()),ed.end());
	
	for(int i = 0 ; i < ed.size() ; i ++){
		for(int j = 0 ; j < id.size() ; j ++){
			if(ed[i].fr == id[j]){
				ed[i].fr = j;
				break;
			}
		}
		for(int j = 0 ; j < id.size() ; j ++){
			if(ed[i].sc == id[j]){
				ed[i].sc = j;
				break;
			}
		}
	}
	
	/*for(int i = 0 ; i < ed.size() ; i ++){
		P p = ed[i];
		cout << p.fr << " " << p.sc << endl;
	}*/
	
	static int cost[130][130] = {};
	for(int i = 0 ; i < 130 ; i ++){
		for(int j = 0 ; j < 130 ; j ++){
			cost[i][j] = 1000;
		}
		cost[i][i] = 0;
	}
	for(int i = 0 ; i < ed.size() ; i ++){
		cost[ed[i].fr][ed[i].sc] = 1;
		cost[ed[i].sc][ed[i].fr] = 1;
	}
	
	for(int k = 0 ; k < id.size() ; k ++){
		for(int i = 0 ; i < id.size() ; i ++){
			for(int j = 0 ; j < id.size() ; j ++){
				cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j] );
			}
		}
	}
	
	ll ret = 1000;
	for(int i = 0 ; i < id.size() ; i ++){
		for(int s = 0 ; s < ed.size() ; s ++){
			P p = ed[s];
			if(p.fr == i || p.sc == i)continue;
			if(cost[i][p.fr] == cost[i][p.sc])ret = min( ret , (ll)cost[i][p.fr]+cost[i][p.sc]+1 );
			for(int ss = 0 ; ss < ed.size() ; ss ++){
				if(s == ss)continue;
				P q = ed[ss];
				if(q.fr == i || q.sc == i)continue;
				if(p.fr == q.fr && cost[i][p.sc] == cost[i][q.sc] && cost[i][p.sc] < cost[i][p.fr])ret = min( ret , (ll)cost[i][p.sc]*2+2 );
				if(p.fr == q.sc && cost[i][p.sc] == cost[i][q.fr] && cost[i][p.sc] < cost[i][p.fr])ret = min( ret , (ll)cost[i][p.sc]*2+2 );
				if(p.sc == q.fr && cost[i][p.fr] == cost[i][q.sc] && cost[i][p.sc] > cost[i][p.fr])ret = min( ret , (ll)cost[i][p.fr]*2+2 );
				if(p.sc == q.sc && cost[i][p.fr] == cost[i][q.fr] && cost[i][p.sc] > cost[i][p.fr])ret = min( ret , (ll)cost[i][p.fr]*2+2 );
			}
		}
	}
	if(ret == 1000)cout << -1 << endl;
	else cout << ret << endl;
}