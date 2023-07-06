#include<bits/stdc++.h>
using namespace std;
string transposeCipher(string name,int width){
    string enc;
    for(int i=0;i<width;i++){
        for(int j=0;j*width+i<name.size();j++){
            enc+=name[j*width+i];
        }
    }
    return enc;
}
string decrypt(string name,int width){
    int len = name.size(),rem = len%width,row = len/width;
    string dec(len,'?');
    for(int i=0,ind=0;i<width;i++,rem = max(rem-1,0)){
        int tem = row+(rem>0);
        for(int j=0;j<tem;j++) dec[j*width+i] = name[ind++];
    }
    return dec;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //ifstream,ofstream
    string name = "abir is trying hard, HE BELIEVES IN ONE AND ONLY ALLAH";
    int width = 4;
    string enc = transposeCipher(name,width);
    string enc2 = transposeCipher(enc,2*width);
    cout<<enc<<endl;
    string dec = decrypt(enc2,2*width);
    string dec2 = decrypt(dec,width);
    cout<<dec2<<endl;
    return 0;
}
