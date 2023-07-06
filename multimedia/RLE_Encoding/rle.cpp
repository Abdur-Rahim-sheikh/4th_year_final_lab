#include<bits/stdc++.h>
using namespace std;
// Run Length Encoding

string encode(string s){
    char prev='?';
    int cnt =1;
    string ans;
    for(char &ch: s){
        if(ch==prev and cnt<128){
            cnt++;
        }
        else{
            ans+=prev;
            ans+=cnt;
            cnt = 1;
        }
        prev = ch;
    }
    ans+=prev;
    ans+=cnt;
    return ans.substr(2,ans.size()-2);
}

string decode(string s){
    string ans;
    for(int i=0;i<s.size();i+=2) ans+=string(s[i+1],s[i]);
    return ans;
}
string readFile(string name){
    ifstream in;
    in.open(name);
    string s,tem;
    while(getline(in,tem))s+=tem+"\n";
    s = s.substr(0,s.size()-1);
    // in.close();
    return s;
}
void writeFile(string name,string text){
    ofstream out;
    out.open(name);
    out<<text;
    out.close();
    return;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    string text,enc;
    text = readFile("in.txt");

    string encoded = encode(text);
    writeFile("encoded.txt",encoded);
    
    enc = readFile("encoded.txt");

    // decode file and save
    string decoded = decode(enc);
    writeFile("decoded.txt",decoded);
    cout<<decoded<<endl;
    //free();   //if pointer array
    return 0;
}