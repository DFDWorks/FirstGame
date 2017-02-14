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
#include "Label.h"

using namespace sf;
////////////////////////////////////
TextArea::TextArea()
{
}

////////////////////////////////////
TextArea::~TextArea()
{
}

////////////////////////////////////
TextAreaPtr TextArea::Create( const F32& x, const F32& y, std::string str )
{
	CREATE( TextArea, init( x, y, str ) );
}

////////////////////////////////////
bool TextArea::init( const F32& x, const F32& y, std::string str )
{
	GameObject::init();						//TRiOLD:	Call of the designer of the base class

	Log( "Loading TextArea...\n" );

	m_label = Label::Create( str );
	

	sf::Texture* area = new sf::Texture();
	area->loadFromFile( "speak_areas01.png" );
	m_sprite->setTexture( *area );
	
	m_sprite->setPosition( x, y );
	m_label->setPosition( m_sprite->getPosition().x + 20, m_sprite->getPosition().y + 20 );
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
	rw->draw( *m_sprite );
	rw->draw( *m_label->getText() );
}


////////////////////////////////////
void TextArea::setAreaImage( const F32& x, const F32& y, const F32& width, const F32& height )
{ 
	// Here you cen set image for your text area
	m_sprite->setTextureRect( sf::IntRect( x, y, width, height ) ); 
}
