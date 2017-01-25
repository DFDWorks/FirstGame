#include "LibsAndConstants.h"
#include "Game.h"

Game::Game()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;
	m_fps = 0;
	m_clockFpsUpdate = 1.0;

	m_menu = NULL;
	m_isMenuActive = true;

	for( int i = 0; i < MAX_OBJ; i++ )
		m_objects[i] = NULL;
	for( int i = 0; i < MAX_OBJBGRND; i++ )
		m_objectsBgnd[i] = NULL;
	for( int i = 0; i < MAX_BAR_BUTT; i++ )
		m_buttons[i] = NULL;

	m_BaseEnemy = NULL;
	m_player = NULL;

	m_renderWindow = NULL;

	m_diedEnemiesCount = 0;

	m_levelNumber = 0;

	m_offSetX = m_offSetY = 0;	

	m_btn_obj = m_btn_fps = m_btn_lvl = m_btn_hpP = m_btn_hpE = 0;
}

Game::~Game()
{
	if( TextureAtlas  )
		delete TextureAtlas;

	if( m_renderWindow )
		delete m_renderWindow;
	
	if( m_menu )
		delete m_menu;
}

void Game::setupSystem()
{
	srand( time( 0 ) );

	m_renderWindow = new sf::RenderWindow( 
		sf::VideoMode( WINDOW_X, WINDOW_Y, 32),
		"Deuterium Tanks",
		sf::Style::Titlebar | sf::Style::Close );

	TextureAtlas = new sf::Texture();
	TextureAtlas->loadFromFile("mediaData/atlas.png");

	Font = new sf::Font();
	Font->loadFromFile( "mediaData/Engr.ttf" );
}

void Game::initialize()
{
	shutdown();

	m_menu = new Menu();
	m_menu->setGame( this );
	m_menu->initialize();

	int l = getLevelNumber();
	m_btn_lvl = l+1;

	// Load level

	for( int r = 0; r < LevelRows; r++ )
		for( int c = 0; c < LevelColumns; c++ )
		{
			unsigned char cellSymbol = LevelsData[l][1][r][c];
			
			switch ( cellSymbol )
			{
				case CellSymbol_BgndAsphalt:
					createBgrndObject( BackgroundType_Asphalt, c, r );
					break;

				case CellSymbol_BgndGrass0:
					createBgrndObject( BackgroundType_Grass, c, r );
					break;

				case CellSymbol_BgndSoil0:
					createBgrndObject( BackgroundType_Soil, c, r );
					break;
			}

		}

	for( int r = 0; r < LevelRows; r++ )
	{
		for( int c = 0; c < LevelColumns; c++ )
		{
			unsigned char cellSymbol = LevelsData[l][0][r][c];

			switch( cellSymbol )
			{
				case CellSymbol_BrickWall:
				{
					Wall* wall = (Wall*)createObject( GameObjectType_Wall, c, r );
					wall->setTextureRect( kWallBrickImage );
					break;
				}

				case CellSymbol_SteelWall:
				{
					Wall* wall = (Wall*)createObject( GameObjectType_Wall, c, r );
					wall->setTextureRect( kWallSteelImage );
					wall->setInvulnerable( true );
					break;
				}
				
				case CellSymbol_HedgehogWall:
				{
					Wall* wall = (Wall*)createObject( GameObjectType_Wall, c, r );
					wall->setTextureRect( kWallHedgehogImage );
					wall->setInvulnerable( true );
					wall->setTierTop( false );
					break;
				}

				case CellSymbol_Tank:
				{
					//НАПИСАТЬ!!!
					break;
				}

				case CellSymbol_BaseEnemy:
				{
					m_BaseEnemy = createObject( GameObjectType_BaseEnemy, c, r );
					break;
				}

				case CellSymbol_Fire:
				{
					Fire* fire = (Fire*)createObject( GameObjectType_Fire, c, r );
					break;
				}

				case CellSymbol_Box:
				{
					Box* box = (Box*)createObject( GameObjectType_Box, c, r );
					break;
				}

				case CellSymbol_Player:
				{
					TankPlayer* player = (TankPlayer*)createObject( GameObjectType_TankPlayer, c, r );
					if( player )
					{
						player->m_gun = (TankGun*)createObject( GameObjectType_TankGun, c, r );
						player->m_gun->initializeGun( player );
						player->setKeys( 'A', 'D', 'W', 'S', ' ' );
						m_player = player;
					}
					break;
				}

				case CellSymbol_Enemy:
				{
					
					TankEnemy* enemy = (TankEnemy*)createObject( GameObjectType_TankEnemy, c, r );
					if( enemy )
					{
						enemy->m_gun = (TankGun*)createObject( GameObjectType_TankGun, c, r );
						enemy->m_gun->initializeGun( enemy );
					}
					break;
				}

			}
		}
	}

	for(int i=0; i<MAX_BAR_BUTT; i++)
		createButton( (ButtonType)i );
}

