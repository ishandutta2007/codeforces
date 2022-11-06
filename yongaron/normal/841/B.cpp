#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a, odd = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if(a%2)
        {
            odd++;
        }
    }
    if(odd)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
    return 0;
}