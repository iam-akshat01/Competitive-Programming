#include <bits/stdc++.h>
using namespace std;

vector<int> findfactors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> pres(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int el;
            cin >> el;
            pres[el] = 1;
        }

        vector<vector<int>> factors(n + 1);
        for (int i = 1; i <= n; i++) {
            factors[i] = findfactors(i);
        }

        vector<int> ans(n + 1, INT_MAX);
        ans[1] = 0;

        for (int i = 2; i <= n; i++) {
            for (int d : factors[i]) {
                if (pres[d] == 1 && ans[i/d]!=-1 && ans[i/d]!=INT_MAX) {
                    ans[i] = min(ans[i], ans[i / d] + 1);
                }
            }
            if (ans[i] == INT_MAX) ans[i] = -1;
        }

        ans[1]=(pres[1]==0?-1:1);

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
