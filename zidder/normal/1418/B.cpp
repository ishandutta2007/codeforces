#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<int> l(n), v(n), v1;
    for(int i=0;i<n;++i)
        cin>>v[i];

    for(int i=0;i<n;++i)
    {
        int ll;
        cin >> ll;
        l[i]=ll;
        if (ll == 0)
            v1.push_back(v[i]);
    }
    
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());

    for (int i=0, j=0;i<n;i++){
        if (l[i] == 0){
            v[i] = v1[j++];
        }
    }
    for (int i=0;i<n;++i)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}