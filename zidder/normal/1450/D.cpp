#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
map<int, int> cnts;
void solven(vector<int>& v, int begin, int end, int start=1){
    if (begin == end){
        return;
    }
    if (cnts[start] == 0){
        for(int i=begin;i<end;++i)
            cout << 0;
        return;
    }
    if (cnts[start] > 1){
        for(int i=begin;i<end-1;++i)
            cout << 0;
        cout << 1;
        return; 
    }
    if (v[begin] == start){
        solven(v, begin+1, end, start+1);
    } else{
        if (v[end-1] == start){
            solven(v, begin, end-1, start+1);
        }
        else {
            bool perm=true;
            for (int i=start;i<start+end-begin;++i){
                if (cnts[i]!=1)
                    perm=false;
            }
            cout << (int)perm;
            for (int i=begin+1;i<end-1;++i)
                cout << 0;
        }
    }
    cout << 1;
}

void solve(int test_ind){
    cin >> n;
    vector<int> v(n);
    cnts.clear();
    for (int i=0;i<n;++i){
        scanf("%d", &v[i]);
        cnts[v[i]]++;
    }
    solven(v, 0, n);
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