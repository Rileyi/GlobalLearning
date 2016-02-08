#ifndef I_CLONEABLE_H_INCLUDED
#define I_CLONEABLE_H_INCLUDED

// cloneable objects
class I_Cloneable
{
	public:
		virtual ~I_Cloneable() = 0;
		virtual I_Cloneable* clone() const = 0;
};

inline I_Cloneable::~I_Cloneable()
{}

#endif // I_CLONEABLE_H_INCLUDED
