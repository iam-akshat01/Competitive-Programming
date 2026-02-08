#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        
        vector<int> dp(n + 1, INF);
        dp[1] = 0;  

    
        vector<int> values;
        for (int x = 1; x <= n; x++) {
            if (freq[x] > 0) {
                values.push_back(x);
            }
        }

        
        for (int x : values) {
            for (int j = x; j <= n; j += x) {
                if (dp[j / x] != INF) {
                    dp[j] = min(dp[j], dp[j / x] + 1);
                }
            }
        }

        if(freq[1]!=0) dp[1]=1;
        else dp[1]=-1;
        for (int i = 1; i <= n; i++) {
            if (dp[i] == INF) cout << -1 << " ";
            else cout << dp[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
