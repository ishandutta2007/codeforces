#include <iostream>
using namespace std;

int main() {
	int t, k;
  cin>>t>>k;
  cout<<min(t, k)<<" "<<(max(t, k)-min(t, k))/2;
}