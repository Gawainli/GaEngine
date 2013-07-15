#ifndef GaContainer_h__
#define GaContainer_h__

#include "CommonMath.h"

#define TABLE_SIZE 65537

template <typename T>
class GaHashObj
{
public:
	GaHashObj()
	{
		hash = 0;
		check = 0;
	}
public:
	T value;
	unsigned int hash;
	unsigned int check;
protected:
private:
};

template <typename T>
class GaHashTable
{
public:
	GaHashTable(){}
	~GaHashTable(){}

public:
	int Insert( const std::string& strkey, T& value )
	{
		unsigned int hash = CommonMath::BKDRHash( strkey );
		unsigned int idx = hash % TABLE_SIZE;

		while ( elements[idx].hash != 0 )
		{
			idx++;
		}
		elements[idx].hash = hash;
		elements[idx].check = CommonMath::APHash( strkey );
		elements[idx] = value;
		return idx;
	}

	int GetIdx( const std::string& strkey ) const
	{
		unsigned int hash = CommonMath::BKDRHash( strkey );
		unsigned int check = CommonMath::APHash( strkey );
		unsigned int idx = hash % TABLE_SIZE;

		while ( elements[idx].check != check )
		{
			idx++;
			if ( elements[idx].hash == 0 )
			{
				return -1;
			}
		}

		return idx;
	}

	T& operator [] ( unsigned int idx ) const
	{
		return elements[idx].value;
	}
public:

private:
	GaHashTable<T> elements[TABLE_SIZE];
};



#endif // GaContainer_h__
