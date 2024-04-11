#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int padres[50010];

int main()
{
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    r1--; r2--;
    for(int i=0; i<n; i++)
    {
        if(i==r1) padres[i]=i; else { cin >> padres[i]; padres[i]--; }
    }

    int act=r2, prev=r2;
    while(act!=r1)
    {
        int next=padres[act];
        //cout << prev << " " << act << " " << next << endl;
        padres[act]=prev;
        prev = act;
        act = next;
    }
    padres[act]=prev;
    
    int printed=0;
    for(int i=0; i<n; i++) if(padres[i]!=i){ if(printed) cout << " "; cout << padres[i]+1; printed=1; }
    cout << endl;
}