#include<bits/stdc++.h>
using namespace std;

#define forever         while(true)
#define int             long long
#define rep(i, s, n)    for(int i=s;i<n;i++)
#define fo(i, n)        rep(i, 0, n)
#define tr(c, it)       for(auto it : c)
#define all(c)          (c).begin(), (c).end()
#define sz(x)           (int)(x.size())
#define ff              first
#define ss              second
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define st              set<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int N = 0;

bool check(vi v, int k, int s) {
    v[0] += s;
    int sum = v[0];
    rep(i, 1, v.size()) {
        if (100 * v[i] > k * sum)
            return 0;
        sum += v[i];
    }
    return 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    fo(i, n)
    cin >> v[i];

    int s = 0, e = 1e14, m, p = 0;
    while (s <= e) {
        m = (s + e) / 2;
        if (check(v, k, m)) {
            p = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }
    cout << p << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    w(t) solve();
    return 0;
}
