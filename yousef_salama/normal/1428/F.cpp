#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	long long res = 0, sum = 0;
	order_set X;
	
	int j = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			j = 0;
			res += sum;
			continue;
		}
		
		j++;
		if((int)X.size() < j){
			sum += i + 1;
			X.insert(i);
		}else{
			auto d = X.find_by_order((int)X.size() - j);
			
			sum += i - (*d);
			
			X.erase(d);
			X.insert(i);
		}
		res += sum;
	}
	cout << res << '\n';
	
	return 0;
}