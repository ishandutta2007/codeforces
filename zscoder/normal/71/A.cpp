#include <iostream>
#include <string>
using namespace std;
int main() 
{
  unsigned short int n;
  cin >> n;
  string array[n];
  int i;
  for(i = 0; i <= n - 1; i++)
  {
    cin >> array[i];
    if(array[i].size() > 10)
    {
      cout << array[i].at(0) << array[i].size() - 2 << array[i].at(array[i].size() - 1) << endl;
    }
    else
    {
      cout << array[i] << endl;
    }
  }
  return 0;
}