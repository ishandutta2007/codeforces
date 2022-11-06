#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int a, b, c, d, id;

int n;

pair<int, int> stud[123456];

int main(int argc, char const *argv[]) {
  cin>>n;
  for(int i = 1; i <= n; i++)
  {
    cin>>a>>b>>c>>d;
    int s = a+b+c+d;
    stud[i-1] = {-s, i};
  }
  sort(stud, &stud[n]);
  for(int i = 1; i <= n; i++)
    if(stud[i-1].second == 1)
      cout<<i<<endl;
  return 0;
}