#include <bits/stdc++.h>
using namespace std;

int t, n, k;

bool cmp(const string& a, const string& b){
	if(a.size() < b.size())return true;
	else if(a.size() > b.size())return false;
	else return (a < b);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		
		vector <string> v;
		for(int d = 0; d <= 9; d++){
			int sf = 0, a = 0, b = 0;
			for(int i = 0; i <= k; i++){
				if(d + i < 10){
					sf += d + i;
					a++;
				}else{
					sf += d + i - 10;
					b++;
				}
			}
			sf += b;
			
			for(int s = 0; ; s++){
				if(sf > n)break;
				
				if((n - sf) % (k + 1) == 0){
					int c = (n - sf) / (k + 1);
					
					string z = "";
					z += d + '0';
					for(int i = 0; i < s; i++)
						z += '9';
					
					if(c > 0){
						if(c <= 8){
							z += c + '0';
						}else{
							z += '8';
							c -= 8;
							while(c > 0){
								z += min(c, 9) + '0';
								c -= min(c, 9);
							}
						}
					}
					reverse(z.begin(), z.end());
					v.push_back(z);
				}
				
				sf += a * 9;
			}
		}
		
		if(v.empty())cout << -1 << endl;
		else cout << *min_element(v.begin(), v.end(), cmp) << endl;
	}
	
	return 0;
}