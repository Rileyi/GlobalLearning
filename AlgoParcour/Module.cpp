//#include "stdafx.h"
#include "Module.h"

using namespace std;


Module::Module(const string& name, int reading, int writing,int maths, int fun) :
    m_name(name), m_reading(reading), m_writing(writing), m_maths(maths), m_fun(fun)
{}

Module::Module(const Module & other) :
    m_name(other.m_name), m_reading(other.m_reading), m_writing(other.m_writing),
    m_maths(other.m_maths), m_fun(other.m_fun)
{}


Module::~Module() {}

const string& Module::getName() const
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

string Module::toString() const
{
    stringstream os;
    os << m_name << ": " << m_reading << " " << m_writing << " " << m_maths << " " << m_fun;
    return os.str();
}

Module& Module:: operator=(const Module& other)
{
    m_name = string(other.m_name);
    m_reading = other.m_reading;
    m_writing = other.m_writing;
    m_maths = other.m_maths;
    m_fun = other.m_fun;
    return *this;
}

ostream& operator<<(ostream& flux, const Module & module)
{
    char s[5];
    size_t length = module.getName().copy(s,3,0);
    s[length]='\0';
    flux << s << module.getName().length()%10;
    return flux;
}

ostream& operator<<(ostream& flux, const Module* & module)
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
