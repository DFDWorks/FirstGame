#pragma once

#include "Game.h"

enum GameObjectType
{
	GameObjectType_None,


};

class Game;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void render( sf::RenderWindow* rw );
	virtual void update( float dt );

	virtual void intersect( GameObject* object );

	GameObjectType getType(){ return m_type; }

	void setGame( Game* game ){ m_game = game; }

	void setX( float x ){ m_x = x; }
	float getX(){ return m_x; }

	void setY( float y ){ m_y = y; }
	float getY(){ return m_y; }

	void setXSpeed( float xSpeed ){ m_xSpeed = xSpeed; }
	float getXSpeed(){ return m_xSpeed; }

	void setYSpeed( float ySpeed ){ m_ySpeed = ySpeed; }
	float getYSpeed(){ return m_ySpeed; }

	void setWidth( float width ){ m_width = width; }
	float getWidth(){ return m_width; }

	void setHeight( float height ){ m_height = height; }
	float getHeight(){ return m_height; }

	void setWCenter( int center ){ m_wCenter = center; }
	float getWCenter(){ return m_wCenter; }
	
	void setHCenter( int center ){ m_hCenter = center; }
	float getHCenter(){ return m_hCenter; }

	void setHealth( int health ){ m_health = health; }
	int getHealth(){ return m_health; }

	void setDestroyAfterDeath( bool destroyAfterDeath ){ m_destroyAfterDeath = destroyAfterDeath; }
	bool getDestroyAfterDeath(){ return m_destroyAfterDeath; }

	void setInvulnerable( bool invulnerable ){ m_invulnerable = invulnerable; }
	bool getInvulnerable(){ return m_invulnerable; }

	void setPhysical( bool physical ){ m_physical = physical; }
	bool getPhysical(){ return m_physical; }

	void setTierTop( bool tierTop ){ m_tierTop = tierTop; }
	bool getTierTop(){ return m_tierTop; }

	void setTierBottom( bool tierBottom ){ m_tierBottom = tierBottom; }
	bool getTierBottom(){ return m_tierBottom; }

	void doDamage( int damage );

	void setTextureRect( sf::IntRect rect ){ m_sprite->setTextureRect( rect ); }

	void setDirectionDegree( int directionDegree ){ m_directionDegree = directionDegree; }
	int getDirectionDegree(){ return m_directionDegree; }

	void chengeShots( int maxCountShots, float frequency, float dt );

protected:
	Game* m_game;
	GameObjectType m_type;

	float m_x;
	float m_y;
	float m_xSpeed;
	float m_ySpeed;

	float m_shot;
	float m_shotTime;

	float m_width;
	float m_height;
	float m_wCenter;
	float m_hCenter;

	int m_health;
	bool m_destroyAfterDeath;
	bool m_invulnerable;

	bool m_physical;
	bool m_tierTop;
	bool m_tierBottom;

	int m_directionDegree;

	sf::Sprite* m_sprite;
};