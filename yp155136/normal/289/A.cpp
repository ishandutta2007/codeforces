#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int a,b;
    cin >> a >>b;
    int tot=0;
    while (a--)
    {
        int l,r;
        cin >> l >> r;
        tot += (r-l+1);
    }
    if(tot%b==0) cout << "0"<<endl;
    else cout << b - tot%b << endl;
}