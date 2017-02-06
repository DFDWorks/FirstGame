////////////////////////////////////
// Game
//
// Author: TRiOLD
//
// 29.01.17				upd 06.02.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "LibsAndConstants.h"
#include "Game.h"
#include "Improvements.h"
#include "Levels.h"
#include "GameHUD.h"	
#include "GO_Cockroach.h"	

sf::Texture* TextureAtlas;

////////////////////////////////////
Game::Game()
{
}

////////////////////////////////////
GamePtr Game::Create()
{
	CREATE( Game, init() );
}

////////////////////////////////////
bool Game::init()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;
	m_fps = 0;
	m_clockFpsUpdate = 1.0;

	m_isMenuActive = true;

	m_player = NULL;
	
	m_hud = NULL;
	for ( S32 i = 0; i < MAX_OBJ; i++ )
		m_objects[i] = NULL;

	m_renderWindow = NULL;

	m_levelNumber = 0;

	m_offSetX = m_offSetY = 0;

	m_btn_obj = m_btn_fps = m_btn_lvl = m_btn_hpP = m_btn_hpE = 0;

	return true;
}

////////////////////////////////////
void Game::setupSystem()
{
	srand( time( 0 ) );

	m_renderWindow = new sf::RenderWindow( 
		sf::VideoMode( WINDOW_X, WINDOW_Y, 32 ),
		"Bla-bla-bla",
		sf::Style::Titlebar | sf::Style::Close );

	TextureAtlas = new sf::Texture();
	TextureAtlas->loadFromFile( "atlas00.png" );
}

////////////////////////////////////
void Game::initialize()
{
	shutdown();

	S32 l = getLevelNumber();
	m_btn_lvl = l + 1;

	// Load level

	for ( S32 r = 0; r < LevelRows; r++ )
		for ( S32 c = 0; c < LevelColumns; c++ )
		{
			unsigned char cellSymbol = LevelsData[l][1][r][c];

			switch ( cellSymbol )
			{
			}

		}

	for ( S32 r = 0; r < LevelRows; r++ )
	{
		for ( S32 c = 0; c < LevelColumns; c++ )
		{
			unsigned char cellSymbol = LevelsData[l][0][r][c];

			switch ( cellSymbol )
			{
			}
		}
	}
	m_player = Cockroach::Create();
	m_player->setGame( shared_from_this() );

	m_hud = GameHUD::Create();
	m_hud->setGame( shared_from_this() );
	
}

////////////////////////////////////
bool Game::loop()
{
	if ( !m_renderWindow->isOpen() )
		return false;

	// Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	F32 deltaTime = F32( deltaClock ) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;


	sf::Event event;
	while ( m_renderWindow->pollEvent( event ) )
	{
		if ( event.type == sf::Event::Closed )
			m_renderWindow->close();
	}

	render();
	update( deltaTime );

	m_clockFpsUpdate -= deltaTime;
	if ( m_clockFpsUpdate > 0 )
		m_fps++;
	else
	{
		m_btn_fps = m_fps;
		m_fps = 0;
		m_clockFpsUpdate = 1.0;
	}

	S32 ping = 25 - deltaTime * 1000;
	if ( ping < 0 ) ping = 0;
	//	Sleep(  ping  );

	return m_isGameActive;


}

////////////////////////////////////
void Game::shutdown()
{
	for ( S32 i = 0; i < MAX_OBJ; i++ )
		if ( m_objects[i] != 0 )
		{
			m_objects[i] = 0;		//TRiOLD: NEED VECTOR!!!
		}
}

////////////////////////////////////
void Game::render()
{
	// Start frame
	m_renderWindow->clear( sf::Color::White );

	// Deaw all game objects

	m_btn_obj = 0;
	for ( S32 i = 0; i < MAX_OBJ; i++ )
		if ( m_objects[i] != NULL )
		{
			m_objects[i]->render( m_renderWindow );
			m_btn_obj++;
		}
	m_hud->render( m_renderWindow );

	m_player->render( m_renderWindow );
	
	

	// End frame
	m_renderWindow->display();
}

