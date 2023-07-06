#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483647
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
#define check(val,pos) ((val>>pos)&1)
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
// first four also work for 90-degree clock-wise rotation
//int row[8]={0,1,0,-1,1,-1,-1,1};
//int col[8]={1,0,-1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values

vector<int> LZW_encoding(map<string,int> dic, string str){
    string s = string(1,str[0]);
    int code = 256;
    vector<int> ans;
    for(int i=1;i<str.size();i++){
        char c = str[i];
        if(dic.find(s+c)!=dic.end()){
            s+=c;
        }
        else{
            ans.pb(dic[s]);
            dic[s+c] = code++;
            s = c;
        }
    }
    ans.pb(dic[s]);
    return ans;
}
void writeFile(string file_name,vi data){
    ofstream out(file_name);
    for(int x: data) out<<x<<' ';
    out.close();
}
string LZW_decoding(map<int,string> mp,vi encoding){
    string s=mp[encoding[0]];
    string ans = mp[encoding[0]];
   
    // cout<<ans<<"***"<<endl;
    for(int i=1;i<encoding.size();i++){
        int k = encoding[i];
        string entry;
        if(mp.find(k)==mp.end())entry = s+s[0];
        else entry = mp[k];
        ans+=entry;
        mp[mp.size()] = s+entry[0];
        s = entry;
    }
    return ans;
}

vi readFile(string name){
    ifstream in(name);
    vi ans;
    int tem;
    while(in>>tem)ans.pb(tem);
    in.close();
    return ans;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    ifstream in;
    ofstream out;
    in.open("in.txt");
    string str,tem;
    while(getline(in,tem))str+=tem+"\n";
    str = str.substr(0,str.size()-1);
    map<string,int> dic;
    map<int,string> dic2;
    for(int i=0;i<256;i++){
        dic[string(1,char(i))] = i;
        dic2[i] = string(1,char(i));
    }
    
    cout<<"input: "<<str<<endl;
    vector<int> encoded = LZW_encoding(dic,str);
    writeFile("out.txt",encoded);
    vi data = readFile("out.txt");
    
    string decoded = LZW_decoding(dic2,data);
    cout<<"output: "<<decoded<<endl;
    //free();   //if pointer array
    return 0;
}
