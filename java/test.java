import java.util.*;

class Base{
        static int x=101;
        public Base(){
                System.out.println("In Base ");
        }
        private int fun(){
                System.out.println("In Base fun "+x);
                return 0;
        }
        public int run(){
                System.out.println("In Base run "+x);
                return 3;
        }
}

class Derived extends Base{
        final int x=102;
        public Derived(){
                System.out.println("In Derived ");
        }
        private int fun(){
                System.out.println("In Derived fun "+x);
                return 1;
        }
        public int run(){
                System.out.println("In Derived run "+x);
                return fun();
        }
}

class Derived1 extends Derived{
        static int x=103;
        public Derived1(){
                System.out.println("In Derived1 ");
        }
        public int fun(){
                System.out.println("In Derived1 fun "+x);
                return 2;
        }
}

public class test {
        public static void main(String[] args){
                Base ref=new Derived1();
                System.out.println(ref.run());
        }
}
