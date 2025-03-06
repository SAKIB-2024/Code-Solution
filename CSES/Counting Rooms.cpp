/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2024-12-14 00:27:26
 *   BANGLADESH , SYLHET.
 */ 
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//gp_hash_table<int, int> table;
using namespace std;
#define fi first
#define se second
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define PI acos(-1.0)
#define pb push_back
#define mp make_pair
#define vi vector<ll>
#define maxn 500005
#define mod 1000000007
#define inf 1000000007
#define pii pair<ll,ll>
#define vii vector<pii>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define lcm(a,b) ((a*b)/__gcd(a,b));
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define setbits(x) __builtin_popcountll(x)
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define rev_str(str) reverse(str.begin(),str.end());
#define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define printp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
const ll N= 1e9+7;
 
ll dx[]= {-1,1,0,0};
ll dy[]= {0,0,-1,1};
 
bool valid(ll x,ll y,ll n, ll m,vector<vector<bool> >&visited, vector<vector<char> >&p){
    return (x>=0 && x<n && y>=0 && y<m && !visited[x][y] && p[x][y]=='.');
}
 
void dfs(ll x,ll y,ll n, ll m,ll &k,vector<vector<bool> >&visited, vector<vector<char> >&p){
    visited[x][y]=true;
 
    for(int i=0;i<4;i++){
        ll next_x = x+dx[i];
        ll next_y = y+dy[i];
 
        if(valid(next_x,next_y,n,m,visited,p)){
            dfs(next_x,next_y,n,m,k,visited,p);
        }
    }
}
void solve(){
    ll n,m;cin>>n>>m;
    vector<vector<char> >p(n,vector<char>(m)); 
    vector<vector<bool> > visited(n,vector<bool>(m));
    ll ini_x,ini_y,k=0;
    rep(i,0,n){
        rep(j,0,m){
            cin>>p[i][j];
            // if(p[i][j]=='@'){
            //     ini_x=i;
            //     ini_y=j;
            // }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(!visited[i][j] && p[i][j]=='.'){
                k++;
                dfs(i,j,n,m,k,visited,p);
            }
        }
    }
    cout<<k<<endl;
    //dfs(ini_x,ini_y,n,m,k,visited,p);
    //cout << "Case " << cnt << ": " << k << endl;
}
int main() {
    fast
    ll t = 1;//cin >> t;
    //ll cnt =1;
    while (t--) {
        solve();
        //cnt++;
    }
    return 0;
}    
