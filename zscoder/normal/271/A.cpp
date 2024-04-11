#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool distinct(int n)
{
   vector <int> h;
   while(n > 0)
   {
        h.push_back(n % 10);
        n /= 10;
   }
   sort(h.begin(), h.end());
   for(int i = 0; i < h.size() - 1; i++)
   {
       if(h.at(i) == h.at(i + 1))
       {
           return false;
       }
   }
   return true;
}
int main()
{
    int n;
    cin >> n;
    n++;
    while(!distinct(n))
    {
        n++;
    }
    cout << n;
    return 0;
}