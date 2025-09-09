#include<bits/stdc++.h>
using namespace std;
void check(string type1,string op,string type2)
{

    if(type1!=type2)
    {
        cout<<"syntex error:"<<type1<<op<<type2<<endl;

    }
    else
    {

        cout<<"syntex correct:"<<type1<<op<<type2<<endl;
    }
}
int main()
{

    check("int","+","int");
    check("float","+","int");
    check("int","+","int");

}
