#include<bits/stdc++.h>
using namespace std;

int factorial(int a) {
    if(a == 0)
        return 1;
    return (a * factorial(a - 1));
}

int smartFactorial(int a, vector<int> dp) {
    if(a == 0)
        return 1;
    if(dp[a] != -1)
        return dp[a];

    dp[a] = a * smartFactorial(a - 1, dp);
    cout<<"ignore -- "<<dp[a]<<endl;;
    return dp[a];    
}


int main() {

    int a;
    cin>>a;
    vector<int> dp(100, -1);
    for(int i = 0; i < a + 1; i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    cout<<smartFactorial(a, dp)<<endl;
    for(int i = 0; i < a + 1; i++)
        cout<<dp[i]<<" ";
    cout<<endl;

return 0;
}
