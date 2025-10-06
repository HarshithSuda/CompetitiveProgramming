import java.math.*;
class Factorial{
    
}
class BigIntegerJava{
    public static BigInteger calculateFactorial(int n){
        BigInteger result= BigInteger.ONE;
        for(int i=1;i<=n;i++){
            result= result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
    public static void main(String[] args){
        BigInteger factorial= calculateFactorial(25);
        System.out.println("factorial : "+factorial);
    }
}
