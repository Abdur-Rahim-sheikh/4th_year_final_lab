public class Demo {
    public static void main(String[] args) {
        String pad = "1234567890";
        OneTimePad otp = new OneTimePad(pad);
        String enc = otp.encrypt("Hello World!");
        System.out.println(enc);
        String dec = otp.decrypt(enc);
        System.out.println(dec);
    }
}
