import java.io.File;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.util.Scanner;

class md5_builtin{
    public static void main(String[] args) throws Exception{
        File f = new File("input.txt");
        Scanner sc = new Scanner(f);
        String msg = "";
        while(sc.hasNextLine())msg += sc.nextLine()+" ";
        sc.close();
        System.out.println(msg);
        System.out.println("Hashed: "+getMD5(msg));
    }
    public static String getMD5(String msg){
        String ans="";
        MessageDigest md;
        try{
            md = MessageDigest.getInstance("md5");
            byte[] byte_value = md.digest(msg.getBytes());
            BigInteger num = new BigInteger(1, byte_value);
            ans = num.toString(16);
            while(ans.length()<32)ans = '0'+ans;
            return ans;
        }catch(Exception e){}
        return ans;
    }
}