import java.math.BigInteger;
import java.util.Random;

class RSA_NUM{
    BigInteger n,e,d,phi,p,q;
    public RSA_NUM(int bitlen){
        p =  BigInteger.probablePrime(bitlen,new Random());
        q =  BigInteger.probablePrime(bitlen, new Random());
        build();
    }
    void build(){
        n = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = new BigInteger("309");
        while(!phi.gcd(e).equals(BigInteger.ONE)){
            e = e.add(BigInteger.ONE);
        }
     
        BigInteger k = new BigInteger("2");
        while(true){
            BigInteger tem = phi.multiply(k).add(BigInteger.ONE);
            d = tem.divide(e);
            if(d.multiply(e).equals(tem)) break;
            k = k.add(BigInteger.ONE);
        }
    }

    BigInteger encryptEasy(String msg){
        BigInteger num = new BigInteger(msg);
        return num.modPow(e, n);
    }

    BigInteger decryptEasy(BigInteger num){
        return num.modPow(d,n);
    }

}