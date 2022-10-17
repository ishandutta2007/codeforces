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
    string A, B;
    cin >> A >> B;
    set<int> mp[20];
    for (int i=0;i<n;++i){
        if (A[i]>B[i]){
            cout << -1 << endl;
            return;
        }
        if (A[i]<B[i]){
            mp[A[i]-'a'].insert(B[i]-'a');
        }
    }
    vector<int> v(20, -1);
    for (int i=0;i<20;i++){
        for (int j=i+1;j<20;j++){
            int w = 0;
            for (int q:mp[i])
                if (mp[j].count(q))
                    w++;
            if (w || mp[i].count(j)){
                v[i]=j;
                for (int q:mp[i])
                    mp[j].insert(q);
                break;
            }
        }
    }
    int c = 0;
    for(int i=0;i<v.size();++i){
        if (v[i]!=-1)
        {
            c++;
        }
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