#include <iostream>

using namespace std;

int main()
{
int n, m;
cin >> n >> m;
int i = 0;
int max = -1;
while(2*i <= n)
{
if((n - i) % m == 0)
{
max = n - i;
}
i++;
}
cout << max << endl;
return 0;
}