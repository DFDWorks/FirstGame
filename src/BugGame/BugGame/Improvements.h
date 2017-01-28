////////////////////////////////////
// Improvements for all code
//
// Author: Fomin Eugene
//
// 27.01.17
////////////////////////////////////

#ifndef _Improvements_h_
#define _Improvements_h_


////////////////////////////////////
// Includes
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <memory>
#include <vector>

////////////////////////////////////
// Typedefs

typedef std::string STR; // String
typedef short S16; // short signed int 16 bit
typedef	unsigned short U16; // short unsigned int 16 bit
typedef int S32; // signed int 32 bit
typedef unsigned int U32; // unsigned int 32 bit
typedef	char C8; // char 8 bit
typedef float F32; // float 32  bit
typedef	double D64; // double 64 bit


////////////////////////////////////
// Macroses
// You need to write objects of classes everywhere like: class Hero { ... }; ... Ptr(Hero); HeroPtr x; => class will delete himself if that need!
#define PTR( cls )			typedef std::shared_ptr< class cls > cls##Ptr; \
							typedef std::shared_ptr< const class cls > cls##ConstPtr; \
							typedef std::weak_ptr< class cls > cls##WPtr; \
							typedef std::weak_ptr< const class cls > cls##ConstWPtr;
// Just printf but in short word
#define Log( str, var ) printf( str, var );
#define Log( str ) std::cout <<str;


// To create objects
#define CREATE( cls, init ) std::shared_ptr< cls > _object( new cls() ); \
							if( !_object->init )     \
								return std::shared_ptr< cls >(NULL);   \
								return _object;

// Override to debug
#define OVERRIDE override;

////////////////////////////////////
// Everything should be in namespace. Write all code in our namespace Bug:

namespace Bug
{
	// here i will show you how to use some things in C++

	PTR( Improvements );

	class Improvements
	{

	public:

		////////////////////////////////////
		Improvements(); // Constructor. Look in cpp file how to write it.
		~Improvements(){}

		////////////////////////////////////
		void setName( const STR& name );      //Thats setter. Argument should to be with & to work with part of memory of object.

		////////////////////////////////////
		inline STR getName() const { return m_name; } // Getter should to be inline and const.

		////////////////////////////////////
		void update( F32 dt );

		////////////////////////////////////
		static ImprovementsPtr Create();

	private:

		////////////////////////////////////
		bool init();

	protected:

		S16 m_variable; // this how to write members of class - "m_"
		STR m_name;

		std::vector< S16 > m_array; // That is an array. Do not write int x[100] or int* x;
	};
	
	

}
#endif
////////////////////////////////////