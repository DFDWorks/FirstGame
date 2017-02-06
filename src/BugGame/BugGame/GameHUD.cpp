////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "GO_Cockroach.h"
#include "Improvements.h"
#include "GameHUD.h"
#include "TextArea.h"

////////////////////////////////////
GameHUD::GameHUD()
	: m_indicators( Indicators::MAX )
	, m_lifeCoeff( 0.531f )
	, m_manaCoeff( 1.0f )
	, m_staminaCoeff( 1.0f )
{
}

////////////////////////////////////
GameHUDPtr GameHUD::Create()
{
	CREATE(GameHUD, init());
}

////////////////////////////////////
bool GameHUD::init()
{
	GameObject::init();							

	Log( "Loading GameHUD...\n" );
	

	U16 arr[][Indicators::MAX] = {
									{ 347, 11, 199, 48 },
									{ 347, 55, 190, 48 },
									{ 347, 100, 190, 48 }
								 };
	for ( S32 j = 0; j < Indicators::MAX; j++ )
        {
            m_indiPos.push_back(std::vector<U16>());
            for (S32 i = 0; i < 5; i++ )
                 m_indiPos[j].push_back(arr[j][i]);
        }

	//Indicators Loading
	sf::Texture* tx = new sf::Texture();
	tx->loadFromFile("Hud.png");
	
	for ( U16 i = Indicators::Life; i < Indicators::MAX; i++ )
	{
		m_indicators[i] = new sf::Sprite();
		m_indicators[i]->setTexture( *tx );
		m_indicators[i]->setPosition( 78.0f, 8.0f );
		m_indicators[i]->setScale( 0.531f, 0.5f );
		m_indicators[i]->setTextureRect( sf::IntRect(m_indiPos[i-1][0], m_indiPos[i-1][1], m_indiPos[i-1][2], m_indiPos[i-1][3]) );
	}

	//delete tx;

	m_label = Label::Create( "Level \"Asshole\" " );
	m_label->setPosition( 20,100 );
	sf::Texture* hud = new sf::Texture();
	hud->loadFromFile( "Hud.png" );
	m_sprite->setTexture( *hud );
	m_sprite->setPosition( 0, 0 );
	m_sprite->setScale( 0.5f, 0.5f );
	m_sprite->setTextureRect( sf::IntRect( 0, 155, 335, 160 ) );

	
	

	return true;
}

////////////////////////////////////
void GameHUD::update( F32 dt )
{
    GameObject::update( dt );

	if (m_lifeCoeff > 0)
	{
		F32 x = m_lifeCoeff -= dt/80;
		F32 y = m_indicators[Indicators::Life]->getScale().y;
		m_indicators[Indicators::Life]->setScale( x, y );
	}
}
    
////////////////////////////////////
void GameHUD::render(sf::RenderWindow* rw)
{
	TextAreaPtr x = TextArea::Create();
	GameObject::render(rw);
	rw->draw( *m_label->operator sf::Text *() );
	rw->draw( *m_indicators[Indicators::Life] );
	rw->draw( *m_sprite );
	//Log( sizeof(m_indicators) );
	rw->draw( *x->getSprite() );
	
	
	
}
