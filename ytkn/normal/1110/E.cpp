#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int N;
int c[200000], t[200000];
map<int, int> mpc, mpt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i];
        if(i > 0){
            int dif = c[i]-c[i-1];
            if(mpc.count(dif) == 0){
                mpc[dif] = 1;
            }else{
                mpc[dif]++;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cin >> t[i];
        if(i > 0){
            int dif = t[i]-t[i-1];
            if(mpt.count(dif) == 0){
                mpt[dif] = 1;
            }else{
                mpt[dif]++;
            }
        }
    }
    if((c[0] != t[0]) || (c[N-1] != t[N-1])){
        cout << "No" << endl;
        return 0;
    }
    for(auto i : mpc){
        if(mpt[i.first] != i.second){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}