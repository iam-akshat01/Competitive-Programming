#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<ll> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        
        sort(a.begin(), a.end(), greater<ll>());

        
        vector<ll> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + b[i - 1];
        }

        ll ans = 0;

        
        for (int k = 1; k <= n; k++) {
            ll x = a[k - 1];

        
            int levels = upper_bound(pref.begin(), pref.end(), k) - pref.begin() - 1;

            ans = max(ans, x * levels);
        }

        cout << ans << '\n';
    }

    return 0;
}
