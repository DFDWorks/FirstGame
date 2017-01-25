#pragma once

#include "LibsAndConstants.h"
#include "GameObject.h"

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

	Button* createButton( ButtonType type );
	Background* createBgrndObject( BackgroundType type, float x, float y );
	GameObject* createObject( GameObjectType type, float x, float y );
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

	Menu* m_menu;
	bool m_isMenuActive;

	bool m_isSoundActive;

	GameObject* m_player;
	GameObject* m_BaseEnemy;
	GameObject* m_objects[MAX_OBJ];

	Background* m_objectsBgnd[MAX_OBJBGRND];

	int m_diedEnemiesCount;

private:
	float m_offSetX;			//привязка "камеры" к обьекту
	float m_offSetY;

	
	Button* m_buttons[MAX_BAR_BUTT];
	int m_btn_obj;
	int m_btn_fps;
	int m_btn_lvl;
	int m_btn_hpP;
	int m_btn_hpE;
	void textValueButton();

public:	
	sf::Vector2i mousePixelPos;	//координаты мыши


	void setOffSets(GameObject * object);
	float getOffSetX(){ return m_offSetX; }
	float getOffSetY(){ return m_offSetY; }

	int getAngleMouseToObject(GameObject * object);
};