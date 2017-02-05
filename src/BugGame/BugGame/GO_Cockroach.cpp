////////////////////////////////////
// Cockroach
//
// Author: TRiOLD
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "GO_Cockroach.h"
#include "Button.h"



////////////////////////////////////
Cockroach::Cockroach()
{
	m_width = kCockroachColumns / 10;
	m_height = kCockroachRows / 10;
	m_wCenter = kCockroachColumns/2;
	m_hCenter = kCockroachRows/2;
	m_sprite->setTexture(*TextureAtlas);
	m_directionFormally = 0;
	m_directionReal = 0;
	m_rotationSpeed = kCockroachRotSpeed;
	m_sprite->setOrigin(getWCenter() * TILE_SIZE, getHCenter() * TILE_SIZE);
	m_sprite->setPosition(9 * TILE_SIZE, 9 * TILE_SIZE);
	x = Button::Create();
}

////////////////////////////////////
void Cockroach::update(F32 dt)
{
	m_game->setOffSets(this);
	setDirectionDegree(m_game->getAngleMouseToObject(this));
	if(rotation(dt))
	{
	}
	GameObject::update(dt);
	//x->update( dt );
	if( x-> getMouseButton()->isButtonPressed(sf::Mouse::Left))
	{
		Log("Okay");
	}
	
}

////////////////////////////////////
void Cockroach::render(sf::RenderWindow* rw)
{
	sf::IntRect texRect;
	 
	rw->draw( *x->getSprite() );
	
	texRect = kCockroachImage;
	m_sprite->setRotation(m_directionReal);
	rw->draw(*m_sprite);
	setTextureRect(texRect);
	GameObject::render(rw);
	
}
