////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

#ifndef _TextArea_h_
#define _TextArea_h_

////////////////////////////////////
// Includes
#include "GameObject.h"
#include "Levels.h"

////////////////////////////////////
PTR( TextArea );

class TextArea
	: public GameObject
{
public:

	////////////////////////////////////
	TextArea();

	////////////////////////////////////
	virtual void update( F32 dt ) OVERRIDE;

	////////////////////////////////////
	virtual void render( sf::RenderWindow* rw ) OVERRIDE;

	////////////////////////////////////
	static TextAreaPtr Create();

	////////////////////////////////////
	void setPosition( const F32& x, const F32& y ) { m_sprite->setPosition( x, y ); };

	////////////////////////////////////
	inline const sf::Vector2f getPosition() const { return m_sprite->getPosition(); } 

	////////////////////////////////////
	void setAreaImage( const F32& x, const F32& y, const F32& width, const F32& height );
		
private:

	////////////////////////////////////
	bool init();

protected:

};

#endif