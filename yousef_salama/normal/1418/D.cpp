#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	
	set <int> s;
	multiset <int> d;
	
	auto add = [&](int x){
					auto i = s.insert(x).first;
					if(i != s.begin() && i != prev(s.end())){
						d.erase(d.lower_bound((*next(i)) - (*prev(i))));
						d.insert((*i) - (*prev(i)));
						d.insert((*next(i)) - (*i));
					}else if(i != s.begin()){
						d.insert((*i) - (*prev(i)));
					}else if(i != prev(s.end())){
						d.insert((*next(i)) - (*i));
					}
				};
	auto del = [&](int x){
					auto i = s.lower_bound(x);
					if(i != s.begin() && i != prev(s.end())){
						d.insert((*next(i)) - (*prev(i)));
						d.erase(d.lower_bound((*i) - (*prev(i))));
						d.erase(d.lower_bound((*next(i)) - (*i)));
					}else if(i != s.begin()){
						d.erase(d.lower_bound((*i) - (*prev(i))));
					}else if(i != prev(s.end())){
						d.erase(d.lower_bound((*next(i)) - (*i)));
					}
					
					s.erase(i);
				};
	auto calc = [&](){
					if(s.empty())return 0;
					if(d.empty())return (*s.rbegin()) - (*s.begin());
					return (*s.rbegin()) - (*s.begin()) - (*d.rbegin());
				};
	
	vector <int> p(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &p[i]);
		add(p[i]);
	}
	printf("%d\n", calc());
	
	while(q--){
		int t, x;
		scanf("%d %d", &t, &x);
		
		if(t == 0)del(x);
		else add(x);
		
		printf("%d\n", calc());
	}
	
	return 0;
}