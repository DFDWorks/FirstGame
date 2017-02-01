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
	
	m_label = Label::Create( "Level \"Asshole\" " );
	m_label->setPosition(20,100);
	sf::Texture* hud = new sf::Texture();
	hud->loadFromFile( "Hud.png" );
	m_sprite->setTexture( *hud );
	m_sprite->setPosition( 0, 0 );
	m_sprite->setScale( 0.5f, 0.5f );
	m_sprite->setTextureRect( sf::IntRect( 0, 0, 335, 160 ) );

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
	rw->draw(*m_label->operator sf::Text *());
	rw->draw( *m_sprite );
	

}
