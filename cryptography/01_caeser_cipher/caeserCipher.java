
public class caeserCipher {
    int key,modulo;
    public caeserCipher(int key,int modulo){
        this.key = key;
        this.modulo = modulo;
    }
    public String encrypt(String data){
        String enc="";
        for(int i=0;i<data.length();i++){
            char ch = data.charAt(i);
            if(ch>='a' && ch<='z'){
                ch = (char)('a'+(ch-'a'+key)%modulo);
            }
            else if(ch>='A' && ch<='Z'){
                ch = (char)('A'+(ch-'A'+key)%modulo);
            }
            enc = enc + ch;
        }
        return enc;
    }
    public String decrypt(String data){
        String dec="";
        for(int i=0;i<data.length();i++){
            char ch = data.charAt(i);
            if(ch>='a' && ch<='z'){
                ch = (char)('a'+(ch-'a'-key+modulo)%modulo);
            }
            else if(ch>='A' && ch<='Z'){
                ch = (char)('A'+(ch-'A'-key+modulo)%modulo);
            }
            dec = dec + ch;
        }
        return dec;
    }
}
