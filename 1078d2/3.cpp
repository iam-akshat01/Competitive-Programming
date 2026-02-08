#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<string> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }

        vector<int> can(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                can[i] |= 1 << (a[j][i] - 'a');
            }
        }

        vector<int> divs;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divs.push_back(d);
                if (d != n / d) divs.push_back(n / d);
            }
        }
        sort(divs.begin(), divs.end());

        string ans(n, 'a');

        for (int d : divs) {
            bool ok = true;
            vector<int> common(d, (1 << 26) - 1);

            for (int i = 0; i < d; i++) {
                for (int j = i; j < n; j += d) {
                    common[i] &= can[j];
                }
                if (common[i] == 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            for (int i = 0; i < d; i++) {
                char ch = 'a';
                for (int c = 0; c < 26; c++) {
                    if (common[i] & (1 << c)) {
                        ch = char('a' + c);
                        break;
                    }
                }
                for (int j = i; j < n; j += d) {
                    ans[j] = ch;
                }
            }

            break;
        }

        cout << ans << '\n';
    }

    return 0;
}
