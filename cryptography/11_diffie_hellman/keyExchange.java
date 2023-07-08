class keyExchange{
    public static int power(int m,int n,int p){
        if(n==0) return 1;
        int ans = power(m,n/2,p);
        ans = (ans*ans)%p;
        if(n%2==1)ans = (ans*m)%p;
        return ans;
    }
    public static void main(String[] args) {
        System.out.println("Mursalin");
        int primitive_root = 2,prime = 13;
        int xa,xb,ya,yb;
        xa = 25070;
        xb = 302;
        ya = power(primitive_root,xa,prime);
        yb = power(primitive_root,xb,prime);

        int key1 = power(ya,xb,prime);
        int key2 = power(yb,xa,prime);
        System.out.println(key1+" "+key2);
    }
}
