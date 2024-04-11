#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	vector < pair <int, int> > v;
	stack <int> s2;
	int ind = -1;
	
	for(int i = n - 1; i >= 0; i--){
		if(a[i] == 0)continue;
		if(a[i] == 1){
			v.push_back({i + 1, i + 1});
			s2.push(i);
			continue;
		}
		if(a[i] == 2){
			if(s2.empty()){
				printf("-1\n");
				return 0;
			}
			v.push_back({s2.top() + 1, i + 1});
			s2.pop();
			ind = i;
			
			continue;
		}
		if(a[i] == 3){
			if(ind != -1){
				v.push_back({i + 1, i + 1});
				v.push_back({i + 1, ind + 1});
				ind = i;
				
				continue;
			}
			if(s2.empty()){
				printf("-1\n");
				return 0;
			}
			
			v.push_back({i + 1, i + 1});
			v.push_back({i + 1, s2.top() + 1});
			s2.pop();
			
			ind = i;
		}
	}
	
	printf("%d\n", (int)v.size());
	for(pair <int, int> p : v)
		printf("%d %d\n", p.first, p.second);
	return 0;
}