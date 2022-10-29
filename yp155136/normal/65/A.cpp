#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    LL a,b,c,d,e,f;
    cin >>a>>b>>c>>d>>e>>f;
    if (e*a*c < b*d*f || c == 0 && d != 0 || a == 0 && b>0 && d > 0) cout << "Ron" << endl;
    else cout << "Hermione" << endl;
}