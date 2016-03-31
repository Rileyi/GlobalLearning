#include "Module.h"


Module::Module(const std::string& name, int reading, int writing,int maths, int fun) :
    m_name(name), m_reading(reading), m_writing(writing), m_maths(maths), m_fun(fun)
{}

Module::Module(int reading, int writing,int maths, int fun) :
    m_name(), m_reading(reading), m_writing(writing), m_maths(maths), m_fun(fun)
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


std::ostream& operator<<(std::ostream& flux, const Module & module)
{
    char s[5];
    size_t length = module.getName().copy(s,3,0);
    s[length]='\0';
    flux << s << module.getName().length()%10;
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
