#include<bits/stdc++.h>

using namespace std;
string readFile(string name){
    ifstream in(name);
    string ans,tem;
    while(getline(in,tem)) ans+=tem+"\n";
    ans = ans.substr(0,ans.size()-1);
    return ans;
}
struct st{
    char ch;
    int fr;
    st *l,*r;
    st(char ch, int fr){
        l = r = nullptr;
        this->ch = ch;
        this->fr = fr;
    }
    st(char ch,int fr,st *left,st *right){
        this->ch = ch;
        this->fr = fr;
        l = left;
        r = right;
    }
};
struct Compare{
    bool operator()(st *a,st *b){
        return a->fr > b->fr;
    }
};

void dfs(st *node,map<char,string> &mp,string s){
    if(node->l==nullptr && node->r==nullptr){
        mp[node->ch] = s;
        return;
    }
    cout<<node->ch<<endl;
    dfs(node->l,mp,s+'0');
    dfs(node->r,mp,s+'1');
}
map<char,string> buildTree(string data){
    map<char,int> freq;
    
    for(char ch: data)freq[ch]++;
    priority_queue<st*,vector<st*>,Compare> pq;
    for(auto it: freq){
        st *tem = new st(it.first,it.second);
        pq.push(tem);
    }
    
    while(pq.size()>1){
        st *a = pq.top(); pq.pop();
        st *b = pq.top(); pq.pop();
        cout<<a->ch<<' '<<a->fr<<' '<<b->ch<<' '<<b->fr<<endl;
        st *tem = new st('?',a->fr+b->fr,a,b);
        pq.push(tem);
    }
    map<char,string> mp;
    dfs(pq.top(),mp,"");
    for(auto it: mp) cout<<it.first<<' '<<it.second<<endl;
    return mp;
}
string encodeHuffman(map<char,string> mp,string data){
    string ans;
    for(char ch: data) ans+=mp[ch];
    return ans;
}
void writeFile(string name,string data){
    ofstream out(name);
    out<<data;
    out.close();
}
string decodeHuffman(map<char,string> mp,string data){
    string ans;
    map<string,char> mp2;
    for(auto it: mp) mp2[it.second] = it.first;
    string tem;
    for(char ch: data){
        tem+=ch;
        if(mp2.find(tem)!=mp2.end()){
            ans+=mp2[tem];
            tem = "";
        }
    }
    return ans;
}
int main(){
    // implementing huffman coding
    int a,b,c;

    string data = readFile("in.txt");
    map<char,string> map = buildTree(data);
    string encoded = encodeHuffman(map,data);
    writeFile("out.txt",encoded);
    string data2 = readFile("out.txt");
    string decoded = decodeHuffman(map,data2);
    cout<<encoded<<' '<<decoded<<endl;
}