#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    int n;
    cin >> T;
    while(T--){
        cin >> n;
        int odd = 0, even = 0;
        for(int i = 1;i <= 2 * n;i++){
            int a;
            cin >> a;
            if(a & 1)
                odd++;
            else
                even++;
        }
        if(odd == even){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}