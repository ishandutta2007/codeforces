#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    int painting_left [1001];
    for(int i = 0; i < 1001; i++){
        painting_left[i] = 0;
    }
    int num_of_painting;
    int x;
    cin >> num_of_painting;
    int painting_took = 1;
    int ans = 0;
    for(int i = 0; i < num_of_painting; i++){
        cin >> x;
        painting_left [x] += 1;
    }
    while(painting_took != 0){
        painting_took = 0;
        for(int i = 0; i < 1001; i++){
            if(painting_left[i] > 0){
                painting_left[i] -= 1;
                painting_took += 1;
                ans += 1;
            }
        }
        ans -= 1;
    }
    
    ans += 1;
    
    cout << ans;
    
    return 0;
}