#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n;
string s;

vector<pair<int, int>> v;

int cones = 0;
int cstr = 0;
ll csum = 0;
ll sum = 0;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>s;
  v.push_back({1e9, -1});
  for(int i = 0; i < n; i++)
  {
    if(s[i] == '0')
    {
      while(cones)
      {
        v.push_back({cones, i-cones});
        cones--;
      }
      cones = 0;
      cstr = 0;
      v.push_back({0, i});
    }
    else
    {
      cones++;
      cstr++;
      while(cones > v.back().first)
      {
        v.pop_back();
        cstr = i-v.back().second;
      }
      csum += cstr;
    }
    sum += csum;
  }
  cout<<sum<<endl;
  return 0;
}