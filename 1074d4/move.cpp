#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ll> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(b.begin(), b.end());

        const ll INF = (ll)4e18;
        vector<ll> L(n, INF), R(n, INF);

        for (int i = 0; i < n; i++) {
            ll x = a[i];
            auto it = lower_bound(b.begin(), b.end(), x);
            if (it != b.end()) R[i] = *it - x;
            if (it != b.begin()) {
                --it;
                L[i] = x - *it;
            }
        }

        string s;
        cin >> s;

        vector<pair<ll,ll>> sh;
        sh.reserve(k + 1);

        ll cur = 0;
        sh.push_back({0, 0});
        for (ll i = 1; i <= k; i++) {
            cur += (s[i - 1] == 'R' ? 1 : -1);
            sh.push_back({cur, i});
        }

        sort(sh.begin(), sh.end());

        vector<ll> dead(k + 2, 0);

        for (int i = 0; i < n; i++) {
            ll best = INF;

            if (R[i] != INF) {
                auto it = upper_bound(
                    sh.begin(), sh.end(),
                    make_pair(R[i] - 1, INF)
                );
                if (it != sh.end() && it->first >= R[i]) {
                    best = it->second;
                }
            }

            if (L[i] != INF) {
                auto it = upper_bound(
                    sh.begin(), sh.end(),
                    make_pair(-L[i], INF)
                );
                if (it != sh.begin()) {
                    --it;
                    if (it->first <= -L[i]) {
                        best = min(best, it->second);
                    }
                }
            }

            if (best <= k)
                dead[best]++;
        }

        ll alive = n;
        for (int i = 1; i <= k; i++) {
            alive -= dead[i];
            cout << alive << " ";
        }
        cout << "\n";
    }
    return 0;
}
