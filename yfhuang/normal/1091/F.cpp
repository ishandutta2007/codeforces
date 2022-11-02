#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5+5;
typedef long long LL;
LL l[maxn];
string s;
int main(){
	int n;
	while(cin >> n){
		for(int i = 1;i <= n;i++){
			scanf("%lld", &l[i]);
		}
		cin >> s;
		LL grass = 0, stamina = 0, time = 0;
		bool water = false;
		for(int i = 1;i <= n;i++){
			if(s[i - 1] == 'L'){
				stamina -= l[i];
				time += l[i];
				if(stamina < 0){
					time += (-stamina) * (water ? 3 : 5);
					stamina = 0;
				}
			}else if(s[i - 1] == 'G'){
				stamina += l[i];
				time += 5 * l[i];
				grass += 2 * l[i];
			}else{
				stamina += l[i];
				time += 3 * l[i];
				water = true;
			}
			grass = min(grass, stamina);
		}	
		if(stamina > 0){
			if(stamina > grass){
				time -= 2 * (stamina - grass) / 2;
			}
			time -= 4 * min(stamina, grass) / 2;
		}
		cout << time << endl;
	}
	return 0;
}