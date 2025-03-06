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
const int M = 1000+7;
ll dx[] = {-1, 1, 0, 0}; 
ll dy[] = {0, 0, -1, 1};
char p[25][25];
ll dis[25][25];
ll n,m;
bool is_valid(ll x,ll y){
    return (x>=0 && x<n && y>=0 && y<m && p[x][y]!='#' && p[x][y]!='m' && dis[x][y]==-1);
}
void bfs(ll start,ll man){
    queue<pair<ll,ll> >Q;
    memset(dis,-1,sizeof(dis));
    Q.push({start,man});
    dis[start][man]=0;

    while (!Q.empty())
    {
        ll position = Q.front().first;
        ll ji = Q.front().second;
        Q.pop();
        rep(i,0,4){
            ll xx = position+dx[i];
            ll yy = ji+dy[i];
            if(is_valid(xx,yy)){
                dis[xx][yy] = dis[position][ji]+1;
                Q.push({xx,yy});
            }
        }
    }
    
}
void solve(ll test){
    cin>>n>>m;
    pair<ll,ll>h,a,b,c;
    rep(i,0,n){
        rep(j,0,m){
            cin>>p[i][j];
            if(p[i][j]=='h') h={i,j};
            else if (p[i][j] == 'a') a = {i, j};
            else if (p[i][j] == 'b') b = {i, j};
            else if (p[i][j] == 'c') c = {i, j};
        }
    }

    bfs(h.first,h.second);
    ll one = dis[a.first][a.second];
    ll two =dis[b.first][b.second];
    ll three= dis[c.first][c.second];
    ll ki = max({one,two,three});
    cout << "Case " << test << ": " << ki << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;cin>>t;
    ll test =1;
    while(t--){
        solve(test);
        test++;
    }
    return 0;
}
