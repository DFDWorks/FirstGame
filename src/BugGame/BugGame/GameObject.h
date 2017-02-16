////////////////////////////////////
// GameObject
//
// Author: TRiOLD
//
// 29.01.17				upd 06.02.17
////////////////////////////////////
#pragma once

////////////////////////////////////
// Includes

//#include "Action2D.h"
#include "Game.h"

////////////////////////////////////
enum GameObjectType
{
	GameObjectType_None,
	GameObjectType_MAX

};

PTR( Game );
PTR( GameObject );


template < typename T >
class SharedObject
	: public std::enable_shared_from_this< T >
{
public:

	////////////////////////////////////
	// Typedef
	typedef std::shared_ptr<T> TPtr;
	typedef std::weak_ptr<T> TWPtr;

public:

	////////////////////////////////////
       virtual ~SharedObject()
       {}

	////////////////////////////////////
	template < class U >
	inline std::shared_ptr< U > cast()
	{ 
		BREAK_IF( !this->shared_from_this() );
		return STATIC_POINTER_CAST< U >( thisShared() ); 
	}

	////////////////////////////////////
	template < class U >
	inline const U* castPure() const
	{ 
		return static_cast< const U* >( this ); 
	}

	////////////////////////////////////
	template < class U >
	inline U* castPure()
	{ 
		return static_cast< U* >( this ); 
	}

protected:

	////////////////////////////////////
	inline TPtr thisShared()
	{
		return this->shared_from_this();
	}

};

class GameObject
	: public SharedObject<GameObject>
{
public:

	////////////////////////////////////
	GameObject();

	////////////////////////////////////
	static GameObjectPtr Create();

	////////////////////////////////////
	virtual void render( sf::RenderWindow* rw );

	////////////////////////////////////
	virtual void update( F32 dt );

	////////////////////////////////////
	virtual void intersect( GameObjectPtr object );

	////////////////////////////////////
	GameObjectType getType(){ return m_type; }

	////////////////////////////////////
	void setGame( const GamePtr& game ){ m_game = game; }

	////////////////////////////////////
	inline const GamePtr& getGame() const { return m_game; }

	////////////////////////////////////
	void setSprite( sf::Sprite* spr ){ m_sprite = spr; }

	////////////////////////////////////
	void setX(F32 x){ m_x = x; }

	////////////////////////////////////
	F32 getX(){ return m_x; }

	////////////////////////////////////
	void setY(F32 y){ m_y = y; }

	////////////////////////////////////
	F32 getY(){ return m_y; }

	////////////////////////////////////
	void setXSpeed( F32 xSpeed ){ m_xSpeed = xSpeed; }

	////////////////////////////////////
	F32 getXSpeed(){ return m_xSpeed; }

	////////////////////////////////////
	void setYSpeed( F32 ySpeed ){ m_ySpeed = ySpeed; }

	////////////////////////////////////
	F32 getYSpeed(){ return m_ySpeed; }

	////////////////////////////////////
	void setWidth( F32 width ){ m_width = width; }

	////////////////////////////////////
	F32 getWidth(){ return m_width; }

	////////////////////////////////////
	void setHeight( F32 height ){ m_height = height; }

	////////////////////////////////////
	F32 getHeight(){ return m_height; }

	////////////////////////////////////
	void setWCenter( F32 center ){ m_wCenter = center; }

	////////////////////////////////////
	F32 getWCenter(){ return m_wCenter; }

	////////////////////////////////////
	void setHCenter( F32 center ){ m_hCenter = center; }

	////////////////////////////////////
	F32 getHCenter(){ return m_hCenter; }

	////////////////////////////////////
	void setHealth( S32 health ){ m_health = health; }

	////////////////////////////////////
	S32 getHealth(){ return m_health; }

	////////////////////////////////////
	void setDestroyAfterDeath( bool destroyAfterDeath ){ m_destroyAfterDeath = destroyAfterDeath; }

	////////////////////////////////////
	bool getDestroyAfterDeath(){ return m_destroyAfterDeath; }

	////////////////////////////////////
	void setInvulnerable( bool invulnerable ){ m_invulnerable = invulnerable; }

	////////////////////////////////////
	bool getInvulnerable(){ return m_invulnerable; }

	////////////////////////////////////
	void setPhysical( bool physical ){ m_physical = physical; }

	////////////////////////////////////
	bool getPhysical(){ return m_physical; }

	////////////////////////////////////
	void doDamage( S32 damage );

	////////////////////////////////////
	void setTextureRect( sf::IntRect rect ){ m_sprite->setTextureRect(rect); }

	////////////////////////////////////
	inline const sf::Sprite* getSprite() const { return m_sprite; }

	////////////////////////////////////
	void setScale( const F32& x, const F32& y ) const { m_sprite->setScale( x, y ); }

	////////////////////////////////////
	void setPosition( const F32& x, const F32& y ) const { m_sprite->setPosition( x, y ); }

	////////////////////////////////////
	void setDirectionDegree( S32 directionDegree ){ m_directionFormally = directionDegree; }

	////////////////////////////////////
	S32 getDirectionDegree(){ return m_directionFormally; }

	////////////////////////////////////
	bool rotation( F32 deltaTime );

	////////////////////////////////////
	//void runAction( const GameObjectPtr& object, const Action2DPtr& action );

	////////////////////////////////////
protected:

	bool init();

protected:
	GamePtr m_game;
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

	// Actions
	//std::vector< Action2DPtr > m_actions;
	
};

