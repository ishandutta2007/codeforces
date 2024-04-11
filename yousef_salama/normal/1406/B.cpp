#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector <int> pos, neg;
		for(int i = 0; i < n; i++){
			int ai;
			scanf("%d", &ai);
			
			if(ai >= 0)pos.push_back(ai);
			else neg.push_back(-ai);
		}
		
		sort(pos.rbegin(), pos.rend());
		sort(neg.rbegin(), neg.rend());
		
		long long res = -1LL << 60;
		
		for(int c = 0; c <= min(5, (int)neg.size()); c++){
			if(5 - c > (int)pos.size()){
				continue;
			}
			
			if(c % 2 == 0){
				long long cur = 1;
				for(int i = 0; i < c; i++)cur *= neg[i];
				for(int i = 0; i < 5 - c; i++)cur *= pos[i];
				
				res = max(res, cur);
			}else{
				long long cur = -1;
				for(int i = 0; i < c; i++)cur *= neg[(int)neg.size() - i - 1];
				for(int i = 0; i < 5 - c; i++)cur *= pos[(int)pos.size() - i - 1];
				
				res = max(res, cur);
			}
		}
		
		printf("%lld\n", res);
	}
	return 0;
}