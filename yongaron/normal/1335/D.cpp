#include<iostream>
#include<vector>

using namespace std;

int t;

char a[9][9];

vector<pair<int, int>> v;

int main(int argc, char const *argv[]) {
  cin>>t;
  while(t--)
  {
    v.clear();
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
      {
        cin>>a[i][j];
        if(a[i][j] == '1')
        {
          if(j%3 != 2)
            v.push_back({i, j+1});
          else
            v.push_back({i, j-2});
        }
      }
    }
    for(int i = 0; i < v.size(); i++)
      a[v[i].first][v[i].second] = '1';
    for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
        cout<<a[i][j];
      cout<<endl;
    }
  }
  return 0;
}