public class ModPow {
    public int modPow(long a, long b, long c){
        if(b==1) return (int)a;
        long res = modPow(a, b/2, c);
        res = (res * res) % c;
        if(b%2 == 1) res = (res * a) % c;
        return (int)res;
    }
}
