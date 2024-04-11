#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long i64;
typedef uint32_t u32;
typedef unsigned long long u64;
typedef long double ld;
typedef long long ll; vector<string> reserved;
vector<string> tokens;
string s;

bool isReserved(const string& s) {
    return binary_search(all(reserved), s);
}

string repl = "";
string nextReplacer() {
    while (true) {
        bool done = false;
        ford(i, repl.size()) {
            if (repl[i] == 'z') repl[i] = 'a';
            else {
                ++repl[i];
                done = true;
                break;
            }
        }
        if (!done) repl += 'a';

        if (!isReserved(repl)) return repl;
    }
}

void scan() {
    int n;
    cin >> n;
    reserved.resize(n);
    forn(i, n) cin >> reserved[i];
    sort(all(reserved));

    cin >> n;

    string r;
    getline(cin, r);
    forn(i, n) {
        getline(cin, r);
        for (char c : r) {
            if (c == '#') break;
            s += c;
        }
        s += ' ';
    }
    // cerr << "INPUT\n";
    // cerr << s << endl;
}

u32 tryNum(u32 pos) {
    while (isdigit(s[pos])) ++pos;
    return pos;
}

u32 tryWord(u32 pos) {
    if (isdigit(s[pos])) return pos;
    while (isalnum(s[pos]) || s[pos] == '_' || s[pos] == '$') ++pos;
    return pos;
}

u32 tryReserved(u32 pos) {
    u32 best = pos;
    for (const auto& t : reserved) {
        if (s.substr(pos, t.size()) == t) {
            best = max<u32>(best, pos + t.size());
        }
    }
    return best;
}

void tokenize(bool print = false) {
    u32 pos = 0;
    while (pos < s.size()) {
        while (pos < s.size() && isspace(s[pos])) ++pos;
        if (pos == s.size()) break;

        u32 p1 = tryNum(pos);
        u32 p2 = tryWord(pos);
        u32 p3 = tryReserved(pos);
        // cerr << pos << " - " << p1 << " " << p2 << " " << p3 << endl;
        u32 mx = max({p1, p2, p3});
        if (mx <= pos) throw 1;

        tokens.push_back(s.substr(pos, mx - pos));
        pos = mx;
    }

    if (print) {
        cerr << "TOKENS\n";
        for (auto s : tokens) {
            cerr << "'" << s << "' ";
        }
        cerr << endl;
    }
}

void makeReplacement() {
    map<string, string> shr;
    for (auto& s : tokens) {
        if (isReserved(s) || isdigit(s[0])) continue;
        string& r = shr[s];
        if (r.empty()) r = nextReplacer();
        s = r;
    }

    /*
    cerr << "TOKENS AFTER REPLACEMENT\n";
    for (auto s : tokens) {
        cerr << "'" << s << "' ";
    }
    cerr << endl;
    */
}

vector<pii> findSegs(vector<string> tokens) {
    vector<pii> res;
    forn(l, tokens.size()) {
        string s = tokens[l];
        vector<string> expected{tokens[l]};

        for (int r = l+1; r-l < 100 && r < (int)tokens.size(); ++r) {
            s += tokens[r];
            expected.push_back(tokens[r]);

            try {
                ::s = s;
                ::tokens.clear();
                tokenize();
            } catch (...) {
                res.emplace_back(l, r-1);
                break;
            }
            if (::tokens != expected) {
                // for (auto x : expected) cerr << x << " ";
                // cerr << "  --  ";
                // for (auto x : ::tokens) cerr << x << " "; cerr << endl;
                res.emplace_back(l, r-1);
                break;
            }
        }
    }
    /*
    cerr << "SEGMENTS\n";
    for (const auto& t : res) {
        cerr << t.fi << " " << t.se << endl;
    }
    */
    return res;
}

vi findPoints(vector<pii> segs) {
    sort(all(segs), [](const pii& a, const pii& b) { return a.se < b.se; });
    vi res;
    int last = -1;
    for (auto s : segs) {
        int l, r;
        tie(l, r) = s;
        // cerr << "seg " << l << " " << r << endl;
        if (last >= l) continue;
        res.push_back(r);
        last = r;
    }
    /*
    cerr << "POINTS\n";
    for (auto x : res) cerr << x << " ";
    cerr << endl;
    */
    return res;
}

bool canBeWord(const string& s) {
    for (char c : s) {
        if (isalnum(c) || c == '_' || c == '$') {}
        else return false;
    }
    return true;
}

bool needSpace(const string& s1, const string& s2) {
    s = s1 + s2;
    tokens.clear();
    try {
    tokenize();
    } catch (...) {
        return true;
    }
    if (tokens.size() == 2 && tokens[0] == s1 && tokens[1] == s2) return false;
    return true;
}

void print(vector<string> tokens, vi splits) {
    string finalVersion;
    splits.push_back(-1);
    u32 ptr = 0;
    forn(i, tokens.size()) {
        cout << tokens[i];
        finalVersion += tokens[i];
        if (splits[ptr] == i) {
            finalVersion += " ";
            cout << " ";
            ++ptr;
        }
    }
    cout << endl;
    return;

    s = finalVersion;
    ::tokens.clear();
    cerr << "NEED\n";
    for (auto s : tokens) {
        cerr << "'" << s << "' ";
    }
    cerr << endl;
    tokenize(true);
    assert(tokens == ::tokens);
}


int main() {
#ifdef LOCAL
    freopen("j.in", "r", stdin);
#endif

    scan();
    tokenize();
    makeReplacement();
    auto tokens = ::tokens;
    auto segs = findSegs(tokens);
    auto pts = findPoints(segs);
    print(tokens, pts);

#ifdef LOCAL
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
    return 0;
}