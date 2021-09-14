
#include <bits/stdc++.h>
using namespace std;

/*class student
{
    public:
    string name;
    int m1,m2,m3,m4,m5,m6;

    int total()
    {
        cout<<("Total marks : ",m1+m2+m3+m4+m5+m6);
        double percentage=(m1+m2+m3+m4+m5+m6)/3;    (x/(50*6)    *100)
        cout<<("Percentage : ",percentage,"%");
    }
};*/
int main(int argc, char *argv[])
{
    string name = argv[1];
    try
    {
        int tot = 0;
        for (int i = 2; i < 8; i++)
        {
            int num = stoi(argv[i]);
            if (num < 0 || num > 50)
                throw std::out_of_range("blah");
            tot += num;
        }
        cout << "Total= " << tot << " Percentage= " << (tot * 100.0) / 600;
    }
    catch (exception e)
    {
        cout << "Range Exception \n";
    }
    return 0;
}
