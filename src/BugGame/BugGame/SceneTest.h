////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

#ifndef _SceneTest_h_
#define _SceneTest_h_

////////////////////////////////////
// Includes
#include "GO_Cockroach.h"
#include "GameHUD.h"
#include "TextArea.h"


////////////////////////////////////
PTR( SceneTest );

class SceneTest
	: public GameObject
{
public:

	////////////////////////////////////
	SceneTest();

	////////////////////////////////////
	virtual void update( F32 dt ) OVERRIDE;

	////////////////////////////////////
	virtual void render( sf::RenderWindow* rw ) OVERRIDE;

	////////////////////////////////////
	static SceneTestPtr Create();

	////////////////////////////////////
	void proccesRender(  sf::RenderWindow* rw  );

private:

	////////////////////////////////////
	bool init();

protected:
	GameHUDPtr m_hud;
	TextAreaPtr m_textArea;
	DorPtr m_dor;
	sf::RectangleShape* m_rectangle; //for map rendering
	sf::Texture* m_block;
};

#endif

