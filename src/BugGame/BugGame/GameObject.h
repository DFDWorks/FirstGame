////////////////////////////////////
// GameObject
//
// Author: TRiOLD
//
// 29.01.17
////////////////////////////////////
#pragma once

////////////////////////////////////
// Includes
#include "Game.h"

class Game;

////////////////////////////////////
enum GameObjectType
{
	GameObjectType_None,
	MAX

};

class GameObject
{
public:

	////////////////////////////////////
	GameObject();

	////////////////////////////////////
	virtual ~GameObject();

	////////////////////////////////////
	virtual void render(sf::RenderWindow* rw);

	////////////////////////////////////
	virtual void update(F32 dt);

	////////////////////////////////////
	virtual void intersect(GameObject* object);

	////////////////////////////////////
	GameObjectType getType(){ return m_type; }

	////////////////////////////////////
	void setGame(Game* game){ m_game = game; }

	////////////////////////////////////
	void setX(F32 x){ m_x = x; }

	////////////////////////////////////
	F32 getX(){ return m_x; }

	////////////////////////////////////
	void setY(F32 y){ m_y = y; }

	////////////////////////////////////
	F32 getY(){ return m_y; }

	////////////////////////////////////
	void setXSpeed(F32 xSpeed){ m_xSpeed = xSpeed; }

	////////////////////////////////////
	F32 getXSpeed(){ return m_xSpeed; }

	////////////////////////////////////
	void setYSpeed(F32 ySpeed){ m_ySpeed = ySpeed; }

	////////////////////////////////////
	F32 getYSpeed(){ return m_ySpeed; }

	////////////////////////////////////
	void setWidth(F32 width){ m_width = width; }

	////////////////////////////////////
	F32 getWidth(){ return m_width; }

	////////////////////////////////////
	void setHeight(F32 height){ m_height = height; }

	////////////////////////////////////
	F32 getHeight(){ return m_height; }

	////////////////////////////////////
	void setWCenter(S32 center){ m_wCenter = center; }

	////////////////////////////////////
	F32 getWCenter(){ return m_wCenter; }

	////////////////////////////////////
	void setHCenter(S32 center){ m_hCenter = center; }

	////////////////////////////////////
	F32 getHCenter(){ return m_hCenter; }

	////////////////////////////////////
	void setHealth(S32 health){ m_health = health; }

	////////////////////////////////////
	S32 getHealth(){ return m_health; }

	////////////////////////////////////
	void setDestroyAfterDeath(bool destroyAfterDeath){ m_destroyAfterDeath = destroyAfterDeath; }

	////////////////////////////////////
	bool getDestroyAfterDeath(){ return m_destroyAfterDeath; }

	////////////////////////////////////
	void setInvulnerable(bool invulnerable){ m_invulnerable = invulnerable; }

	////////////////////////////////////
	bool getInvulnerable(){ return m_invulnerable; }

	////////////////////////////////////
	void setPhysical(bool physical){ m_physical = physical; }

	////////////////////////////////////
	bool getPhysical(){ return m_physical; }

	////////////////////////////////////
	void doDamage(S32 damage);

	////////////////////////////////////
	void setTextureRect(sf::IntRect rect){ m_sprite->setTextureRect(rect); }

	

	////////////////////////////////////
	void setDirectionDegree(S32 directionDegree){ m_directionFormally = directionDegree; }

	////////////////////////////////////
	S32 getDirectionDegree(){ return m_directionFormally; }

	////////////////////////////////////
	bool rotation(F32 deltaTime);

protected:
	Game* m_game;
	GameObjectType m_type;

	F32 m_x;
	F32 m_y;
	F32 m_xSpeed;
	F32 m_ySpeed;

	F32 m_width;
	F32 m_height;
	F32 m_wCenter;
	F32 m_hCenter;

	S32 m_health;
	bool m_destroyAfterDeath;
	bool m_invulnerable;

	bool m_physical;
	
	F32 m_rotationSpeed;			// One revolution per second
	S32 m_directionFormally;		// The value of which operate
	F32 m_directionReal;			// Values displayed. Approaching to formally
	S32 m_sideOfRotation;			// 1 - clockwise, -1 - anticlockwise

	sf::Sprite* m_sprite;
	
};
