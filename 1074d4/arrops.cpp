#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, m, h;
        cin >> n >> m >> h;

        vector<ll> base(n), add(n, 0);
        vector<int> version(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> base[i];
        }

        int currentVersion = 1;

        for (int i = 0; i < m; i++) {
            ll idx, val;
            cin >> idx >> val;
            idx--;

            if (version[idx] != currentVersion) {
                version[idx] = currentVersion;
                add[idx] = 0;
            }

            add[idx] += val;

            if (base[idx] + add[idx] > h) {
                currentVersion++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (version[i] == currentVersion) {
                cout << base[i] + add[i] << " ";
            } else {
                cout << base[i] << " ";
            }
        }
        cout << "\n";
    }
}
