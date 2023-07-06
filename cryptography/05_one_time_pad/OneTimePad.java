class OneTimePad{
    int head,tail;
    String pad;
    OneTimePad(String pad){
        this.pad = pad;
        head = tail = 0;
    }
    public String encrypt(String data){
        String result = "";
        for(int i=0;i<data.length();i++){
            int index = (int)data.charAt(i);
            int key = (int)pad.charAt(head);
            int cipher = (index+key)%256;
            result += (char)cipher;
            head = (head+1)%pad.length();
        }
        return result;
    }
    public String decrypt(String enc){
        String result = "";
        for(int i=0;i<enc.length();i++){
            int index = (int)enc.charAt(i);
            int key = (int)pad.charAt(tail);
            int cipher = (index-key+256)%256;
            result += (char)cipher;
            tail = (tail+1)%pad.length();
        }
        return result;
    }
}