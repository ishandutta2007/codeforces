#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n, m;
    cin >> n >> m;
    int c = 0;
    map<int, int> mp;
    for (int i=0;i<m;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == y)
            continue;
        mp[x] = y;
    }
    while(!mp.empty()){
        int p = mp.begin()->first;
        int p1 = p;
        while (mp.count(p)){
            int pp = mp[p];
            mp.erase(p);
            p = pp;
            c++;
        }
        if (p1 == p)
            c++;
    }
    cout << c << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}