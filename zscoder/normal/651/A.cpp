#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    int charge_1, charge_2, ans;
    cin >> charge_1 >> charge_2;
    if(charge_1==1&&charge_2==1) 
    {
        cout << 0;
        return 0;
    }
    bool depleted = false;
    ans = 0;
    while(depleted != true){
        if(charge_1 >= charge_2){
            charge_2 += 1;
            charge_1 -= 2;
        }
        else{
            charge_2 -= 2;
            charge_1 += 1;
        }
        ans += 1;
        if((charge_1 <= 0) || (charge_2 <=0)){
            depleted = true;
        }
    }
    cout << ans;
    return 0;
}