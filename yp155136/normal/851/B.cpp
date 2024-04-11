#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    LL ax,ay,bx,by,cx,cy;
    cin >> ax >>ay >> bx >>by >> cx >> cy;
    if ((bx-ax)*(bx-ax)+(ay-by)*(ay-by) != (cx-bx)*(cx-bx)+(cy-by)*(cy-by)) puts("No");
    else if ((ax-bx)*(ay-cy) == (ax-cx)*(ay-by)) puts("No");
    else puts("Yes");
}