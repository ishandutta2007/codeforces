#include <iostream>
using namespace std;

int N;
int c[3];

int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
    {
        int k;
        cin >> k;
        c[i%3]+=k;
    }

    if(c[0]>c[1] && c[0]>c[2])
    {
        cout << "chest" << endl;
    }
    else
    if(c[1]>c[2])
        cout << "biceps" << endl;
    else
        cout << "back" << endl;
}