////////////////////////////////////
void Game::update( F32 dt )
{
	mousePixelPos = sf::Mouse::getPosition( *m_renderWindow );

	if ( m_isMenuActive )
	{
	}
	else
	{
		for ( S32 i = 0; i < MAX_OBJ; i++ )
			if ( m_objects[i] != 0 )
			{
				m_objects[i]->update( dt );

				if ( m_objects[i]->getHealth() <= 0 && m_objects[i]->getDestroyAfterDeath() )
					destroyObject( m_objects[i] );
			}

		m_btn_hpP = m_player->getHealth();

		// Player destroyed
		if ( m_player && m_player->getHealth() <= 0 )
			initialize();
	}

	m_player->update( dt );
	m_hud->update( dt );
	
}

////////////////////////////////////
GameObjectPtr Game::checkIntersects( F32 x, F32 y, F32 width, F32 height, GameObjectPtr exceptObject )
{
	F32 passing = 1.4;

	F32 x0 = x;
	F32 y0 = y;

	F32 x1;
	F32 y1;

	F32 minDistance;
	F32 realDistance;

	for ( S32 i = 0; i < MAX_OBJ; i++ )
		if ( m_objects[i] != 0 && m_objects[i]->getPhysical() && m_objects[i] != exceptObject )
		{
			x1 = m_objects[i]->getX();
			y1 = m_objects[i]->getY();

			minDistance = ( width + ( F32 )m_objects[i]->getWidth() ) / 2;			//Code smell!!!
			realDistance = sqrt( pow( x1 - x0, 2 ) + pow( y1 - y0, 2 ) ) * passing;

			if ( realDistance < minDistance )
			{
				return m_objects[i];
			}

		}

	return NULL;
}

////////////////////////////////////
bool Game::moveObjectTo( GameObjectPtr object, F32 x, F32 y )
{
	bool canMoveToCell = false;
	return canMoveToCell;
}

////////////////////////////////////
S32 Game::getObjectsCount( GameObjectType type )
{
	S32 totalCount = 0;

	for ( S32 i = 0; i < MAX_OBJ; i++ )
	{
		if ( m_objects[i] == 0 )
			continue;

		if ( m_objects[i]->getType() == type )
			totalCount++;
	}

	return totalCount;
}

////////////////////////////////////
GameObjectPtr Game::createObject( GameObjectType type, F32 x, F32 y )
{
	// Find free pointer and create object
	for ( S32 i = 0; i < MAX_OBJ; i++ )
	{
		if ( m_objects[i] == NULL )
		{
			GameObjectPtr object = NULL;

			switch ( type )
			{
			}

			if ( object == NULL )
				return NULL;

			object->setGame( shared_from_this() );


			if ( moveObjectTo( object, x, y ) == false )
			{
				return NULL;
			}

			m_objects[i] = object;

			return object;
		}
	}

	return NULL;
}

////////////////////////////////////
void Game::destroyObject( GameObjectPtr object )
{
	for ( S32 i = 0; i < MAX_OBJ; i++ )
	{
		if ( m_objects[i] == object )
		{
//			delete m_objects[i];
			m_objects[i] = 0;

			return;
		}
	}
}

////////////////////////////////////
void Game::increaseDiedEnemiesCount()
{
	m_diedEnemiesCount++;
}

////////////////////////////////////
void Game::levelUP()
{
	m_levelNumber++;
}


////////////////////////////////////
void Game::setOffSets( GameObjectPtr object )
{
//	if ( object->getX() > WINDOW_X / 2 / TILE_SIZE && object->getX() < COLUMNS - WINDOW_X / 2 / TILE_SIZE - 1.5 )
		m_offSetX = object->getX() - WINDOW_X / 2 / TILE_SIZE;
//	if ( object->getY() > WINDOW_Y / 2 / TILE_SIZE && object->getY() < ROWS - WINDOW_Y / 2 / TILE_SIZE - 1.5 )
		m_offSetY = object->getY() - WINDOW_Y / 2 / TILE_SIZE - 1.0;
}

////////////////////////////////////
S32 Game::getAngleMouseToObject( GameObjectPtr object )
{
	F32 dX = mousePixelPos.x - ( object->getX() - getOffSetX() ) * TILE_SIZE;
	F32 dY = mousePixelPos.y - ( object->getY() - getOffSetY() ) * TILE_SIZE;

	S32 res = ( S32 )( atan2( dY, dX ) * ( 180 / 3.14159265 ) );
	if( res < 0 )	res += 360;
	return res;
}
