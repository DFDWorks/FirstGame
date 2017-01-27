#pragma once

#include "LibsAndConstants.h"
#include "GameObject.h"

enum GameObjectType;
class GameObject;

class Game
{
public:
	Game();
	~Game();

	void setupSystem();
	void initialize();
	bool loop();
	void shutdown();

	void setGameActive( bool isActive ) { m_isGameActive = isActive; }
	void setMenuActive( bool isActive ) { m_isMenuActive = isActive; }
	void setSoundActive( bool isActive ) { m_isSoundActive = isActive; }
	bool getSoundActive() { return m_isSoundActive; }

	GameObject* createObject( GameObjectType type, float x, float y );	//Блок манипуляции обьектами
	void destroyObject( GameObject* object );
	GameObject* checkIntersects( float x, float y, float width, float height, GameObject* exceptObject );
	bool moveObjectTo( GameObject* object, float x, float y );
	int getObjectsCount( GameObjectType type );

	int getDiedEnemiesCount(){ return m_diedEnemiesCount; }
	void increaseDiedEnemiesCount();

	int getLevelNumber(){return m_levelNumber; }
	void levelUP();

private:
	void render();
	void update( float dt );

private:
	bool m_isGameActive;
	int m_levelNumber;
	
	clock_t m_clockLastFrame;
	float m_clockFpsUpdate;
	int m_fps;

	sf::RenderWindow* m_renderWindow;

	bool m_isMenuActive;
	bool m_isSoundActive;

	GameObject* m_player;
	GameObject* m_objects[MAX_OBJ];

	int m_diedEnemiesCount;

private:
	float m_offSetX;			//привязка "камеры" к обьекту
	float m_offSetY;

	int m_btn_obj;				//Различные игровые счетчики
	int m_btn_fps;
	int m_btn_lvl;
	int m_btn_hpP;
	int m_btn_hpE;

public:	
	sf::Vector2i mousePixelPos;	//координаты мыши


	void setOffSets(GameObject * object);			//привязка "камеры" к обьекту
	float getOffSetX(){ return m_offSetX; }
	float getOffSetY(){ return m_offSetY; }

	int getAngleMouseToObject(GameObject * object);	//Угол мышь-обьект (для управления мишью)
};