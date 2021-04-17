import java.util.*;

class Bse{
    int x=101;
    public Bse(){
        System.out.println("Bse");
    }
    public void pr(){
        System.out.println("Bse");
    }
}
class Der extends Bse{
    int x=102;
    public Der(){
        System.out.println("Der");
    }
    public void pr(){
        System.out.println("Der");
    }
    public void pr2(){
        System.out.println("Der2");
    }
} 
class xyz {
    static public void main(String[] args){
        Bse b=new Bse();
        System.out.println();

        Der d=new Der();
        System.out.println();
        
        Bse o=new Der();
        System.out.println();
        
        Der e=new Der();
        System.out.println();

        Bse r=e;
        
        System.out.println(b.x+" "+d.x+" "+o.x+" "+r.x);
        // b.pr();
        d.pr();
        o.pr();
        r.pr();

        d.pr2();
        // o.pr2();
        // r.pr2();

        // r=b;
        // System.out.println(r.x);
        // r.pr();
    }
}
