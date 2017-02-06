////////////////////////////////////
// Cockroach
//
// Author: DD
//
// 05.02.17
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
	m_sprite->setOrigin(0,0);
	m_sprite->setTextureRect( sf::IntRect( WINDOW_X/2, WINDOW_Y/2, 300, 70 ) );
	m_mouse = new sf::Mouse();
    m_posOfPixels =  sf::Vector2i();	
	
	//if( sf::Mouse::Left )
	
	return true;
}

////////////////////////////////////
void Button::update(F32 dt)
{
	GameObject::update(dt);
	m_game->setOffSets(this);
	m_posOfPixels = sf::Mouse::getPosition(*m_gameWindow);
	
	
}

////////////////////////////////////
void Button::render(sf::RenderWindow* rw)
{
	
	GameObject::render(rw);
}
