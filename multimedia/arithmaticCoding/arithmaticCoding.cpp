#include<bits/stdc++.h>

using namespace std;

#define pdd pair<double,double>
#define mcd map<char,pdd>

string readFile(string name){
    ifstream in(name);
    string ans,tem;
    while(getline(in,tem))ans+=tem+"\n";
    ans = ans.substr(0,ans.size()-1);
    return ans;
}
void writeFile(string file_name,string data){
    ofstream out(file_name);
    out<<data;
    out.close();
}
map<char,pdd> getPercentage(string &data){
    map<char,pdd> mp;
    data+='$';
    for(char c: data) mp[c].second++;
    double begin = 0;
    
    for(auto &it: mp) {
        // cout<<it.first<<"} "<<it.second.second<<endl;
        it.second.first = begin;
        it.second.second=it.second.first+it.second.second/data.size();
        begin=it.second.second;
        cout<<it.first<<' '<<it.second.first<<' '<<it.second.second<<endl;
    }
    return mp;
}
double getBin(double a,double b){
    double ans = 0,tem = 0.5;
    while(ans<a){
        ans+=tem;
        if(ans>b) ans-=tem;
        tem/=2;
    }
    return ans;
}
double encodeArithmatic(mcd &mp,string data){
    double begin = 0;
    double end = 1;
    for(char c: data){
        double new_begin = begin+(end-begin)*mp[c].first;
        double new_end = begin+(end-begin)*mp[c].second;
        begin = new_begin;
        end = new_end;
        // cout<<c<<' '<<begin<<' '<<end<<endl;
    }
    return getBin(begin,end);
}
string decodeArithmatic(mcd &mp,double encoded){
    string ans;
    double begin = 0;
    double end = 1;
    while(true){
        char c;
        for(auto it: mp){
            if(it.second.first<=encoded && it.second.second>encoded){
                c = it.first;
                break;
            }
        }
        if(c=='$')break;

        ans+=c;
        double begin = mp[c].first;
        double end = mp[c].second;
        encoded = (encoded-begin)/(end-begin);
    }
    return ans;
}
int main(){
    // we will implement arithmatic coding here
    // we will use the same example as in the book
    string data = readFile("input.txt");
    map<char,pdd> mp = getPercentage(data);
    double encoded = encodeArithmatic(mp,data);
    string decoded = decodeArithmatic(mp,encoded);
    cout<<encoded<<endl;
    cout<<decoded<<endl;
}