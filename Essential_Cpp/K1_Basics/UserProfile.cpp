#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class UserProfile
{
public:
    //定义枚举类型user_lvl，枚举元素作为常量，分别为0,1,2,3,4....
    enum user_lvl
        {
            Beginner,
            Intermediate,
            Advanced,
            Guru
        };
    //"有参无默认值"初始化，用于有名字和等级的客户
    UserProfile(string login, user_lvl=Beginner);
    //default constructor
    UserProfile();

    //Operator overload
    bool operator==(const UserProfile &);
    bool operator!=(const UserProfile &);
    //Get-Methods
    string get_login             () const {return _login;}
    string get_user_name         () const {return _user_name;}
    int    get_log_num           () const {return _log_num;}
    int    get_guess_num         () const {return _guess_num;}
    int    get_correct_guess_num () const {return _correct_guess_num;}
    string get_lvl               () const ;//TBD
    double get_average           () const ;//TBD
    //Set-Methods
    void   set_login             (const string &val) {_login = val;}
    void   set_user_name         (const string &val) {_user_name=val;}
    void   set_log_num           (int val)           {_log_num=val;}
    void   set_guess_num         (int val)           {_guess_num=val;}
    void   set_correct_guess_num (int val)           {_correct_guess_num=val;}
    void   set_lvl               (const string &val);//TBD
    void   set_lvl               (user_lvl val)      {_current_lvl=val;}
    void   inc_log_num           (int cnt = 1)       {_log_num+=cnt;}
    void   inc_guess_num         (int cnt = 1)       {_guess_num+=cnt;}
    void   inc__correct_guess_num(int cnt = 1)       {_correct_guess_num+=cnt;}

private:
    string   _login;
    string   _user_name;
    int      _log_num;
    int      _guess_num;
    int      _correct_guess_num;
    user_lvl _current_lvl;

    static map<string, user_lvl> _lvl_map;
    static void init_lvl_map();
    
};



//定义猜对百分比函数
inline double UserProfile::get_average() const
{
    return _guess_num ? double(_correct_guess_num) / double(_guess_num) * 100: 0.0;
}
//"有参无默认值"初始化，用于有名字和等级的客户
inline UserProfile::UserProfile(string login, user_lvl lvl)
: _login(login), _current_lvl(lvl), _log_num(1), _guess_num(0), _correct_guess_num(0)
{}
//默认构造函数初始化，用于默认的guest用户初始化
//guest的等级默认设定为Beginner

#include <cstdlib>
inline UserProfile::UserProfile()
: _login("guest"), _current_lvl(Beginner), _log_num(1), _guess_num(0), _correct_guess_num(0)
{
    static int id = 0;
    char buffer[16];
    _itoa_s(id++, buffer, 10);;//C语言中的函数，将整型值转换为字符串
    _login += buffer;
}

inline bool UserProfile::operator==(const UserProfile &rhs)
{
    if(_login == rhs._login && _user_name == rhs._user_name)
        return true;
    return false;
}

inline bool UserProfile::operator!=(const UserProfile &rhs)
{
    return !(*this==rhs); //operator== is already overloaded in the last function definition
}

//输出流重载
ostream& operator<<(ostream &os, const UserProfile &rhs)
{
    //输出格式：qing Beginner 12 100 10 10%
    os << rhs.get_login()             <<' '
       << rhs.get_lvl()               <<' '
       << rhs.get_log_num()           <<' '
       << rhs.get_guess_num()         <<' '
       << rhs.get_correct_guess_num() <<' '
       << rhs.get_average()           <<'%'
       << endl;
    return os;
}

//输入流重载
istream& operator>>(istream &is, UserProfile &rhs)
{
    string login, level;
    is >> login >> level;

    int lcount    = 0;
    int gcount    = 0;
    int gcorrect  = 0;

    rhs.set_login(login);
    rhs.set_lvl(level);
    rhs.set_log_num(lcount);
    rhs.set_guess_num(gcount);
    rhs.set_correct_guess_num(gcorrect);

    return is;
}

//静态static 数据成员初始化
map<string, UserProfile::user_lvl> UserProfile::_lvl_map;

void UserProfile::init_lvl_map() 
{
    map<string, user_lvl>::iterator it;
    if (_lvl_map.empty())
    {
        _lvl_map["Beginner"]     = Beginner;
        _lvl_map["Intermediate"] = Intermediate;
        _lvl_map["Advanced"]     = Advanced;
        _lvl_map["Guru"]         = Guru;
    }    
}

inline string UserProfile::get_lvl() const
{
    static string _level_table[] = {"Beginner", "Intermediate", "Advanced", "Guru"};
    return _level_table[_current_lvl];
}

inline void UserProfile::set_lvl(const string &val)
{
    map<string, user_lvl>::iterator it;
    if (_lvl_map.empty())
    {
        init_lvl_map();
    }
    //确保level的确代表一个可识别的用户等级
    // it->second is the second object of the returned pair from map
    _current_lvl = ((it=_lvl_map.find(val)) != _lvl_map.end()) ? it->second:Beginner;    
}

int main()
{
    UserProfile measure1;
    cout << measure1;

    UserProfile measure2;
    cout << measure2;

    UserProfile measure3("Qing", UserProfile::Advanced);
    cout << measure3;
    measure3.inc_log_num();
    measure3.inc_guess_num(28);
    measure3.inc__correct_guess_num(20);
    cout << measure3;

    UserProfile measure4;
    cin >>measure4;
    cout<<measure4;

    system("pause");
}