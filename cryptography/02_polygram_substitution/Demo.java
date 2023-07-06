import java.io.File;
import java.util.*;
public class Demo {
    public static String readFile(String name){
        String text = "";
        try{
            File file = new File(name);
            Scanner sc = new Scanner(file);
            while(sc.hasNextLine()){
                text = text + sc.nextLine();
            }
            sc.close();
        }catch(Exception e){
            System.out.println(e);
        }
        return text;
    }
    public static HashMap<String,String> readDict(String name){
        HashMap<String,String> dict = new HashMap<String,String>();
        try{
            File file = new File(name);
            Scanner sc = new Scanner(file);
            while(sc.hasNextLine()){
                String[] line = sc.nextLine().split(" ");
                dict.put(line[0],line[1]);
            }
            sc.close();
        }catch(Exception e){
            System.out.println(e);
        }
        return dict;
    }
    public static void main(String[] args) {
        HashMap<String,String> dict = readDict("dictionary.txt");
        String plainText = readFile("plain.txt");
        PolygramSubstitutionCipher cipher = new PolygramSubstitutionCipher(dict);
        String cipherText = cipher.encrypt(plainText);
        System.out.println(plainText);
        System.out.println(cipherText);
        System.out.println(cipher.decrypt(cipherText));
    }
}
