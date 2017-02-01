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
#include "Label.h"
using namespace sf;
////////////////////////////////////
Label::Label()
{
	

	
}

////////////////////////////////////
LabelPtr Label::Create()
{
	CREATE(Label, init());
}

////////////////////////////////////
LabelPtr Label::Create(const STR& text)
{
	CREATE(Label, init(text));
}

////////////////////////////////////
bool Label::init()
{
	m_font = new Font();
	m_text = new Text();
	Log("Loading Label...\n");
	if (!m_font->loadFromFile("DroidSans.ttf"))
	{
		Log("Ouuu... FUCK! Cannot load font!\n");
	}
	m_text->setFont(*m_font);
	m_text->setCharacterSize(24);
	m_text->setFillColor(sf::Color(0, 0, 255));
	m_text->setStyle(sf::Text::Bold);
	m_text->setPosition(0, 0);

	return true;
}

////////////////////////////////////
bool Label::init(const STR& text)
{
	m_font = new Font();
	m_text = new Text();
	Log("Loading Label...\n");
	if (!m_font->loadFromFile("DroidSans.ttf"))
	{
		Log("Ouuu... FUCK! Cannot load font!\n");
	}
	m_text->setFont( *m_font );
	m_text->setString(text);
	m_text->setCharacterSize(24);
	m_text->setFillColor(sf::Color(0, 0, 255));
	m_text->setStyle(sf::Text::Bold);
	m_text->setPosition(0, 0);

	return true;
	
}

////////////////////////////////////
void Label::update(F32 dt)
{
	GameObject::update(dt);
	m_game->setOffSets(this);
	
}

////////////////////////////////////
void Label::render(sf::RenderWindow* rw)
{
	GameObject::render(rw);
}
