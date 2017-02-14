////////////////////////////////////
// GameObject
//
// Author: TRiOLD
//
// 29.01.17				upd 06.02.17
////////////////////////////////////


////////////////////////////////////
// Includes

#include "LibsAndConstants.h"
#include "Improvements.h"
#include "Levels.h"
#include "GameObject.h"

////////////////////////////////////
GameObject::GameObject()
{
}

////////////////////////////////////
GameObjectPtr GameObject::Create()
{
	CREATE( GameObject, init() );
}

////////////////////////////////////
bool GameObject::init()
{
	m_game = NULL;
	m_type = GameObjectType_None;

	m_x = m_y = 0.0;
	m_xSpeed = m_ySpeed = 0.0;

	m_width = m_height = 1;
	m_wCenter = m_hCenter = 0.5;

	m_health = 1;
	m_destroyAfterDeath = true;
	m_invulnerable = false;

	m_physical = true;

	m_rotationSpeed = 0.0;
	m_directionFormally = 0;
	m_directionReal = 0.0;
	m_sideOfRotation = 1;

	m_sprite = new sf::Sprite();
	
	return true;
}

////////////////////////////////////
void GameObject::render( sf::RenderWindow* rw )
{
	if ( m_sprite )
	{
		F32 xSprite = getWCenter();
		F32 ySprite = getHCenter();
		F32 column = m_x - m_game->getOffSetX();
		F32 row = m_y - m_game->getOffSetY();
	}
}

////////////////////////////////////
void GameObject::update( F32 dt )
{
	F32 oldRow = m_y;
	F32 oldColumn = m_x;

	F32 newY = m_y + m_ySpeed * dt;
	F32 newX = m_x + m_xSpeed * dt;

	F32 newRow = newY;
	F32 newColumn = newX;


	if ( oldColumn != newColumn )
		m_game->moveObjectTo( shared_from_this(), newX, m_y) ;
	else
		m_x = newX;

	if ( oldRow != newRow )
		m_game->moveObjectTo( shared_from_this(), m_x, newY );
	else
		m_y = newY;
}

////////////////////////////////////
void GameObject::intersect( GameObjectPtr object )
{

}

////////////////////////////////////
void GameObject::doDamage( S32 damage )
{
	if ( getInvulnerable() )
		return;

	if ( m_health > damage )
		m_health -= damage;
	else
		m_health = 0;
}

////////////////////////////////////
bool GameObject::rotation( F32 deltaTime )
{
	if( m_rotationSpeed == 0 )
	{
		m_directionReal = m_directionFormally;
		return false;
	}

	S32 difference = ( S32 ) ( ( F32 )m_directionFormally - m_directionReal );
	if( difference == 0 )
	{
		m_sideOfRotation = 1;
		return false;		
	}
	
	if( difference < 0 )	difference += 360;
	
	if( difference < 180 )
		m_sideOfRotation =  1;
	else
		m_sideOfRotation = -1;
	
	F32 deltaAngle = deltaTime * m_rotationSpeed * 360;
	m_directionReal += deltaAngle * m_sideOfRotation;

	if( m_directionReal < 0 )		m_directionReal += 360;
	if( m_directionReal >= 360 )	m_directionReal -= 360;

//	if((m_sideOfRotation == 1 && m_directionReal > m_directionFormally)
//		|| (m_sideOfRotation == -1 && m_directionReal > m_directionFormally))
//		m_directionReal = m_directionFormally;


	//printf("%i, %f, %i, %f\n",m_directionFormally, m_directionReal, difference, deltaAngle);
	return true;
}
