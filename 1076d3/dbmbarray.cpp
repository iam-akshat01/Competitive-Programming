#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,x;
        cin>>n>>s>>x;
        int sum=0;
        for(int i=0;i<n;i++){
            int el;
            cin>>el;
            sum+=el;
        }
        if(sum>s){
            cout<<"NO"<<endl;
            continue;
        }
        int diff=s-sum;
        if(diff%x!=0){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES";
        cout<<endl;
    }
    return 0;
}