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
    vector<string> v(n);
    for (int i=0;i<n;++i)cin>>v[i];
    int r=-1, w=-1;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (v[i][j] == 'R'){
                if (r == -1)
                    r = (i+j)%2;
                else{
                    if (r!=(i+j)%2){
                        cout << "NO" << endl;
                        return;
                    }}
            }
            if (v[i][j] == 'W'){
                if (w == -1)
                    w = (i+j)%2;
                else{
                    if (w!=(i+j)%2){
                        cout << "NO" << endl;
                        return;
                    }}
            }
        }
    }
    if (r==-1 && w==-1){
        r=0;w=1;
    }
    if (r==-1){r=1-w;}
    if (w==-1){w=1-r;}
    if (r==w){cout<<"NO"<<endl;return;}
    cout<<"YES"<<endl;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if ((i+j)%2==w) cout<<"W";
            else cout<<"R";
        }
        cout<<endl;
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