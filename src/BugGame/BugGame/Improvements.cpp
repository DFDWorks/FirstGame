////////////////////////////////////
// Improvements for all code
//
// Author: Fomin Eugene
//
// 27.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "Improvements.h"

namespace Bug
{

	////////////////////////////////////
	Improvements::Improvements()
		: m_variable( 0 ) // this how to initialize variables (if that need you)
		, m_name( "empty" )
	{
	}

	////////////////////////////////////
	bool Improvements::init()
	{
		Log( "Hello!!!" );

		m_array.push_back( 125 ); // put elements in vector like in stack
		m_array.resize( 200 ); // or give him size and wor like with standart array
		m_array[12] = 100;

		return true;
	}

	////////////////////////////////////
	void Improvements::update( F32 dt )
	{
		//Game::update( dt ); <- that what to write in update
	}

	////////////////////////////////////
	ImprovementsPtr Improvements::Create()
	{
		CREATE( Improvements, init() );
	}

	////////////////////////////////////
	void Improvements::setName( const STR& name )
	{
		m_name = name;
	}


}