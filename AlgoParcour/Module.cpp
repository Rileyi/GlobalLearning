#include "Module.h"


Module::Module(const std::string& name, int reading, int writing,int maths, int fun) :
    m_name(name), m_reading(reading), m_writing(writing), m_maths(maths), m_fun(fun)
{}

Module::Module(const std::string& name) :
    m_name(name), m_reading(0), m_writing(0), m_maths(0), m_fun(0)
{}

Module::Module(int reading, int writing,int maths, int fun) :
    m_name(), m_reading(reading), m_writing(writing), m_maths(maths), m_fun(fun)
{}

Module::Module() :
    m_name(), m_reading(0), m_writing(0), m_maths(0), m_fun(0)
{}

Module::Module(int x) :
    m_name(), m_reading(x), m_writing(x), m_maths(x), m_fun(x)
{}

Module::Module(const Module & other) :
    m_name(other.m_name), m_reading(other.m_reading), m_writing(other.m_writing),
    m_maths(other.m_maths), m_fun(other.m_fun)
{}


Module::~Module() {}

const std::string& Module::getName() const
{
    return m_name;
}

int Module::getReading() const
{
    return m_reading;
}

int Module::getWriting() const
{
    return m_writing;
}

int Module::getMaths() const
{
    return m_maths;
}

int Module::getFun() const
{
    return m_fun;
}

int Module::totalValue() const
{
    return m_reading + m_writing + m_maths + m_fun;
}

Module* Module::inferiorLevel() const
{
    Module* r = new Module(m_name + "*");
    *r = *this / 2;
    return r;
}

std::string Module::toString() const
{
    std::stringstream os;
    os << m_name << ": " << m_reading << " " << m_writing << " " << m_maths << " " << m_fun;
    return os.str();
}

Module& Module:: operator=(const Module& other)
{
    if (m_name.empty()) m_name = std::string(other.m_name);
    m_reading = other.m_reading;
    m_writing = other.m_writing;
    m_maths = other.m_maths;
    m_fun = other.m_fun;
    return *this;
}

Module& Module::operator+=(const Module& other)
{
    m_reading += other.m_reading;
    m_writing += other.m_writing;
    m_maths += other.m_maths;
    m_fun += other.m_fun;
    return *this;
}

Module Module::operator+(const Module& other) const
{
    return Module(m_reading + other.m_reading, m_writing + other.m_writing,
                  m_maths + other.m_maths, m_fun + other.m_fun);
}

Module Module::operator-(const Module& other) const
{
    return Module(m_reading - other.m_reading, m_writing - other.m_writing,
                  m_maths - other.m_maths, m_fun - other.m_fun);
}

Module Module::operator-() const
{
    return Module(-m_reading, -m_writing, -m_maths, -m_fun);
}

Module Module::operator*(const int& x) const
{
    return Module(m_reading * x, m_writing * x, m_maths * x, m_fun * x);
}

Module Module::operator/(const int& x) const
{
    return Module(m_reading / x, m_writing / x, m_maths / x, m_fun / x);
}

bool Module::operator==(const Module& other) const
{
    return m_reading == other.m_reading  &&  m_writing == other.m_writing  &&
           m_maths == other.m_maths  &&  m_fun == other.m_fun;
}

Module max(const Module& m1, const Module& m2)
{
    return Module(std::max(m1.m_reading, m2.m_reading), std::max(m1.m_writing, m2.m_writing),
                  std::max(m1.m_maths, m2.m_maths), std::max(m1.m_fun, m2.m_fun));
}

Module min(const Module& m1, const Module& m2)
{
    return Module(std::min(m1.m_reading, m2.m_reading), std::min(m1.m_writing, m2.m_writing),
                  std::min(m1.m_maths, m2.m_maths), std::min(m1.m_fun, m2.m_fun));
}

std::ostream& operator<<(std::ostream& flux, const Module & module)
{
    flux << module.m_name.substr(0, 3) << module.m_name.length()%10;
    return flux;
}

std::ostream& operator<<(std::ostream& flux, const Module* & module)
{
    if (module == nullptr)
    {
        flux << "####";
    }
    else
    {
        flux << *module;
    }
    return flux;
}


int calculateScore(const Module& current, const Module& concurrent, const Module& diff)
{
    return  calculateScore(current.m_reading, concurrent.m_reading, diff.m_reading) +
            calculateScore(current.m_writing, concurrent.m_writing, diff.m_writing) +
            calculateScore(current.m_maths, concurrent.m_maths, diff.m_maths) +
            calculateScore(current.m_fun, concurrent.m_fun, diff.m_fun);
}


int calculateScore(int current, int concurrent, int diff)
{
    int modif = concurrent - current;
    return (diff>0 ? (modif >= 0 ||  diff >= -modif  ?  -modif  :   modif + 2*diff)
                   : (modif <= 0 || -diff >=  modif  ?   modif  :  -modif - 2*diff));
}
