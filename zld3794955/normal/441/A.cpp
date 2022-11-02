#include <iostream>
using namespace std;

int main()
{	
  int n, v, a[50] = {0};
  cin >> n >> v;
  
  int k, x; int idx = 1;
  for(int i = 1; i <= n; ++i)
    {
      cin >> k;
      bool b = false;
      for(int j = 1; j <= k; ++j)
	{
	  cin >> x;
	  if(!b && x < v){
	    a[idx++] = i;
	    b = true;
	  }
	}
    }
  cout << idx - 1 << "\n";
  
  for(int i = 1; i < idx; ++i)
    cout << a[i] << " ";
 
 return 0;
}