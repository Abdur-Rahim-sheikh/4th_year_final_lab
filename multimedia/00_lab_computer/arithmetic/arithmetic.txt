#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pdi pair<double,int>
#define x first
#define y second
using namespace std;
map<char,pdd> table;

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
double arithmeticEncoding(string text){
    double low=0,high=1,range=1;
    double prevLow = 0;
    for(char ch: text){
        low = prevLow + range * table[ch].x;
        high = prevLow + range * table[ch].y;
        range = high-low;
        prevLow = low;
    }
    return binEquivalent(low,high);
}
string arithmeticDecoding(double encoded){
    double low=0,high=1,range=1;
    string ans;
    
    while(true){
        char ch;
        for(auto data: table){
            if(data.y.x<=encoded and encoded<data.y.y){
                ch = data.x;
                break;
            }
        }
        ans+=ch;
        if(ch=='$')return ans;
        low = table[ch].x;
        high = table[ch].y;
        range = high - low;
        encoded = (encoded - low)/range;
    }
}
int main(){
    int a,b,c;
    freopen("arithmetic.txt","r",stdin);
    string tem,text;
    while(getline(cin,tem)) text+=tem+"\n";
    text.pop_back();
    makeDictionary(text);
    double encoded = arithmeticEncoding(text);
    string decoded = arithmeticDecoding(encoded);
    cout<<"Original:"<<text<<endl;
    cout<<"Encoded :"<<encoded<<endl;
    cout<<"Decoded :"<<decoded<<endl;
    return 0;
}