bool Game::loop()
{
	if( !m_renderWindow->isOpen() )
		return false;

	// Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;


	sf::Event event;
    while( m_renderWindow->pollEvent(event) )
	{
		if( event.type == sf::Event::Closed )
			m_renderWindow->close();
	}
	
	render();
	update( deltaTime );

	m_clockFpsUpdate -= deltaTime;
	if(m_clockFpsUpdate > 0)
		m_fps++;
	else
	{
		m_btn_fps = m_fps;
		m_fps = 0;
		m_clockFpsUpdate = 1.0;
	}

	int ping = 25 - deltaTime*1000;
	if(ping < 0 ) ping = 0;
	Sleep( ping );

	return m_isGameActive;


}

void Game::shutdown()
{
	for( int i = 0; i < MAX_OBJ; i++ )
		if( m_objects[i] != 0 )
		{
			delete m_objects[i];
			m_objects[i] = 0;
		}
}

void Game::render()
{
	// Start frame
	m_renderWindow->clear( sf::Color::Black );

	// Deaw all game objects
	for( int i = 0; i < MAX_OBJBGRND; i++ ) 
		if( m_objectsBgnd[i] != NULL )
			 m_objectsBgnd[i]->render( m_renderWindow );

	m_btn_obj = 0;
	for( int i = 0; i < MAX_OBJ; i++ ) 
		if( m_objects[i] != NULL )
		{
			 m_objects[i]->render( m_renderWindow );
			 m_btn_obj++;
		}

	for( int i = 0; i < MAX_BAR_BUTT; i++ )
		if( m_buttons[i] != NULL )
			 m_buttons[i]->render( m_renderWindow );

	if( m_isMenuActive )
		m_menu->render( m_renderWindow );

	// End frame
	m_renderWindow->display();
}

void Game::update( float dt )
{
	mousePixelPos = sf::Mouse::getPosition( * m_renderWindow );

	if( m_isMenuActive )
		m_menu->update( dt );
	else
	{
		for( int i = 0; i < MAX_OBJ; i++ ) 
			if( m_objects[i] != 0 )
			{
				 m_objects[i]->update( dt );

				 if( m_objects[i]->getHealth() <= 0 && m_objects[i]->getDestroyAfterDeath() )
					 destroyObject( m_objects[i] );
			}

		m_btn_hpP = m_player->getHealth(); 

		if( m_BaseEnemy && m_BaseEnemy->getHealth() <= 0 )
		{
			levelUP();
			initialize();
		}

		// Player destroyed
		if( m_player && m_player->getHealth() <= 0 )
			initialize();

		textValueButton();
		for( int i = 0; i < MAX_BAR_BUTT; i++ )
			if( m_buttons[i] != 0 )
				m_buttons[i]->update( dt );
	}

//	printf("%f, %f, %f, %f\n",float(mousePixelPos.x), float(mousePixelPos.y), m_offSetX*TILE_SIZE, m_offSetY*TILE_SIZE);
}

GameObject* Game::checkIntersects( float x, float y, float width, float height, GameObject* exceptObject )
{
	float passing = 1.4;

	float x0 = x;
	float y0 = y;

	float x1;
	float y1;

	float minDistance;
	float realDistance;
	
	for( int i = 0; i < MAX_OBJ; i++ ) 
		if( m_objects[i] != 0 && m_objects[i]->getPhysical() && m_objects[i] != exceptObject )
		{
			x1 = m_objects[i]->getX();
			y1 = m_objects[i]->getY();

			minDistance = (width + (float)m_objects[i]->getWidth())/2;			//Реализация только для квадратных плиток!
			realDistance = sqrt( pow(x1-x0, 2) +  pow(y1-y0, 2) ) * passing;

			if( realDistance < minDistance )
			{
			//	printf("%f, %f\t %f, %f\t %f,%f\n", x, y, x1, y1, realDistance, minDistance);
				return m_objects[i];
			}
				
		}

	return NULL;
}

bool Game::moveObjectTo( GameObject* object, float x, float y )
{
	float r0 = y;
	float c0 = x;
	float r1 = r0 + object->getHeight() - 1;
	float c1 = c0 + object->getWidth() - 1;

	if( r0 < 0 || c0 < 0 || r1 >= LevelRows || c1 >= LevelColumns )
		return false;


	GameObject* otherObject = checkIntersects( x , y, object->getWidth(), object->getHeight(), object );

	if( !object->getPhysical() )
		return true;
	
	bool canMoveToCell = false;

	if( otherObject )
	{
		object->intersect( otherObject );
		otherObject->intersect( object );
		if( !otherObject->getTierBottom() )
			canMoveToCell = true;
		if( object->getType() == GameObjectType_Bullet && !otherObject->getTierTop() )
			canMoveToCell = true;
	}
	else
		canMoveToCell = true;

	if( canMoveToCell )
	{
		object->setX( x );
		object->setY( y );
	}



	return canMoveToCell;
}

