#include <iostream>
using namespace std;

int dd(int y)
{
    int d[10];
    for(int i=0; i<10; i++)
        d[i]=0;

    while(y>0)
    {
        d[y%10]++;
        y/=10;
    }

    for(int i=0; i<10; i++)
        if(d[i]>1)
            return 0;

    return 1;
}

int main()
{
    int y;
    cin >> y;
    y++;

    while(!dd(y))
    {
        y++;
    }

    cout << y << endl;
}