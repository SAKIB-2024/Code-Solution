/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2025-03-06 01:09:16
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
ll sum_Digits(ll num) {
    ll sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int bfs(int start,int end) {
    if(start==end) return 0;
    queue<pair<int,int> >Q;
    vector<bool>visited(10001,false);

    visited[start]=1;
    Q.push({start,0});

    while (!Q.empty())
    {
        int cur  = Q.front().first;
        int step = Q.front().second;
        Q.pop();
        int one = cur*3;
        int two = cur+ sum_Digits(cur);
        int three = cur -2;

        for(int i:{one,two,three}){
            if(i == end) return step+1;
            if(i>0 && i<10001 && !visited[i])
            {
                visited[i]=1;
                Q.push({i,step+1});
            }
        }
    }

    return -1;
    
}
void solve(ll test){
    ll n,m;cin>>n>>m;
    cout<<bfs(n,m)<<endl;
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
