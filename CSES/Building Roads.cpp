/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2024-10-02 16:10:29
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
 using namespace std;
 #define fi first
 #define se second
 #define endl '\n'
 #define ll long long
 #define ull unsigned long long
 #define ld long double
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
 #define rep(i, a, b) for(int i = (a); i < (b); i++)
 #define per(i, a, b) for(int i = (a); i >= (b); i--)
 #define rev_str(str) reverse(str.begin(),str.end());
 #define print(v) for(auto e:v) cout<<e<<" "; cout<<endl;
 #define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
 #define printp(v) for(auto e:v) cout<<e.first<<" "<<e.second<<endl;
 #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;}
 //ll q[200005];
 const int N=1e5+7;
 //bool visited[500][500];
 // DFS
 vector<vector<ll>>graph(N+1);
 vector<bool>visited(N);
 void dfs(ll u){
    visited[u]=1;
    for(int v:graph[u]){
        if(visited[v]){
            continue;
        }
        dfs(v);
    }
 }
 void solve(){
    ll n,m;cin>>n>>m;
    rep(i,0,m){
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    } 
    ll cnt =0;
    vii p;
    vi q;
    rep(i,1,n+1){
        if(!visited[i]){
            q.push_back(i);
            dfs(i);
            cnt++;
        }
    }
    vii mpp;
    cout<<cnt-1<<endl;
    rep(i,0,sz(q)){
        if(i==sz(q)-1){
            break;
        }
        cout<<q[i]<<' '<<q[i+1]<<endl;
    }
 }
 int main() {
     fast
     ll t=1;//cin>>t;
     while (t--) {
         solve();
     }
     return 0;
}
