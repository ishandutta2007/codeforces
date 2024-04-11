#include <iostream>
#include <vector>
using namespace std;
long long int gcd(long long int a, long long int b){
    if (a<b){
        return gcd(b, a);
    }
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    long long int n, m, q;
    cin >> n >> m >> q;
    long long int g = gcd(n, m);
    for(int i=0;i<q;i++){
        long long int sx, sy, s;
        cin>>sx>>sy;
        if (sx == 1){
            s = (sy-1) / (n / g);
        }
        else{
            s = (sy-1) / (m / g);
        }
        long long int ex, ey, e;
        cin>>ex>>ey;
        if (ex == 1){
            e = (ey-1) / (n/g);
        }
        else{
            e = (ey-1) / (m/g);
        }
        if (e == s){
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}