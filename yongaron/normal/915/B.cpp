#include <iostream>

using namespace std;

int n, p, l, r;

int main()
{
    int k = 0;
    cin>>n>>p>>l>>r;
    if(p < l)
    {
        k += l-p;
        p = l;
    }
    if(r < p)
    {
        k += p-r;
        p = r;
    }
    if(l > 1 && r == n)
        k += p-l+1;
    else if(r < n && l == 1)
        k += r-p+1;
    else if(r == n && l == 1)
        k += 0;
    else
        k += r-l+min(r-p, p-l)+2;
    cout<<k<<endl;
    return 0;
}