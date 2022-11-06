#include <iostream>
#include <algorithm>

using namespace std;

int n, k, x = 0;
int a[1005];

void nacti();
void vyres();

int main()
{
    nacti();
    vyres();
    cout<<x<<endl;
    return 0;
}
void nacti()
{
    cin>>n;
    cin>>k;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(&a[0], &a[n]);
}
void vyres()
{
    int p = 0;
    while(p < n)
    {
        if(a[p] <= 2*k)
        {
            k = max(k, a[p]);
            p++;
        }
        else
        {
            k *= 2;
            x++;
        }
    }
}