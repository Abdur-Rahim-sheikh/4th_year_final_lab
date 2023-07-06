#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define vd vector<double>
#define x first
#define y second
using namespace std;
map<char,pdd> table;
#define LEN 10
#define PAD 2
void makeDictionary(string text){
    map<char,double> ascii;
    
    double total=text.size();
    for(char &u: text) ascii[u]++;
    double low=0;
    for(auto data: ascii){
        table[data.x] = {low,low+(data.y/total)};
        low += data.y/total;
    }
}
double binEquivalent(double low,double high){
    double val = 0,denom=2;
    double cnt=0;
    while(val<low){
        val+= 1/denom;
        if(val>high) val -= 1/denom;
        denom*=2;
        // cnt++;
    }

    return val;
}
void saveData(vd encodings){
    string ans;
    double low = 0;
    for(int i=0;i<256;i++){
        ans+=to_string(table[i].y-table[i].x)+' ';
    }
    cout<<ans<<endl;
}
vd arithmeticEncoding(string text){
    double low=0,high=1,range=1;
    double prevLow = 0;
    int cnt = 0;
    
    vd ans;
    for(char ch: text){
        cnt++;
        low = prevLow + range * table[ch].x;
        high = prevLow + range * table[ch].y;
        range = high-low;
        prevLow = low;
        cout<<"debug "<<ch<<' '<<cnt<<endl;
        if(cnt%LEN==0){
            ans.push_back(binEquivalent(low,high));
            prevLow = low = 0;
            high=range = 1;
        }
            

    }
    return ans;
}
string arithmeticDecoding(vd encodings){
    double low,high,range;
    string ans;
    for(double &encoded: encodings){
        int cnt=LEN;
        while(cnt--){
            char ch;
            for(auto data: table){
                if(data.y.x<=encoded and encoded<=data.y.y){
                    ch = data.x;
                    break;
                }
            }
            if(ch==PAD)break;
            ans+=ch;
            low = table[ch].x;
            high = table[ch].y;
            range = high - low;
            encoded = (encoded - low)/range;
        }
    }
    return ans;
}
int main(){
    int a,b,c;
    freopen("arithmetic.txt","r",stdin);
    string tem,text;
    while(getline(cin,tem)) text+=tem+"\n";
    text.pop_back();
    while(text.size()%LEN!=0)text+=PAD;
    makeDictionary(text);
    vd encoded = arithmeticEncoding(text);
    
    saveData(encoded);
    
    string decoded = arithmeticDecoding(encoded);
    cout<<"Original:"<<text<<endl;
    cout<<"Encoded :";
    for(double &en: encoded)cout<<en<<' ';
    cout<<endl;
    cout<<"Decoded :"<<decoded<<endl;
    return 0;
}