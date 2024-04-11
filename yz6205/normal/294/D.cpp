#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    set < pair < int , int > > st;
    char cm[2];
    cin >> cm;
    int fx , fy ;
    if (cm[0] == 'U'){
        fx = -1;
    }else{
        fx = 1;
    }
    if (cm[1] == 'L'){
        fy = -1;
    }else{
        fy = 1;
    }
    long long ans = 1;
    for (int i=0;i<=n + n + m + m;i++){
        //cout << x << ' ' << y << ' ' << fx << ' ' << fy << endl;
        st.insert( pair < int , int > ( x , y ) );
        if ((int)st.size() == n + m - 2){
            cout << ans ;
            return 0;
        }
        int ga , gb;
        if (fx == -1){
            ga = x - 1;
        }else{
            ga = n - x;
        }
        if (fy == -1){
            gb = y - 1;
        }else{
            gb = m - y;
        }
        //cout << ga << ' ' << gb << endl;
        int move = min(ga,gb);
        x += fx * move;
        y += fy * move;
        ans += 1LL * move;
        if (x * fx == -1 || x * fx == n){
            fx = -fx;
        }
		if (y * fy == -1 || y * fy == m){
            fy = -fy;
        }
    }
    cout << -1 ;
    return 0;
}