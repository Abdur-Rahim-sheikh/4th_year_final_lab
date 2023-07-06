public class MillerRabin {
    int iterate;
    ModPow modPow;
    public MillerRabin(int iterate){
        this.iterate = iterate;
        modPow = new ModPow();
    }
    public boolean isPrime(int n){
        int d = n - 1;
        while(d % 2 == 0) d /= 2;
        
        for(int i = 0; i < iterate; i++){
            int a = (int)(Math.random() * (n - 3)) + 2;
            int ans = modPow.modPow(a, d, n);
            if(ans == 1 || ans == n - 1){
                continue;
            }
            while(d!=n-1){
                ans = (ans * ans) % n;
                d *= 2;
                if(ans == 1) return false;
                if(ans == n - 1) break;
            }
            if(d==n-1) return false;
        }
        return true;
    }
}
