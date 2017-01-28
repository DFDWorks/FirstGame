////////////////////////////////////
// Game
//
// Author: Triold
//
// **.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "LibsAndConstants.h"
#include "Game.h"
#include "Improvements.h"
#include "Levels.h"

	


sf::Texture* TextureAtlas = NULL;

////////////////////////////////////
Game::Game()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;
	m_fps = 0;
	m_clockFpsUpdate = 1.0;

	m_isMenuActive = true;

	m_player = NULL;
	for (S32 i = 0; i < MAX_OBJ; i++)
		m_objects[i] = NULL;

	m_renderWindow = NULL;

	m_levelNumber = 0;

	m_offSetX = m_offSetY = 0;

	m_btn_obj = m_btn_fps = m_btn_lvl = m_btn_hpP = m_btn_hpE = 0;
}

////////////////////////////////////
Game::~Game()
{
	if (TextureAtlas)
		delete TextureAtlas;

	if (m_renderWindow)
		delete m_renderWindow;
}

////////////////////////////////////
void Game::setupSystem()
{
	srand(time(0));

	m_renderWindow = new sf::RenderWindow(
		sf::VideoMode(WINDOW_X, WINDOW_Y, 32),
		"Bla-bla-bla",
		sf::Style::Titlebar | sf::Style::Close);

	TextureAtlas = new sf::Texture();
	TextureAtlas->loadFromFile("bug.png");
}

////////////////////////////////////
void Game::initialize()
{
	shutdown();

	S32 l = getLevelNumber();
	m_btn_lvl = l + 1;

	// Load level

	for (S32 r = 0; r < LevelRows; r++)
		for (S32 c = 0; c < LevelColumns; c++)
		{
			unsigned char cellSymbol = LevelsData[l][1][r][c];

			switch (cellSymbol)
			{
			}

		}

	for (S32 r = 0; r < LevelRows; r++)
	{
		for (S32 c = 0; c < LevelColumns; c++)
		{
			unsigned char cellSymbol = LevelsData[l][0][r][c];

			switch (cellSymbol)
			{
			}
		}
	}
}

////////////////////////////////////
bool Game::loop()
{
	if (!m_renderWindow->isOpen())
		return false;

	// Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	F32 deltaTime = F32(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;


	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_renderWindow->close();
	}

	render();
	update(deltaTime);

	m_clockFpsUpdate -= deltaTime;
	if (m_clockFpsUpdate > 0)
		m_fps++;
	else
	{
		m_btn_fps = m_fps;
		m_fps = 0;
		m_clockFpsUpdate = 1.0;
	}

	S32 ping = 25 - deltaTime * 1000;
	if (ping < 0) ping = 0;
	//	Sleep( ping );

	return m_isGameActive;


}

////////////////////////////////////
void Game::shutdown()
{
	for (S32 i = 0; i < MAX_OBJ; i++)
		if (m_objects[i] != 0)
		{
			delete m_objects[i];
			m_objects[i] = 0;
		}
}

////////////////////////////////////
void Game::render()
{
	// Start frame
	m_renderWindow->clear(sf::Color::Black);

	// Deaw all game objects

	m_btn_obj = 0;
	for (S32 i = 0; i < MAX_OBJ; i++)
		if (m_objects[i] != NULL)
		{
			m_objects[i]->render(m_renderWindow);
			m_btn_obj++;
		}

	// End frame
	m_renderWindow->display();
}

////////////////////////////////////
void Game::update(F32 dt)
{
	mousePixelPos = sf::Mouse::getPosition(*m_renderWindow);

	if (m_isMenuActive)
	{
	}
	else
	{
		for (S32 i = 0; i < MAX_OBJ; i++)
			if (m_objects[i] != 0)
			{
				m_objects[i]->update(dt);

				if (m_objects[i]->getHealth() <= 0 && m_objects[i]->getDestroyAfterDeath())
					destroyObject(m_objects[i]);
			}

		m_btn_hpP = m_player->getHealth();

		// Player destroyed
		if (m_player && m_player->getHealth() <= 0)
			initialize();
	}

	//	prS32f("%f, %f, %f, %f\n",F32(mousePixelPos.x), F32(mousePixelPos.y), m_offSetX*TILE_SIZE, m_offSetY*TILE_SIZE);
}

////////////////////////////////////
GameObject* Game::checkIntersects(F32 x, F32 y, F32 width, F32 height, GameObject* exceptObject)
{
	F32 passing = 1.4;

	F32 x0 = x;
	F32 y0 = y;

	F32 x1;
	F32 y1;

	F32 minDistance;
	F32 realDistance;

	for (S32 i = 0; i < MAX_OBJ; i++)
		if (m_objects[i] != 0 && m_objects[i]->getPhysical() && m_objects[i] != exceptObject)
		{
			x1 = m_objects[i]->getX();
			y1 = m_objects[i]->getY();

			minDistance = (width + (F32)m_objects[i]->getWidth()) / 2;			//Реализация только для квадратных плиток!
			realDistance = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)) * passing;

			if (realDistance < minDistance)
			{
				return m_objects[i];
			}

		}

	return NULL;
}

////////////////////////////////////
bool Game::moveObjectTo(GameObject* object, F32 x, F32 y)
{
	bool canMoveToCell = false;



	return canMoveToCell;
}

////////////////////////////////////
S32 Game::getObjectsCount(GameObjectType type)
{
	S32 totalCount = 0;

	for (S32 i = 0; i < MAX_OBJ; i++)
	{
		if (m_objects[i] == 0)
			continue;

		if (m_objects[i]->getType() == type)
			totalCount++;
	}

	return totalCount;
}

////////////////////////////////////
GameObject* Game::createObject(GameObjectType type, F32 x, F32 y)
{
	// Find free pointer and create object
	for (S32 i = 0; i < MAX_OBJ; i++)
	{
		if (m_objects[i] == NULL)
		{
			GameObject* object = NULL;

			switch (type)
			{
			}

			if (object == NULL)
				return NULL;

			object->setGame(this);


			if (moveObjectTo(object, x, y) == false)
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

////////////////////////////////////
void Game::destroyObject(GameObject* object)
{
	for (S32 i = 0; i < MAX_OBJ; i++)
	{
		if (m_objects[i] == object)
		{
			delete m_objects[i];
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
void Game::setOffSets(GameObject * object)
{
	if (object->getX() > WINDOW_X / 2 / TILE_SIZE && object->getX() < COLUMNS - WINDOW_X / 2 / TILE_SIZE - 1.5)
		m_offSetX = object->getX() - WINDOW_X / 2 / TILE_SIZE;
	if (object->getY() > WINDOW_Y / 2 / TILE_SIZE && object->getY() < ROWS - WINDOW_Y / 2 / TILE_SIZE - 1.5)
		m_offSetY = object->getY() - WINDOW_Y / 2 / TILE_SIZE - 1.0;
}

////////////////////////////////////
S32 Game::getAngleMouseToObject(GameObject * object)
{
	F32 dX = mousePixelPos.x - (object->getX() - getOffSetX()) * TILE_SIZE;
	F32 dY = mousePixelPos.y - (object->getY() - getOffSetY()) * TILE_SIZE;

	return (S32)(atan2(dY, dX) * (180 / 3.14159265));
}
