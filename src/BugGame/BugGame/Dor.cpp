////////////////////////////////////
// Dor
//
// Author: Eugene Fomin
//
// 29.01.17				
////////////////////////////////////

////////////////////////////////////
// Includes
#include "Dor.h"

////////////////////////////////////
Dor::Dor()
{
}

////////////////////////////////////
Dor::~Dor()
{
}

////////////////////////////////////
DorPtr Dor::Create()
{
	CREATE( Dor, init() );
}

////////////////////////////////////
bool Dor::init()
{
	GameObject::init();

	m_width = 100;
	m_height = 100;
	m_wCenter = 1;
	m_hCenter = 1;
	sf::Texture* tex = new sf::Texture();
	tex->loadFromFile( "bug.png" );
	m_sprite->setTexture( *tex );
	m_sprite->setOrigin( getWCenter() * TILE_SIZE, getHCenter() * TILE_SIZE );
	m_sprite->setPosition( 1 * TILE_SIZE, 1 * TILE_SIZE );
	
	return true;
}

////////////////////////////////////
void Dor::update( F32 dt )
{
	//m_game->setOffSets( shared_from_this() );
	
	GameObject::update( dt );
}

////////////////////////////////////
void Dor::render( sf::RenderWindow* rw )
{
	sf::IntRect texRect;
	texRect = kDorImage;
	rw->draw( *m_sprite );
	setTextureRect( texRect );
	GameObject::render( rw );
}
