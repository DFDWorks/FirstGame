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
		: m_variable(0) // this how to initialize variables (if that need you)
		, m_name( "empty" )
	{
	}

	////////////////////////////////////
	bool Improvements::init()
	{
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
		CREATE(Improvements, init());
	}

	////////////////////////////////////
	void Improvements::setName(const STR& name)
	{
		m_name = name;
	}

	//////////////////////////////////////
	//SettingsMiniGamePtr SettingsMiniGame::Create()
	//{
	//	BFG_CREATE_AND_INIT_SHARED_PTR(SettingsMiniGame, init());
	//}
	//
	//////////////////////////////////////
	//SettingsMiniGamePtr SettingsMiniGame::Create(const SettingsMiniGamePtr& obj)
	//{
	//	BFG_CREATE_AND_INIT_SHARED_PTR(SettingsMiniGame, init(obj));
	//}


}