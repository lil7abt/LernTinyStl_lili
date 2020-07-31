//Execercise 4.3
//By wrapping these global obj within a class, we encapsulate their direct access within a small set of functions.
//The names of the obj are now hidden behind the scope of the class and cannot clash with other global entities.

#include <string>
using std::string;

class globalWapprer
{
public:
    static int tests_passed() {return _tests_passed;}
    static int tests_run()    {return _tests_run;}
    static int version_num()  {return _version_number;}
    static string version_stamp() {return _version_stamp;}
    static string program_name()  {return _program_name;}

    
private:
    static string _program_name;
    static string _version_stamp;
    static int    _version_number;
    static int    _tests_run;
    static int    _tests_passed;
}