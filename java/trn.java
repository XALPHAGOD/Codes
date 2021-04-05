import java.util.*;

class A{
    public int var1,var2;
    public A(int val){
        this.var1=val;
    }
    public int m1(){
        System.out.println("A m1");
        return this.var2;
    }
}

class B extends A{
    public B(){
        super(10);
    }
    public int m1(int v1){
        System.out.println("B m1");
        return this.var1;
    }
}
class C extends B{
    public C(int v1,int v2){
        super();
        this.var2=v2;
    }
    public void m1(int v1,int v2){
        System.out.println("C m1");
        this.var2=super.m1(v1);
    }
}
class trn {
    public static void main(String[] args){
        C o=new C(5,20);
        System.out.println(o.m1());
    }
}
