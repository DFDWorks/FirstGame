////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes

#include "Improvements.h"
#include "TextArea.h"

using namespace sf;
////////////////////////////////////
TextArea::TextArea()
{
}

////////////////////////////////////
TextAreaPtr TextArea::Create()
{
	CREATE( TextArea, init() );
}

////////////////////////////////////
bool TextArea::init()
{
	GameObject::init();						//TRiOLD:	Call of the designer of the base class

	Log( "Loading TextArea...\n" );
	sf::Texture* area = new sf::Texture();
	area->loadFromFile( "speak_areas01.png" );
	m_sprite->setTexture( *area );
	
	m_sprite->setPosition( WINDOW_X/2, WINDOW_Y/2 );
	m_sprite->setTextureRect( sf::IntRect( 0, 0, 147, 96 ) );
	

	return true;
}

////////////////////////////////////
void TextArea::update( F32 dt )
{
	GameObject::update( dt );
//	m_game->setOffSets( this );	
	
}

////////////////////////////////////
void TextArea::render( sf::RenderWindow* rw )
{
	GameObject::render( rw );
}


////////////////////////////////////
void TextArea::setAreaImage( const F32& x, const F32& y, const F32& width, const F32& height )
{ 
	// Here you cen set image for your text area
	m_sprite->setTextureRect( sf::IntRect( x, y, width, height ) ); 
}
