import java.util.HashMap;

class PolygramSubstitutionCipher{
    HashMap<String, String> key,key2;
    public PolygramSubstitutionCipher(HashMap<String, String> key){
        this.key = key;
        key2 = new HashMap<String, String>();
        for(String plain: key.keySet()){
            key2.put(key.get(plain),plain);
        }
    }

    public String encrypt(String plainText){
        String cipherText = "",tem="";
        for(int i = 0; i < plainText.length(); i++){
            tem = tem+plainText.substring(i, i+1);
            if(key.get(tem) != null){
                cipherText = cipherText + key.get(tem);
                tem = "";
            }
        }
        return cipherText;
    }

    public String decrypt(String cipherText){
        String plainText = "",tem="";
        for(int i = 0; i < cipherText.length(); i++){
            tem = tem+cipherText.substring(i, i+1);
            if(key2.get(tem) != null){
                plainText = plainText + key2.get(tem);
                tem = "";
            }
        }
        return plainText;
    }
}