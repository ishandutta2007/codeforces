#include <bits/stdc++.h>
using namespace std;
int n, m;
int gather;
int key[51];
class solver{
public:
	vector <pair <pair <int, int>, pair <int, int>>> ans; 
	int c[52][52];
	int x[51];
	int y[51];
	void push(pair <pair <int, int>, pair <int, int>> p){
		if(c[p.second.first][p.second.second]){
			cerr<<p.first.first<<' '<<p.first.second<<' '<<p.second.first<<' '<<p.second.second<<'\n';
			for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cerr<<c[i][j]<<" \n"[j==n];
			exit(-1);
		}
		swap(c[p.first.first][p.first.second], c[p.second.first][p.second.second]);
		if(!ans.empty()){
			if(ans.back().first==p.second&&(ans.back().second==p.first)){
				ans.pop_back();
				return;
			}
		}
		ans.push_back(p);
	}
	void move(int x, int y){
		if(x==gather){
			while(y>1){
				if(c[x][y-1]) return;
				push({{x, y}, {x, y-1}});
				y--;
			}
		}
		else if(x<gather){
			if(x+1<gather){
				push({{x, y}, {x+1, y}});
				move(x+1, y);
			}
			else{
				if(c[x+1][y]==0){
					push({{x, y}, {x+1, y}});
					move(x+1, y);
				}
				else{
					push({{x, y}, {x, y+1}});
					move(x, y+1);
				}
			}
		}
		else{
			if(x-1>gather){
				push({{x, y}, {x-1, y}});
				move(x-1, y);
			}
			else{
				if(c[x-1][y]==0){
					push({{x, y}, {x-1, y}});
					move(x-1, y);
				}
				else{
					push({{x, y}, {x, y+1}});
					move(x, y+1);
				}
			}
		}
	}
	void mask(){
		for(int i=1; i<=n; i++) key[i]=0;
		for(int i=1; i<=m; i++) if(x[i]==y[i]) key[i]=x[i];
	}
	void input(){
		for(int i=1; i<=m; i++) cin>>x[i]>>y[i];		
	}
	void solve(){
		ans.clear();
		for(int i=1; i<=m; i++) c[x[i]][y[i]]=i;
		for(int i=gather; i<=gather; i++) for(int j=1; j<=n; j++) if(c[i][j]) move(i, j);
		for(int i=gather+1; i<=n; i++) for(int j=n; j>=1; j--) if(c[i][j]) move(i, j);
		for(int i=gather-1; i>=1; i--) for(int j=n; j>=1; j--) if(c[i][j]) move(i, j);
		for(int i=1; i<=n; i++) if(c[gather][i]){
			int j=gather;
			while(j>i){
				push({{j, i}, {j-1, i}});
				j--;
			}
			while(j<i){
				push({{j, i}, {j+1, i}});
				j++;
			}
		}
		// for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cerr<<c[i][j]<<" \n"[j==n];
		for(int cnt=1; cnt<=n*n; cnt++){
			for(int i=1; i<=n; i++) if(c[i][i]){
				int id=key[c[i][i]];
				if(id==i||id==0) continue;//good
				// cerr<<id<<'\n';
				int anti_id=c[id][id];
				///move to id, i
				int x=i, y=i;
				while(x<id){
					push({{x, y}, {x+1, y}});
					x++;
				}
				while(x>id){
					push({{x, y}, {x-1, y}});
					x--;
				}
				if(anti_id){
					int xx=id, yy=id;
				///move to i, id
					while(xx<i){
						push({{xx, yy}, {xx+1, yy}});
						xx++;
					}
					while(xx>i){
						push({{xx, yy}, {xx-1, yy}});
						xx--;
					}
					while(yy<i){
						push({{xx, yy}, {xx, yy+1}});
						yy++;
					}
					while(yy>i){
						push({{xx, yy}, {xx, yy-1}});
						yy--;
					}
				}
				while(y<id){
					push({{x, y}, {x, y+1}});
					y++;
				}
				while(y>id){
					push({{x, y}, {x, y-1}});
					y--;
				}
			}
		}
		for(int i=1; i<=n; i++) key[c[i][i]]=i;
	}
	void flip(){
		reverse(ans.begin(), ans.end());
		for(auto &x: ans) swap(x.first, x.second);
	}
} S1, S2;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int main(){
	cin>>n>>m;
	if(n==1){
		cout<<"0\n";
		return 0;
	}
	S1.input();
	S2.input();
	while(true){
		gather=rng()%n+1;
		S2.mask();
		S1.solve();
		S2.solve();
		auto ans=S1.ans;
		// cerr<<ans.size()<<'\n';;
		S2.flip();
		for(auto x: S2.ans) ans.push_back(x);
		if(ans.size()>10800) continue;
		cout<<ans.size()<<'\n';;
		for(auto &x: ans) cout<<x.first.first<<' '<<x.first.second<<' '<<x.second.first<<' '<<x.second.second<<'\n';
		return 0;
	}
}