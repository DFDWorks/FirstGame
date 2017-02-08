////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

#ifndef _GameHUD_h_
#define _GameHUD_h_

////////////////////////////////////
// Includes
#include "GameObject.h"
#include "Levels.h"
#include "Label.h"
#include "Dor.h"

////////////////////////////////////
PTR( GameHUD );
PTR( Dor );

namespace Indicators
{
	enum Enum
	{
		None = 0,
		Life,
		Stamina,
		Mana,
		MAX = 4
	};
}

class GameHUD
	: public GameObject
{
public:

	////////////////////////////////////
	GameHUD();

	////////////////////////////////////
	virtual void update(F32 dt) OVERRIDE;

	////////////////////////////////////
	virtual void render( sf::RenderWindow* rw ) OVERRIDE;

	////////////////////////////////////
	static GameHUDPtr Create();

private:

	////////////////////////////////////
	bool init();

protected:
	
	LabelPtr m_label;
	std::vector<sf::Sprite*> m_indicators;
	std::vector<std::vector<U16>> m_indiPos;

	F32 m_lifeCoeff;
	F32 m_manaCoeff;
	F32 m_staminaCoeff;
	DorPtr m_dor;
};

#endif