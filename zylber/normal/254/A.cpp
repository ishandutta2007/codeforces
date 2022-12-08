#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int cant[5010];
int prox[5010];
int nums[700000];
int N;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    for(int i=0; i<=5000; i++)
        cant[i]=0;

    cin >> N;
    for(int i=1; i<=2*N; i++)
    {
        cin >> nums[i];
        cant[nums[i]]++;
    }

    int can=1;

    for(int i=0; i<=5000; i++)
        if(cant[i]%2)
            can=0;

    if(can)
    {
        for(int i=1; i<=2*N; i++)
        {
            if(cant[nums[i]]%2)
            {
                cout << prox[nums[i]] << " " << i << endl;
            }
            else
                prox[nums[i]]=i;
            cant[nums[i]]--;
        }
    }
    else
        cout << -1 << endl;
}