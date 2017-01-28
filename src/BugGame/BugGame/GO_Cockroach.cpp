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

////////////////////////////////////
Cockroach::Cockroach()
{
	m_width = kCockroachColumns;
	m_height = kCockroachRows;
	m_wCenter = kCockroachColumns/2;
	m_hCenter = kCockroachRows/2;

	m_directionFormally = 0;
	m_directionReal = 0;
	m_rotationSpeed = kCockroachRotSpeed;
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
}

////////////////////////////////////
void Cockroach::render(sf::RenderWindow* rw)
{
	sf::IntRect texRect;
	texRect = kCockroachImage;
	m_sprite->setRotation(m_directionReal);

	setTextureRect(texRect);
	GameObject::render(rw);
}
