#include "Module.h"


Module::Module(const std::string& name, int reading, int writing,int maths, int fun) :
    m_name(name), m_learnings(Matter::Size, 0)
{
    m_learnings[Matter::Reading] = reading;
    m_learnings[Matter::Writing] = writing;
    m_learnings[Matter::Maths] = maths;
    m_learnings[Matter::Fun] = fun;
}

Module::Module(const std::string& name, const std::vector<int>& learnings) :
    m_name(name), m_learnings(learnings)
{}

Module::Module(const std::string& name) :
    m_name(name), m_learnings(Matter::Size, 0)
{}

Module::Module(int reading, int writing,int maths, int fun) :
    m_name(), m_learnings(Matter::Size, 0)
{
    m_learnings[Matter::Reading] = reading;
    m_learnings[Matter::Writing] = writing;
    m_learnings[Matter::Maths] = maths;
    m_learnings[Matter::Fun] = fun;
}

Module::Module(const std::vector<int>& learnings) :
    m_name(), m_learnings(learnings)
{}

Module::Module(int x) :
    m_name(), m_learnings(Matter::Size, 0)
{
    m_learnings[Matter::Reading] = x;
    m_learnings[Matter::Writing] = x;
    m_learnings[Matter::Maths] = x;
    m_learnings[Matter::Fun] = x;
}

Module::Module() :
    m_name(), m_learnings(Matter::Size, 0)
{}

Module::Module(const Module & other) :
    m_name(other.m_name), m_learnings(other.m_learnings)
{}


Module::~Module() {}

const std::string& Module::getModuleName() const
{
    return m_name;
}

void Module::setModuleName(const std::string name)
{
    m_name = name;
}

const std::vector<int>& Module::getlearnings() const
{
    return m_learnings;
}


Matter Module::mainMatter() const
{
    int value = 0;
    Matter matter = Matter::Fun;
    for (int i=0; i<Matter::Size; ++i)
    {
        if (m_learnings[i] > value)
        {
            matter = Matter(i);
            value = m_learnings[i];
        }
    }

    return matter;
}

int Module::totalValue() const
{
    int total = 0;
    for(int i=0; i<Matter::Size; ++i)
    {
        total += m_learnings[i];
    }
    return total;
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
    os << m_name << ": ";
    os << "reading(" << (*this)[Matter::Reading] << ") ";
    os << "writing(" << m_learnings[Matter::Writing] << ") ";
    os << "maths(" << m_learnings[Matter::Maths] << ") ";
    os << "fun(" << m_learnings[Matter::Fun] << ") ";
    return os.str();
}

Module& Module:: operator=(const Module& other)
{
    m_learnings = other.m_learnings;
    return *this;
}

Module& Module::operator+=(const Module& other)
{
    for(int i=0; i<Matter::Size; ++i)
    {
        m_learnings[i] += other.m_learnings[i];
    }
    return *this;
}

Module& Module::operator-=(const Module& other)
{
    for(int i=0; i<Matter::Size; ++i)
    {
        m_learnings[i] -= other.m_learnings[i];
    }
    return *this;
}

Module& Module::operator*=(const int& x)
{
    for(int i=0; i<Matter::Size; ++i)
    {
        m_learnings[i] *= x;
    }
    return *this;
}

Module& Module::operator/=(const int& x)
{
    for(int i=0; i<Matter::Size; ++i)
    {
        m_learnings[i] /= x;
    }
    return *this;
}

Module Module::operator+(const Module& other) const
{
    Module m = *this;
    m += other;
    return m;
}

Module Module::operator-(const Module& other) const
{
    Module m = *this;
    m -= other;
    return m;
}

Module Module::operator-() const
{
    Module m = *this;
    m *= -1;
    return m;
}

Module Module::operator*(const int& x) const
{
    Module m = *this;
    m *= x;
    return m;
}

Module Module::operator/(const int& x) const
{
    Module m = *this;
    m /= x;
    return m;
}

int& Module::operator[](const Matter& matter)
{
    return m_learnings[matter];
}

int Module::operator[](const Matter& matter) const
{
    return m_learnings[matter];
}

int& Module::operator[](const int& matter)
{
    return m_learnings[matter];
}

int Module::operator[](const int& matter) const
{
    return m_learnings[matter];
}

bool Module::operator==(const Module& other) const
{
    for(int i=0; i<Matter::Size; ++i)
    {
        if (m_learnings[i] != other.m_learnings[i]) return false;
    }

    return true;
}

Module max(const Module& m1, const Module& m2)
{
    Module m;
    for(int i=0; i<Matter::Size; ++i)
    {
        m.m_learnings[i] = std::max(m1.m_learnings[i], m2.m_learnings[i]);
    }
    return m;
}

Module min(const Module& m1, const Module& m2)
{
    Module m;
    for(int i=0; i<Matter::Size; ++i)
    {
        m.m_learnings[i] = std::min(m1.m_learnings[i], m2.m_learnings[i]);
    }
    return m;
}

std::ostream& operator<<(std::ostream& flux, const Module & module)
{
    flux << module.m_name.substr(0, 3) << module.m_name.length()%10;
    return flux;
}

int calculateScore(const Module& current, const Module& concurrent, const Module& diff)
{
    int score = 0;
    for(int i=0; i<Matter::Size; ++i)
    {
        int modif = concurrent[i] - current[i];
        score += (diff[i]>0 ? (modif >= 0 ||  diff[i] >= -modif  ?  -modif  :   modif + 2*diff[i])
                            : (modif <= 0 || -diff[i] >=  modif  ?   modif  :  -modif - 2*diff[i]));
    }
    return score;
}

