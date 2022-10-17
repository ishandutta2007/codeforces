#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;	
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    if (dx == 0 || dy == 0){
        cout << dx + dy << endl;
    } else {
        cout << dx + dy + 2 << endl;
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}