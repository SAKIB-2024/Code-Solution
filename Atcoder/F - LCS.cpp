// Problem Link :- https://atcoder.jp/contests/dp/tasks/dp_f
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string a,b; 
const int N = 3030;
int dp[N][N]; 
int lcs(int i,int j){
    if(i >= a.size() || j>=b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = lcs(i+1,j);
    ans = max(ans, lcs(i,j+1));
    if(a[i] == b[j]){
        ans = max(ans , lcs(i+1,j+1)+1);
    }
    return dp[i][j] = ans;
}
void print(int i,int j ){
    if(i >= a.size() || j >= b.size()) return;
    if(a[i] == b[j]){
        cout << a[i];
        print(i+1,j+1);
        return;
    }
    int x = lcs(i+1, j);
    int y = lcs(i, j+1);
    if(x >= y){
        print(i+1, j);
    }
    else{
        print(i , j+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    print(0,0);
    //cout << print(0,0) << endl;
    return 0;
}
