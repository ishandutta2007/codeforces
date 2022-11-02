#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int _,x,y,xx,yy;
int main(){
    cin >> _;
    while (_--){
        cin >> x >> y >> xx >> yy;
        if (x==xx){
            cout << abs(y-yy) << endl;
        } else if (y==yy){
            cout << abs(x-xx) << endl;
        } else {
            cout << 2+abs(x-xx)+abs(y-yy) << endl;
        }
    }
}