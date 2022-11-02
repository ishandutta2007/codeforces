#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll a[7000], b[7000];
bool used[7000];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    ll ans = 0;
    vector<ll> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] == a[j]){
                if((!used[i])&&(!used[j])) v.push_back(a[i]);
                if(!used[i]) {
                    ans += b[i];
                    used[i] = true;
                }
                if(!used[j]){
                    ans += b[j];
                    used[j] = true;
                }
            }
        }
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < n; j++){
            if(used[j]) continue;
            if((v[i]|a[j]) == v[i]){
                ans += b[j];
                used[j] = true;
            }
        }
    }
    cout << ans << endl;
}