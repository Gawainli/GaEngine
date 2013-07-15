#ifndef CommonMath_h__
#define CommonMath_h__

#include "..\common.h"
#include "..\EngineDef.h"

class CommonMath
{
public:

	inline static unsigned int BKDRHash(const std::string& str)
	{
		unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
		unsigned int hash = 0;

		for(std::size_t i = 0; i < str.length(); i++)
		{
			hash = (hash * seed) + str[i];
		}

		return hash;
	}

	inline static unsigned int APHash(const std::string& str)
	{
		unsigned int hash = 0xAAAAAAAA;

		for(std::size_t i = 0; i < str.length(); i++)
		{
			hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ str[i] * (hash >> 3)) :
				(~((hash << 11) + (str[i] ^ (hash >> 5))));
		}

		return hash;
	}

protected:
private:
};

#endif // CommonMath_h__
