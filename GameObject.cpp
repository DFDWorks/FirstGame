#include "LibsAndConstants.h"
#include "GameObject.h"

GameObject::GameObject()
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
	m_tierTop = true;
	m_tierBottom = true;

	m_directionDegree = 0;

	m_sprite = new sf::Sprite();
	m_sprite->setTexture( *TextureAtlas );
	setTextureRect( sf::IntRect() );

	m_shot = 0;
	m_shotTime = 0.0;
}

GameObject::~GameObject()
{
	if( m_sprite )
		delete m_sprite;
}

void GameObject::render( sf::RenderWindow* rw )
{
	if( m_sprite )
	{
		float xSprite = (float)getWidth() * getWCenter();
		float ySprite = (float)getHeight() * getHCenter();
		float column = m_x - m_game->getOffSetX(); 
		float row = m_y - m_game->getOffSetY();

		m_sprite->setOrigin( xSprite * TILE_SIZE, ySprite * TILE_SIZE );
		m_sprite->setPosition( column * TILE_SIZE, row * TILE_SIZE );
		rw->draw(*m_sprite);
	}
}	

void GameObject::update( float dt )
{
	float oldRow = m_y;
	float oldColumn = m_x;

	float newY = m_y + m_ySpeed * dt;
	float newX = m_x + m_xSpeed * dt;

	float newRow = newY;
	float newColumn = newX;


	if( oldColumn != newColumn )
		m_game->moveObjectTo( this, newX, m_y );
	else
		m_x = newX;

	if( oldRow != newRow )
		m_game->moveObjectTo( this, m_x, newY );
	else
		m_y = newY;
}

void GameObject::intersect( GameObject* object )
{
	
}

void GameObject::doDamage( int damage )
{
	if( getInvulnerable() )
		return;

	if( m_health > damage )
		m_health -= damage;
	else
		m_health = 0;
}

void GameObject::chengeShots( int maxCountShots, float frequency, float dt )
{
	float timeCh = (float)1/frequency;
	m_shotTime += dt;
	_reIn1:
	if(m_shotTime >= timeCh)
	{
		m_shotTime -= timeCh;
		m_shot++;
		goto _reIn1;
	}
	
	_reIn2:
	if(m_shot >= maxCountShots)
	{
		m_shot -= maxCountShots;
		goto _reIn2;
	}
}