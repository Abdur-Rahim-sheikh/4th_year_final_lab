import java.util.Scanner;
import java.math.BigInteger;
public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // String msg = sc.nextLine();
        String msg = "2020",msg2="abir2020";
        sc.close();
        RSA_NUM rsa = new RSA_NUM(130);
        BigInteger enc = rsa.encryptEasy(msg);
        BigInteger dec = rsa.decryptEasy(enc);
        System.out.println(new BigInteger(msg));
        System.out.println(enc+"\n"+dec);

        // next one
        RSA_MSG rsa2 = new RSA_MSG(123);
        enc = rsa2.encrypt(msg2);
        dec = rsa2.decrypt(enc);
        System.out.println("Original: "+msg2+
        "\nenc: "+enc+
        "\ndec: "+new String(dec.toByteArray()));
    }
}
