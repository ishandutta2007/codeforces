#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

double a[25], b[25];

int main() {
    int n; double V;
    cin >> n >> V;
    
    double sum=0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
        V=min(V, (b[i]/a[i])*sum);
    }
    cout << V << endl;
}