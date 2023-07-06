public class Demo {
    public static void main(String[] args) {
        int n = 1000000007;
        System.out.println(n);
        int itrate = 20;
        LehmanPrimalityTest lpt = new LehmanPrimalityTest(itrate);
        MillerRabin mr = new MillerRabin(itrate);
        System.out.println("Lehman Primality Test:");
        System.out.println("Is " + n + " prime? " + lpt.isPrime(n));
        System.out.println("Miller Rabin Primality Test:");
        System.out.println("Is " + n + " prime? " + mr.isPrime(n));
    }
}
