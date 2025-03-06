/* 
 *   @author:- MAHMUDUL HASAN SAKIB
 *   DATE & TIME :- 2025-03-06 01:09:16
 *   BANGLADESH , SYLHET.
 */ 
#include <bits/stdc++.h>
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
vector<vector<string> > chess(8,vector<string>(8));
ll dx[]={2,2,-1,1,-2,-2,1,-1};
ll dy[]={1,-1,2,2,1,-1,-2,-2};
vector<ll>dis(65);
bool visited[15][15]={0};
ll bfs(string xx,string yy){
    if(xx==yy){
        return 0;
    }
    memset(visited, 0, sizeof(visited));
    ll j = xx[0]-'a'+1;
    ll what = xx[1]-'0';
    visited[j][what]=1;
    queue<pair<string,ll> >Q; 
    Q.push({xx,0});
    while(!Q.empty()){
        string node = Q.front().first;
        ll ki = node[1]-'0';
        char ji = node[0];
        ll steps = Q.front().second;
        Q.pop();
        rep(i,0,8){
            char c = ji+dx[i];
            ll bolo = c-'a'+1;
            ll nts = ki+dy[i];
            string s ="";
            s+=c;
            s+=(nts+'0');
            if(s==yy) return steps+1;
            else if(bolo >=1 && bolo <=8 && nts >= 1 && nts <= 8 && !visited[bolo][nts]){
                visited[bolo][nts]=1;
                Q.push({s,steps+1});
            }
        }
    }
    return -1;
}
void solve(ll test){
    char c= 'a';
    rep(i,0,8){
        string s="";
        s+=c;
        rep(j,0,8){
            s+=((j+1)+'0');
            chess[i][j]=s;
            s.pop_back();
        }
        c++;
    }
    string xx,yy;
    while(cin>>xx>>yy){
        ll ki = bfs(xx,yy);
        cout << "To get from " << xx << " to " << yy << " takes " << ki << " knight moves.\n";
    }

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
