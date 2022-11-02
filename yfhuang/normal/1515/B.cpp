#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

bool sq(int n){
    for(int i = 1;i * i <= n;i++){
        if(i * i == n)
            return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if((n % 2 == 0 and sq(n / 2)) or (n % 4 == 0 and sq(n / 4))){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}