// Purpose: Test the Lehman Primality Test
class LehmanPrimalityTest{
    int itrate;
    ModPow modPow;
    public LehmanPrimalityTest(int itrate){
        this.itrate = itrate;
        modPow = new ModPow();
    }
    public boolean isPrime(int n){
        if(n == 2 || n == 3){
            return true;
        }
        if(n % 2 == 0 || n % 3 == 0){
            return false;
        }
        for(int i = 0; i < itrate; i++){
            int a = (int)(Math.random() * (n - 3)) + 2;
            int ans = modPow.modPow(a, (n - 1)/2, n);
            if(ans != 1 && ans != n - 1){
                System.out.println("lehman: "+n+" iterate: "+i+" ans: "+ans);
                return false;
            }
        }
        return true;
    }
}