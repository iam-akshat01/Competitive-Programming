#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<int> ans(n, -1);
        int ptr = -1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                ptr = i;
                ans[i] = -1;
            } else {
                ans[i] = ptr;
            }
        }

        vector<int> sufOpen(n+1,0);
        for(int i=n-1;i>=0;i--)
            sufOpen[i] = sufOpen[i+1] + (s[i]=='(');

        int answer = -1;
        for(int i=0;i<n;i++){
            if(s[i]==')' && ans[i] > i){
                int d = ans[i] - i;
                if(sufOpen[ans[i]+1] >= d){
                    answer = max(answer, n - 2*d);
                }
            }
        }

        cout << answer << endl;
    }
}
