#include <iostream>

using namespace std;

int t;
int n;
char c[310][310];
int cnt[3];

int main()
{
 ios::sync_with_stdio(false);
 cin >> t;
 while(t--)
 {
  cnt[0] = cnt[1] = cnt[2] = 0;
  cin >> n;
  for(int i = 1; i <= n; i++)
   for(int j = 1; j <= n; j++)
    cin >> c[i][j];
  for(int i = 1; i <= n; i++)
   for(int j = 1; j <= n; j++)
    if(c[i][j] == 'X')
     cnt[(i + j) % 3]++;
  int k;
  if(cnt[0] <= cnt[1] && cnt[0] <= cnt[2])
   k = 0;
  else if(cnt[1] <= cnt[0] && cnt[1] <= cnt[2])
   k = 1;
  else
   k = 2;
  for(int i = 1; i <= n; i++)
   for(int j = 1; j <= n; j++)
    if(c[i][j] == 'X' && (i + j) % 3 == k)
     c[i][j] = 'O';
  for(int i = 1; i <= n; i++ , cout << endl)
   for(int j = 1; j <= n; j++)
    cout << c[i][j]; 
 }
 return 0;
}