int Game::getObjectsCount( GameObjectType type )
{
	int totalCount = 0;

	for( int i = 0; i < MAX_OBJ; i++ )
	{	
		if( m_objects[i] == 0 )
			continue;

		if( m_objects[i]->getType() == type )
			totalCount++;
	}

	return totalCount;
}

void Game::textValueButton()
{
	char* str = new char[5];
	ButtonType type = ButtonType_None;

	for( int i = 0; i < MAX_BAR_BUTT; i++ )
	{ 
		if ( m_buttons[i] != NULL )
		{
			type = m_buttons[i]->getType();

			switch ( type )
			{ 
				case ButtonType_FPS:			sprintf(str, "%i\0", m_btn_fps);	break;
				case ButtonType_OBJ:			sprintf(str, "%i\0", m_btn_obj);	break;
				case ButtonType_Level:			sprintf(str, "%i\0", m_btn_lvl);	break;
				case ButtonType_PlayerHalth:	sprintf(str, "%i\0", m_btn_hpP);	break;
				case ButtonType_EnemyBaseHalth:	sprintf(str, "%i\0", m_btn_hpE);	break;

				case ButtonType_Menu:	sprintf(str, "\0");		break;
				case ButtonType_None:	sprintf(str, "\0");		break;
			}
			m_buttons[i]->setTextVariable( str );
		}
	}
	delete []str;
}

Button* Game::createButton( ButtonType type )
{
	Button* object = new Button();

	if( type == ButtonType_Menu )
		object = new Bar_Menu();

	object->initializeBar( type );
	object->setGame( this );

	for( int i = 0; i < MAX_BAR_BUTT; i++ )
	{
		if( m_buttons[i] == NULL )
		{
			m_buttons[i] = object;
			return object;
		}
	}
	return NULL;
}

Background* Game::createBgrndObject( BackgroundType type, float x, float y )
{
	Background* object = new Background();
	object->initialize( type, x, y );
	object->setGame( this );

	for( int i = 0; i < MAX_OBJBGRND; i++ )
	{
		if( m_objectsBgnd[i] == NULL )
		{
			m_objectsBgnd[i] = object;
			return object;
		}
	}
	return NULL;
}

GameObject* Game::createObject( GameObjectType type, float x, float y )
{
	// Find free pointer and create object
	for( int i = 0; i < MAX_OBJ; i++ )
	{	
		if( m_objects[i] == NULL )
		{
			GameObject* object = NULL;
			
			switch( type )
			{
				case GameObjectType_Wall:			object = new Wall();			break;
				case GameObjectType_BaseEnemy:		object = new BaseEnemy();		break;
				case GameObjectType_Bullet:			object = new Bullet();			break;
				case GameObjectType_TankPlayer:		object = new TankPlayer();		break;
				case GameObjectType_TankEnemy:		object = new TankEnemy();		break;
				case GameObjectType_TankGun:		object = new TankGun();			break;
				case GameObjectType_Fire:			object = new Fire();			break;
				case GameObjectType_Box:			object = new Box();				break;
			}

			if( object == NULL )
				return NULL;

			object->setGame( this );


			if( moveObjectTo( object, x, y ) == false )
			{
				delete object;
				return NULL;
			}
			
			m_objects[i] = object;

			return object;
		}
	}

	return NULL;
}

void Game::destroyObject( GameObject* object )
{
	for( int i = 0; i < MAX_OBJ; i++ )
	{	
		if( m_objects[i] == object )
		{
			delete m_objects[i];
			m_objects[i] = 0;

			return;
		}
	}
}

void Game::increaseDiedEnemiesCount()
{
	m_diedEnemiesCount++;
}

 void Game::levelUP()
 {
	  m_levelNumber++;
 }


void Game::setOffSets( GameObject * object )
{
	if( object->getX() > WINDOW_X / 2 / TILE_SIZE && object->getX() < COLUMNS - WINDOW_X / 2 / TILE_SIZE - 1.5 )
		m_offSetX = object->getX() - WINDOW_X / 2 / TILE_SIZE;
	if( object->getY() > WINDOW_Y / 2 / TILE_SIZE && object->getY() < ROWS - WINDOW_Y / 2 / TILE_SIZE - 1.5 )
		m_offSetY = object->getY() - WINDOW_Y / 2 / TILE_SIZE - 1.0;
}

int Game::getAngleMouseToObject( GameObject * object )
{
	float dX = mousePixelPos.x - (object->getX() - getOffSetX()) * TILE_SIZE;
	float dY = mousePixelPos.y - (object->getY() - getOffSetY()) * TILE_SIZE;

	return (int)(atan2( dY, dX ) * (180 / 3.14159265));
}