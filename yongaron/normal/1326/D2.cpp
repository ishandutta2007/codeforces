#include<bits/stdc++.h>

using namespace std;

int t, n;
string s;
string r;

int pi[1234567];
bool p[1234567];

int longest_palindrome_prefix(const string &sr)
{
    string kmprev = sr;
    reverse(kmprev.begin(), kmprev.end());
    string kmp = sr + "#" + kmprev;

    vector<int> lps(kmp.size(), 0);   // lps[i] = longest suffix length for substring kmp[0..i] where the suffix == prefix
    for (int i = 1; i < (int)lps.size(); ++i)
    {
        int prev_idx = lps[i - 1];

        while (prev_idx > 0 && kmp[i] != kmp[prev_idx])
        {
            prev_idx = lps[prev_idx - 1];
        }

        lps[i] = prev_idx + (kmp[i] == kmp[prev_idx] ? 1 : 0);
    }

    // after KMP's LPS preprocessing, the last index of the LPS array will contain the longest palindrome prefix' length!
    return lps[lps.size() - 1];
}


int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>t;
  while(t--)
  {
    cin>>s;
    n = s.size();
    int presuf = 0;
    for(int i = 0; i < n && i < n-i-1; i++)
    {
      if(s[i] != s[n-i-1])
        break;
      presuf++;
    }
    r = "";
    for(int i = presuf; i < n-presuf; i++)
      r += s[i];
    int best = 0;
    int ma = longest_palindrome_prefix(r);

    string rr;
    for(int i = 0; i < r.size(); i++)
      rr += r[r.size()-i-1];
    int mar = 0;
    mar = longest_palindrome_prefix(rr);

    string ans;
    if(ma == 0 && r.size())
      ma = 1;
    for(int i = 0; i < presuf; i++)
      ans += s[i];
    // cout<<r<<" "<<ma<<" "<<mar<<endl;
    if(ma > mar)
    {
      for(int i = 0; i < ma; i++)
        ans += r[i];
    }
    else
    {
      for(int i = 0; i < mar; i++)
        ans += r[r.size()-mar+i];
    }
    for(int i = 0; i < presuf; i++)
      ans += s[n-presuf+i];
    cout<<ans<<endl;
  }

  return 0;
}