import java.io.File;
import java.util.*;

public class TransposeCipher {
    public static String transposeCipher(String name, int width) {
        StringBuilder enc = new StringBuilder();
        for (int i = 0; i < width; i++) {
            for (int j = 0; j * width + i < name.length(); j++) {
                enc.append(name.charAt(j * width + i));
            }
        }
        return enc.toString();
    }

    public static String decrypt(String name, int width) {
        int len = name.length();
        int rem = len % width;
        int row = len / width;
        char[] dec = new char[len];
        Arrays.fill(dec, '?');
        int ind = 0;
        for (int i = 0; i < width; i++, rem = Math.max(rem - 1, 0)) {
            int tem = row + (rem > 0 ? 1 : 0);
            for (int j = 0; j < tem; j++) {
                dec[j * width + i] = name.charAt(ind++);
            }
        }
        return new String(dec);
    }

    public static void main(String[] args)throws Exception {
        String name = "abir is trying hard, HE BELIEVES IN ONE AND ONLY ALLAH";
        File f = new File("input.txt");
        Scanner sc = new Scanner(f);
        name = sc.nextLine();
        sc.close();
        int width = 4;
        String enc = transposeCipher(name, width);
        String enc2 = transposeCipher(enc, 2 * width);
        System.out.println(enc);
        System.out.println(enc2);
        String dec = decrypt(enc2, 2 * width);
        String dec2 = decrypt(dec, width);
        System.out.println(dec2);
    }
}
