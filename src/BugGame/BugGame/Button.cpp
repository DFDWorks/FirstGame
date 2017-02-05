////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "Improvements.h"
#include "Button.h"
using namespace sf;
////////////////////////////////////
Button::Button()
{

	

}

////////////////////////////////////
ButtonPtr Button::Create()
{
	CREATE( Button, init() );
}

////////////////////////////////////
bool Button::init()
{
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile( "NetFish.jpg" );
	m_sprite->setTexture( *tex );
	m_sprite->setPosition( 0, 0 );
	m_sprite->setScale( 0.5f, 0.5f );
	m_sprite->setTextureRect( sf::IntRect( 0, 0, 300, 70 ) );
	m_mouse = new sf::Mouse();
	
	
	//if( sf::Mouse::Left )
	
	return true;
}

////////////////////////////////////
void Button::update(F32 dt)
{
	GameObject::update(dt);
	m_game->setOffSets(this);
	
	
}

////////////////////////////////////
void Button::render(sf::RenderWindow* rw)
{
	
	GameObject::render(rw);
}
