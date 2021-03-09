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
const int N = 1e6;

int n, c;
int arr[N];

bool check(int d) {
    int last = -INF;
    int cnt = 0;
    rep(i, 0, n) {
        if (arr[i] - last >= d) {
            cnt++;
            last = arr[i];
        }
    }
    if (cnt >= c)
        return 1;
    return 0;

}

void solve() {
    cin >> n >> c;
    fo(i, n)
    cin >> arr[i];
    sort(arr, arr + n);

    int l = 1, u = N;
    int ans = -1;
    while (l <= u) {
        int mid = l + (u - l) / 2;
        if (check(mid) == 1) {
            ans = mid;
            l = mid + 1;
        }
        else
            u = mid - 1;
    }
    cout << ans << "\n";
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

