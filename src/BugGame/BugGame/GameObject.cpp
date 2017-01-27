////////////////////////////////////
// GameObject
//
// Author: Triold
//
// **.01.17
////////////////////////////////////


////////////////////////////////////
// Includes
#include "LibsAndConstants.h"
#include "GameObject.h"
#include "Improvements.h"
#include "Levels.h"


////////////////////////////////////
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

	m_directionDegree = 0;

	m_sprite = new sf::Sprite();
	m_sprite->setTexture(*TextureAtlas);
	setTextureRect(sf::IntRect());
}

////////////////////////////////////
GameObject::~GameObject()
{
	if (m_sprite)
		delete m_sprite;
}

////////////////////////////////////
void GameObject::render(sf::RenderWindow* rw)
{
	if (m_sprite)
	{
		F32 xSprite = (F32)getWidth() * getWCenter();
		F32 ySprite = (F32)getHeight() * getHCenter();
		F32 column = m_x - m_game->getOffSetX();
		F32 row = m_y - m_game->getOffSetY();

		m_sprite->setOrigin(xSprite * TILE_SIZE, ySprite * TILE_SIZE);
		m_sprite->setPosition(column * TILE_SIZE, row * TILE_SIZE);
		rw->draw(*m_sprite);
	}
}

////////////////////////////////////
void GameObject::update(F32 dt)
{
	F32 oldRow = m_y;
	F32 oldColumn = m_x;

	F32 newY = m_y + m_ySpeed * dt;
	F32 newX = m_x + m_xSpeed * dt;

	F32 newRow = newY;
	F32 newColumn = newX;


	if (oldColumn != newColumn)
		m_game->moveObjectTo(this, newX, m_y);
	else
		m_x = newX;

	if (oldRow != newRow)
		m_game->moveObjectTo(this, m_x, newY);
	else
		m_y = newY;
}

////////////////////////////////////
void GameObject::intersect(GameObject* object)
{

}

////////////////////////////////////
void GameObject::doDamage(S32 damage)
{
	if (getInvulnerable())
		return;

	if (m_health > damage)
		m_health -= damage;
	else
		m_health = 0;
}

