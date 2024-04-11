#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;

    long long T = (long long)1e18;
    int ans = 1;
    for(long long j = 0; j < T; ++j) 
        for(long long i = 0; i < T; ++i) ans *= 2;

    if(ans){
        cout << n << '\n';
        for(int i = 0; i < n; ++i) cout << "1 ";
    }
    else
    {
        cout << "1\n1";
    }
    
    return 0;
}