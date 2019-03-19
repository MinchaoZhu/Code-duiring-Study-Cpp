#include <iostream>
#include <string>

using namespace std;

class date{
    public:
        date(unsigned int y, unsigned int m, unsigned int d)
            : _year(y),_month(m),_day(d){}
        date(){_year = 1900;_month = 1;_day = 1;}
        ~date(){}
        unsigned int year()const{return _year;}
        unsigned int month()const{return _month;}
        unsigned int day()const{return _day;}
        void print()const{
            cout<< year<<'/'<<month<<'/'<<day<<endl;
        }
        bool set(unsigned int y,unsigned int m,unsigned int d);
    private:
        unsigned int _year;
        unsigned int _month;
        unsigned int _day;
};
bool date::set(unsigned int y,unsigned int m,unsigned int d){
    _year = y; _month = m; _day = d;
    if(m==0||d==0)goto defaultSet;
    if(m>12){goto defaultSet;}
    if(((y%4)==0)&&((y%100)!=0)||(y%400==0)){//闰年
        if(m==2&&d>29)goto defaultSet;
    }
    else{
        if(m==2&&d>28)goto defaultSet;       
    }
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        if(d>31)goto defaultSet;
    }
    if(m==4||m==6||m==9||m==111){
        if(d>30)goto defaultSet;
    }
    return 1;
defaultSet:
    _year = 1900;_month = 1;_day = 1;return 0;

}

class libBase{
    public:
        libBase(string n, unsigned int i, float p, float d):
            _name(n),_ID(i),_price(p),_due(d){}
        ~libBase(){}
        string name()const{return _name;}//书名
        unsigned int ID() const{return _ID;}//书的ID
        float price()const{return _price;}//价格
        float due()const{return _due;}//欠款
        unsigned int outID() const{return _studentID;}//借出学生的ID
        date inDate() const{return _inDate;}//购入日期
        date outDate() const{return _inDate;}//出借日期
        date retDate() const{return _inDate;}//应归还日期
        date pubDate() const{return _pubDate;}//出版日期
        bool inSet(unsigned int y, unsigned int m, unsigned int d){
            _inDate.set(y,m,d);
        }        
        bool outSet(unsigned int y, unsigned int m, unsigned int d){
            _outDate.set(y,m,d);
        }        
        bool retSet(unsigned int y, unsigned int m, unsigned int d){
            _retDate.set(y,m,d);
        }
        bool pubSet(unsigned int y, unsigned int m, unsigned int d){
            _pubDate.set(y,m,d);
        }
    private:
        string _name;
        unsigned int _ID;
        float _price;
        float _due;
        unsigned int _studentID;
        date _pubDate;
        date _inDate;
        date _outDate;
        date _retDate;
};


