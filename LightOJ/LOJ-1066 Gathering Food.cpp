/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2025-02-21 23:03:31
 *   BANGLADESH , SYLHET.
 */ 
 
#include<bits/stdc++.h>
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
const int M = 100+7;

char grid[M][M];
int graph[M][M];
ll n;
pair<ll,ll>PM[M];
ll dx[]={-1,1,0,0};
ll xx,yy;
ll dy[]={0,0,-1,1};
bool is_valid(ll x,ll y){
    return x>=0 && x<n && y>=0 && y<n && grid[x][y]!='#' && (grid[x][y] == '.' || grid[x][y] <= grid[xx][yy]);
}


void bfs(int startX, int startY) {
    queue<pair<int, int> > q;
    q.push({startX, startY});
    graph[startX][startY] = 0;

    while (!q.empty()) {
        startX = q.front().first;
        startY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = startX + dx[i];
            int newY = startY + dy[i];

            if (is_valid(newX, newY)){

                if(graph[newX][newY] != -1 && graph[newX][newY] <= graph[startX][startY] + 1) continue;
                graph[newX][newY] = graph[startX][startY] + 1;
                q.push({newX, newY});
            }
        }
    }
}
void solve(ll test){
    cin>>n;
    ll x,y=0;
    rep(i,0,n){
        rep(j,0,n){
            cin>>grid[i][j];
            if(grid[i][j]=='A'){
                x=i;
                y=j;
            }
        }
    }
    ll mx = 0;
    rep(i,0,n){
        rep(j,0,n){
            if(grid[i][j]>='A' && grid[i][j]<='Z'){
                ll ki = grid[i][j]-'A';
                PM[ki] = {i,j};
                mx = max(mx,ki);
            }
        }
    }
    ll cnt = 0;
    for(int i=0;i<mx;i++){
        xx = PM[i+1].first;
        yy = PM[i+1].second;
        memset(graph, -1, sizeof(graph));
        bfs(PM[i].first, PM[i].second);
        if (graph[xx][yy] == -1) {
            cout<<"Case "<<test<<": "<<"Impossible"<<endl;
            return;
        }
        cnt += graph[xx][yy];
    }
    cout<<"Case "<<test<<": "<<cnt<<endl;
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
