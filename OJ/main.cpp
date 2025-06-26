#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cassert>
#if 1

#ifdef DEBUG
#include <sstream>
#include <windows.h>
int g_debug = 1;
class LogStream
{
    std::ostringstream oss;
    HANDLE hConsole;

public:
    LogStream()
    {
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    }

    ~LogStream()
    {
        std::string output = oss.str();
        std::cout << output;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    template <typename T>
    LogStream &operator<<(const T &val)
    {
        if (g_debug == 1)
            oss << val;
        return *this;
    }

    LogStream &operator<<(std::ostream &(*manip)(std::ostream &))
    {
        if (g_debug == 1)
            manip(oss);
        return *this;
    }
};
#define log LogStream()
#else
int g_debug = 0;
class NullLogStream
{
public:
    template <typename T>
    NullLogStream &operator<<(const T &) { return *this; }
    NullLogStream &operator<<(std::ostream &(*)(std::ostream &)) { return *this; }
};
#define log    \
    if (false) \
    NullLogStream()
#endif

using namespace std;

#define vi(x) std::vector<int>(x)

#define mod %
typedef long long ll;
typedef pair<int, int> pint;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef unordered_map<int, vector<int>> graph;

#define _for(i, b) for (int i = 0; i < (b); ++i)
#define _forr(i, a, b) for (int i = (a); i < (b); ++i)
#define _p(a, b) make_pair(a, b)
const int inf = 1e9;
#define _vi(_name, _n) \
    vi _name(_n);      \
    _for(_i, _n) cin >> _name[_i];
#endif
