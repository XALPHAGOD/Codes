import java.util.*;
class X{
    int v;
    public X(int x)
    {
        v=x;
    }
    void disp(){
        int v=20;
        System.out.println(v);
    }
}
class temp
{
    public static void main(String args[])
    {   
        X a=new X(10);
        System.out.println(a.v);
        a.disp();
    }
}