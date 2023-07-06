import java.io.File;
import java.util.*;
// import caeserCipher;
public class Demo {
    public static void main(String[] args) throws Exception{
        // read from text file
        File file = new File("input.txt");
        Scanner sc = new Scanner(file);
        String input,tem;
        input = "";
        while(sc.hasNextLine()){
            tem = sc.nextLine();
            input = input + " " +tem;
        }
        sc.close();
        System.out.println(input);
        caeserCipher obj = new caeserCipher(3,26);

        String encrypted = obj.encrypt(input);
        String decrypted = obj.decrypt(encrypted);
        System.out.println("Encrypted: "+encrypted);
        System.out.println("Decrypted: "+decrypted);
    }
}
