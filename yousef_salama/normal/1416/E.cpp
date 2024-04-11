#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		int mx = 0;
		long long disp = 0, sign = 1;
		set < pair <long long, long long> > s;
		
		auto fix = [&](){
						if(sign == 1){
							while(!s.empty() && disp + sign * s.begin()->first < 1){
								if(disp + sign * s.begin()->second < 1)s.erase(s.begin());
								else{
									long long tmp = s.begin()->second;
									s.erase(s.begin());
									s.insert({1 - disp, tmp});
								}
							}
						}else{
							while(!s.empty() && disp + sign * prev(s.end())->second < 1){
								if(disp + sign * prev(s.end())->first < 1)s.erase(prev(s.end()));
								else{
									long long tmp = prev(s.end())->first;
									s.erase(prev(s.end()));
									s.insert({tmp, disp - 1});
								}
							}
						}
					};
					
		auto contains = [&](long long x){
							x = sign * x - sign * disp;
			
							auto d = s.lower_bound({x, 1LL << 50});
							if(d != s.begin()){
								if(prev(d)->second >= x)return true;
								else return false;
							}else return false;
						};
		
		for(int i = 0; i < n; i++){
			int a;
			scanf("%d", &a);
			
			if(i == 0){
				if(a % 2 == 0){
					mx = 1;
					s.insert({a / 2, a / 2});
				}else{
					mx = 0;
					s.insert({1, a - 1});
				}
			}else{
				sign = -sign;
				disp = a - disp;
				fix();
				
				if(a % 2 == 0){
					if(contains(a / 2)){
						s.clear();
						s.insert({sign * a / 2 - sign * disp, sign * a / 2 - sign * disp});
						mx += 2;
					}else{
						s.insert({sign * a / 2 - sign * disp, sign * a / 2 - sign * disp});
						mx++;
					}
				}else{
					if(s.empty()){
						if(sign == 1){
							s.insert({1 - disp, a - 1 - disp});
						}else{
							s.insert({disp - (a - 1), disp - 1});
						}
					}else{
						mx++;
					}
				}
			}
		}
		
		printf("%d\n", 2 * n - mx);
	}
	return 0;
}