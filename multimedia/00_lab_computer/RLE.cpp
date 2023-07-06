#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
#define ll long long
#define endl '\n'
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values
// Run Length Encoding

string encode(string s){
    char prev='?';
    int cnt =1;
    string ans;
    for(char &ch: s){
        if(ch==prev and cnt<9){
            cnt++;
        }
        else{
            ans+=prev;
            ans+=cnt+'0';
            cnt = 1;
        }
        prev = ch;
    }
    ans+=prev;
    ans+=cnt+'0';
    return ans.substr(2,ans.size()-2);
}

string decode(string s,int len=1){
    string ans;
    for(int i=0;i<s.size();i+=len+1){
        int val = stoi(s.substr(i+1,len));
        ans+=string(s[i+1]-'0',s[i]);
    }
    
    return ans;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    freopen("codeToRLE.txt","r",stdin);
    string s,tem;
    while(getline(cin,tem)){
        s+=tem+'\n';
    }
    s=s.substr(s.size()-1);
    freopen("encoded.txt","w",stdout);
   
    string encoded = encode(s);
    cout<<encoded<<endl;

    freopen("decoded.txt","w",stdout);
    string decoded = decode(encoded);
    cout<<decoded<<endl;
    //free();   //if pointer array
    return 0;
}