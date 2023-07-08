import java.math.BigInteger;
import java.util.Random;
public class RSA_MSG {
    BigInteger n,p,q,phi,e,d;
    BigInteger ONE(){
        return BigInteger.ONE;
    }
    public RSA_MSG(int bitlen){
        p = BigInteger.probablePrime(bitlen,new Random());
        q = BigInteger.probablePrime(bitlen,new Random());
        build();
    }
    void build(){
        n = p.multiply(q);
        phi = p.subtract(ONE()).multiply(q.subtract(ONE()));
        e = new BigInteger(13,new Random());
        while(!phi.gcd(e).equals(ONE()))
            e = e.add(ONE());
        
        BigInteger k = new BigInteger("2"),tem;
        while(true){
            tem = phi.multiply(k).add(ONE());
            d = tem.divide(e);
            if(d.multiply(e).equals(tem))break;
            k = k.add(ONE());
        }
    }

    BigInteger encrypt(String msg){
        byte[] data = msg.getBytes();
        BigInteger num = new BigInteger(data);
        return num.modPow(e,n);
    }

    BigInteger decrypt(BigInteger enc){
        return enc.modPow(d,n);
    }

}
