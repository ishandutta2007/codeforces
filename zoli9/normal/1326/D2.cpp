#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int N;
int L[2000009];
string s;
string results;

//Manacher from GeeksforGeeks

void findLongestPalindromicString(string &text)
{
    pair<int, int> res={1, 0};
    int N = text.size();
    if(N == 0)
        return;
    N = 2*N + 1; //Position count
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition
    int R = 2; //centerRightPosition
    int i = 0; //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    //Uncomment it to print LPS Length array
    //printf("%d %d ", L[0], L[1]);
    for (i = 2; i < N; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        L[i] = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0)
            L[i] = min(L[iMirror], diff);

        //Attempt to expand palindrome centered at currentRightPosition i
        //Here for odd positions, we compare characters and
        //if match then increment LPS Length by ONE
        //If even position, we just increment LPS by ONE without
        //any character comparison
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&
            ( ((i + L[i] + 1) % 2 == 0) ||
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] )))
        {
            L[i]++;
        }

        if(L[i]==i && L[i] > res.first)  // Track maxLPSLength
        {
            res.first=L[i];
            res.second=0;
        }
        if(L[i]==N-1-i && L[i] > res.first)
        {
            res.first=L[i];
            res.second=1;
        }

        //If palindrome centered at currentRightPosition i
        //expand beyond centerRightPosition R,
        //adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    if(res.second==0)
    {
        for(int ii=0; ii<res.first; ii++)
        {
            cout<<text[ii];
        }
    }
    else
    {
        int ts=text.size();
        for(int ii=ts-1; ii>=ts-res.first; ii--)
        {
            cout<<text[ii];
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>s;
        results="";
        int h=s.size();
        int k1=0;
        int k2=h-1;
        while(k1<k2)
        {
            if(s[k1]==s[k2])
            {
                results+=s[k1];
                k1++;
                k2--;
            }
            else break;
        }
        if(k1>=k2)
        {
            cout<<s<<'\n';
            continue;
        }
        cout<<results;
        int rs=results.size();
        string z=s.substr(rs, h-2*rs);
        findLongestPalindromicString(z);
        for(int j=rs-1; j>=0; j--)
        {
            cout<<results[j];
        }
        cout<<'\n';
    }


    return 0;
}