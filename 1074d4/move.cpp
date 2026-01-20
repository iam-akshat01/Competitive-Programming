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

        string inst;
        cin >> inst;
        int x = inst.size();

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<vector<ll>> instructions(x, vector<ll>(2));
        vector<ll> answer(x, 0);

        const ll INF = (ll)4e16;
        vector<ll> left(n, INF), right(n, INF);

        ll sh = 0;
        for (int i = 0; i < x; i++) {
            if (inst[i] == 'L') sh--;
            else sh++;
            instructions[i] = {sh, i};
        }
        sort(instructions.begin(), instructions.end());

        for (int i = 0; i < n; i++) {
            int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (idx < m) right[i] = b[idx] - a[i];
        }

        int ptr = 0;
        for (int i = 0; i < n; i++) {
            while (ptr + 1 < m && b[ptr + 1] < a[i]) ptr++;
            if (b[ptr] < a[i]) left[i] = a[i] - b[ptr];
        }

        for (int i = 0; i < n; i++) {
            ll best = INF;

            // RIGHT: shift >= right[i]
            if (right[i] != INF) {
                auto it = upper_bound(
                    instructions.begin(),
                    instructions.end(),
                    vector<ll>{right[i] - 1, INF}
                );

                if (it != instructions.end()) {
                    if ((*it)[0] >= right[i]) {
                        best = (*it)[1];
                    }
                }
            }

            // LEFT: shift <= -left[i]
            if (left[i] != INF) {
                auto it = upper_bound(
                    instructions.begin(),
                    instructions.end(),
                    vector<ll>{-left[i] - 1, INF}
                );

                // 👇 your rule: do NOT discard begin()
                if (it != instructions.end()) {
                    if ((*it)[0] <= -left[i]) {
                        best = min(best, (*it)[1]);
                    }
                }
            }

            if (best != INF) {
                answer[best]++;
            }
        }

        ll dead = 0;
        for (int i = 0; i < x; i++) {
            dead += answer[i];
            cout << n - dead << " ";
        }
        cout << "\n";
    }
    return 0;
}
