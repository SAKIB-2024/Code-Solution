/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2025-03-06 01:09:16
 *   BANGLADESH , SYLHET.
 */ 
#include <algorithm>
#include <cstring>
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
bool sortByValue(const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;}
const int N = 100+10;
const int M = 1e5+7;
ll n,m;
vector<vector<ll> > graph(110);
vector<bool>visited(1000);
void bfs(ll start, ll &node){
    queue<ll>q;
    q.push(start);
    visited[start] = true;
    node = 1;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(int i:graph[u]){
            if(!visited[i]){
                visited[i]=true;
                q.push(i);
                node++;
            }
        }
    }
}

bool ok(){
    if(n!=m){
        return false;
    }
    ll node_combined = 0;
    bfs(1,node_combined);
    if(node_combined != n){
        return false;
    }
    return true;
}
void solve(ll test){
    cin>>n>>m;
    rep(i,0,m){
        ll u,v;cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }   
    if(ok()){
        cout<<"FHTAGN!"<<endl;
        //cout<<n<<' '<<m<<endl;
    }
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;//cin>>t;
    ll test =1;
    while(t--){
        solve(test);
        test++;
    }
    return 0;
}
