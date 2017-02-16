////////////////////////////////////
// Cockroach
//
// Author: Eugene
//
// 29.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "SceneTest.h"
#include "Action2D_sinMovement.h"

////////////////////////////////////
SceneTest::SceneTest()
{
}

////////////////////////////////////
SceneTestPtr SceneTest::Create()
{
	CREATE( SceneTest, init() );
}

////////////////////////////////////
bool SceneTest::init()
{
	GameObject::init();							

	Log( "Loading SceneTest...\n" );

	m_rectangle = new sf::RectangleShape(sf::Vector2f(32, 32)); //for map
	m_block = new sf::Texture();
	m_block->loadFromFile( "block.png" );
	

	m_textArea = TextArea::Create( 150, 400, "I am BUG!" );
	m_dor = Dor::Create();
	m_dor->setScale( 0.2f, 0.2f );
	m_dor->setPosition( 120.0f, 510.0f );
	m_hud = GameHUD::Create();
	m_hud->setGame( this->getGame() );
	return true;
}

////////////////////////////////////
void SceneTest::update( F32 dt )
{
    GameObject::update( dt );
	m_hud->update( dt );
	
}
    
////////////////////////////////////
void SceneTest::render( sf::RenderWindow* rw )
{
	GameObject::render(rw);

	proccesRender( rw );

	m_hud->render( rw );
	m_textArea->render( rw );
	rw->draw( *m_dor->getSprite() );
}

////////////////////////////////////
void SceneTest::proccesRender(  sf::RenderWindow* rw  )
{
	for ( S32 r = 0; r < 19; r++ )
	{
		for ( S32 c = 0; c < 25; c++ )
		{

			if( Map[r][c] == 'm' )
			{
				m_rectangle->setTexture( m_block );
				m_rectangle->setPosition( c * TILE_SIZE , r * TILE_SIZE );
				rw->draw( *m_rectangle );
			}

			if( Map[r][c] == 's' )
			{
				sf::Texture* tex = new sf::Texture();
				tex->loadFromFile( "block_surprise00.png" );
				m_rectangle->setTexture( tex );
				m_rectangle->setPosition( c * TILE_SIZE , r * TILE_SIZE );
				rw->draw( *m_rectangle );
			}

		}
	}
}
