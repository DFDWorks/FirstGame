////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "GO_Cockroach.h"
#include "Improvements.h"
#include "GameHUD.h"

////////////////////////////////////
GameHUD::GameHUD()
{
	//m_width = kCockroachColumns;
	//m_height = kCockroachRows;
	//m_wCenter = kCockroachColumns / 2;
	//m_hCenter = kCockroachRows / 2;
	//
	//m_directionFormally = 0;
	//m_directionReal = 0;
	//m_rotationSpeed = kCockroachRotSpeed;
}

////////////////////////////////////
GameHUDPtr GameHUD::Create()
{
	CREATE(GameHUD, init());
}

////////////////////////////////////
bool GameHUD::init()
{
	Log( "Loading GameHUD...\n" );
	
	m_label = Label::Create( "Hello" );
	
	return true;
}

////////////////////////////////////
void GameHUD::update( F32 dt )
{
	GameObject::update(dt);
	m_game->setOffSets(this);
}

////////////////////////////////////
void GameHUD::render(sf::RenderWindow* rw)
{
	GameObject::render(rw);
	
	rw->draw(*m_label->getText());

}
