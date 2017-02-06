////////////////////////////////////
// Cockroach
//
// Author: DD
//
// 05.02.17
////////////////////////////////////

#ifndef _Button_h_
#define _Button_h_

////////////////////////////////////
// Includes
#include "GameObject.h"
#include "Levels.h"

////////////////////////////////////
PTR(Button);



class Button
	: public GameObject
{
public:

	////////////////////////////////////
	Button();

	////////////////////////////////////
	virtual void update(F32 dt) OVERRIDE;

	////////////////////////////////////
	virtual void render(sf::RenderWindow* rw) OVERRIDE;

	///////////////////////////////////
	inline const sf::Mouse* getMouseButton() const { return m_mouse; }

    ///////////////////////////////////
	inline const sf::Vector2i getMousePosition() const { return m_posOfPixels; }

	////////////////////////////////////
	void setPosition( const F32& x, const F32& y ){ }

	////////////////////////////////////
	static ButtonPtr Create();

private:

	////////////////////////////////////
	bool init();

protected:

	sf::Mouse* m_mouse;
	sf::RenderWindow* m_gameWindow;
	sf::Vector2i m_posOfPixels;

};

#endif