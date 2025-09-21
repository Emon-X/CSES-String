#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Node{
    Node *nxt[26];
    bool end;
    Node(){
        end = false;
        for(int i=0;i<26;i++) nxt[i] = NULL;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(const string &word)
    {
        Node *curr = root;
        for(auto ch:word){
            ll idx = ch - 'a';
            if(curr->nxt[idx]==NULL) curr->nxt[idx] = new Node();

            curr = curr->nxt[idx];
        }
        curr->end = true;
    }

};

void domain_expension()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll k;
    cin >> k;
    Trie t;
    
    for(int i=0;i<k;i++){
        string w;
        cin >> w;
        t.insert(w);
    }
    vector<ll>dp(n+1,0);
    dp[0] = 1;

    for(int i=0;i<n;i++)
    {
        Node *curr = t.root;
        for(int j=i;j<n;j++){
            ll idx = s[j]-'a';
            if(curr->nxt[idx]==NULL) break;

            curr= curr->nxt[idx];
            if(curr->end){
                dp[j+1]+=dp[i];
                dp[j+1]%=mod;
            }
        }
    }
    cout << dp[n]%mod << endl;


}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}