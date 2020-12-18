#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
class student
{
public:
    string first_name;
    string second_name;
    string roll_no;
    student(string f,string s,string roll_no)
    {
        first_name=f;
        second_name=s;
        this->roll_no=roll_no;
    }
    bool operator==(const student &s) const
    {
        return roll_no==s.roll_no;
    }
};
class hashfunction
{
public:
    size_t operator()(const student &t) const
    {
        return t.first_name.length()+t.second_name.length();
    }
};
int main()
{ 
    unordered_map<student,int,hashfunction> m;
    student s1("Prateek","Narang","65");
    student s2("Tejas","Dongare","98");
    student s3("shubham","Donagre","99");
    student s4("shreyash","Donagre","120");
    student s5("Tau","Donagre","130");
    m[s1]=120;
    m[s2]=70;
    m[s3]=120;
    m[s4]=99;
    m[s5]=1;
    for(auto s:m)
    {
        cout<<s.first.first_name<<" "<<s.first.second_name<<" "<<s.first.roll_no<<" "<<s.second<<endl;
    }
}