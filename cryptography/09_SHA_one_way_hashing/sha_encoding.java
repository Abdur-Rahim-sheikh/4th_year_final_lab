import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.util.Scanner;

class sha_encoding{
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        File f = new File("output.txt");
        PrintWriter writer = new PrintWriter(f);
        String msg = sc.nextLine();
        sc.close();
        writer.print(getSHA(msg));
        writer.close();
    }
    public static String getSHA(String msg){
        String ans="";
        try{
            MessageDigest md = MessageDigest.getInstance("SHA-1");
            byte[] arr = md.digest(msg.getBytes());
            BigInteger num = new BigInteger(1, arr);
            ans = num.toString(16);
            while(ans.length()<40)ans = "0"+ans;
        }catch(Exception e){System.out.println(e);}
        return ans;
    }
}