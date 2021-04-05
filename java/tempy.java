import java.util.*;


public class tempy {
    public static void m(){
        throw new ArrayIndexOutOfBoundsException();
    }
    public static void main(String[] args){
        try{
            m();
        }catch(ArrayIndexOutOfBoundsException e){

        }
    }
}
