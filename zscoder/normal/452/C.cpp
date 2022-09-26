#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
         ld a, b; cin >> a >> b;
         if(a > 1 && b > 1)  cout << fixed << setprecision(20) << ld(1+ld((a-1)*(b-1))/ld(a*b-1))/ld(a);
         else if(a == 1) cout << 1;
         else cout << ld(1)/ld(a);
return 0;
}