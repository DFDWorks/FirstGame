////////////////////////////////////
// Cockroach
//
// Author: TRiOLD
//
// 29.01.17				upd 06.02.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "GO_Cockroach.h"

////////////////////////////////////
Cockroach::Cockroach()
{
}

////////////////////////////////////
CockroachPtr Cockroach::Create()
{
	CREATE( Cockroach, init() );
}

////////////////////////////////////
bool Cockroach::init()
{
	GameObject::init();

	m_width = kCockroachColumns / 10;
	m_height = kCockroachRows / 10;
	m_wCenter = kCockroachColumns/2;
	m_hCenter = kCockroachRows / 2;
	m_sprite->setTexture( *TextureAtlas );
//	m_directionFormally = 0;
	m_directionReal = 0;
	m_rotationSpeed = kCockroachRotSpeed;
	m_sprite->setOrigin( getWCenter() * TILE_SIZE, getHCenter() * TILE_SIZE );
	m_sprite->setPosition( 9 * TILE_SIZE, 9 * TILE_SIZE );
	
	return true;
}

////////////////////////////////////
void Cockroach::update( F32 dt )
{
	m_game->setOffSets( shared_from_this() );
	setDirectionDegree( m_game->getAngleMouseToObject( shared_from_this() ) );
	if( rotation( dt ) )
	{
	}
	GameObject::update( dt );
}

////////////////////////////////////
void Cockroach::render( sf::RenderWindow* rw )
{
	//sf::IntRect texRect;
		
	//texRect = kCockroachImage;
	//m_sprite->setRotation( m_directionReal );
	//rw->draw( *m_sprite );
	//setTextureRect( texRect );
	GameObject::render( rw );
}
