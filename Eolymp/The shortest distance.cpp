/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2025-02-21 23:03:31
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
ll dx[]={-1,1,0,0};
ll xx,yy;
ll dy[]={0,0,-1,1};
void bfs(int start,ll n,vector<vector<ll> > &matrix) {
    vector<ll>distance(n,-1);
    queue<ll>Q;
    start--;
    distance[start] =0;
    Q.push(start);
    while(!Q.empty()){
        ll node = Q.front();
        Q.pop();
        for(int i = 0;i<n;i++){
            if(matrix[node][i]==1 && distance[i]==-1){
                distance[i]=distance[node]+1;
                Q.push(i);
            }
        }
    }

    print(distance);
}
void solve(ll test){
    ll n,m;cin>>n>>m;
    vector<vector<ll> >matrix(n,vector<ll>(n));
    rep(i,0,n){
        rep(j,0,n){
            cin>>matrix[i][j];
        }
    }

    bfs(m,n,matrix);
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
