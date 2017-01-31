////////////////////////////////////
// Game
//
// Author: TRiOLD
//
// 29.01.17
////////////////////////////////////

#pragma once
////////////////////////////////////
// Includes
#include "Improvements.h"
#include "LibsAndConstants.h"
#include "GameObject.h"

enum GameObjectType;
class GameObject;
PTR(Label);
PTR(GameHUD);

class Game
{
public:

	////////////////////////////////////
	Game();

	////////////////////////////////////
	~Game();

	////////////////////////////////////
	void setupSystem();

	////////////////////////////////////
	void initialize();

	////////////////////////////////////
	bool loop();

	////////////////////////////////////
	void shutdown();

	////////////////////////////////////
	void setGameActive(bool isActive) { m_isGameActive = isActive; }

	////////////////////////////////////
	void setMenuActive(bool isActive) { m_isMenuActive = isActive; }

	////////////////////////////////////
	void setSoundActive(bool isActive) { m_isSoundActive = isActive; }

	////////////////////////////////////
	bool getSoundActive() { return m_isSoundActive; }

	////////////////////////////////////
	GameObject* createObject(GameObjectType type, F32 x, F32 y);

	////////////////////////////////////
	void destroyObject(GameObject* object);

	////////////////////////////////////
	GameObject* checkIntersects(F32 x, F32 y, F32 width, F32 height, GameObject* exceptObject);

	////////////////////////////////////
	bool moveObjectTo(GameObject* object, F32 x, F32 y);

	////////////////////////////////////
	S32 getObjectsCount(GameObjectType type);

	////////////////////////////////////
	S32 getDiedEnemiesCount(){ return m_diedEnemiesCount; }

	////////////////////////////////////
	void increaseDiedEnemiesCount();

	////////////////////////////////////
	S32 getLevelNumber(){ return m_levelNumber; }

	////////////////////////////////////
	void levelUP();

private:

	////////////////////////////////////
	void render();

	////////////////////////////////////
	void update(F32 dt);

private:
	bool m_isGameActive;
	S32 m_levelNumber;

	clock_t m_clockLastFrame;
	F32 m_clockFpsUpdate;
	S32 m_fps;

	sf::RenderWindow* m_renderWindow;

	bool m_isMenuActive;
	bool m_isSoundActive;

	GameObject* m_player;
	GameObject* m_objects[MAX_OBJ];
	GameHUDPtr m_hud;

	S32 m_diedEnemiesCount;

private:
	F32 m_offSetX;
	F32 m_offSetY;

	S32 m_btn_obj;
	S32 m_btn_fps;
	S32 m_btn_lvl;
	S32 m_btn_hpP;
	S32 m_btn_hpE;

public:
	sf::Vector2i mousePixelPos;


	void setOffSets(GameObject * object);
	F32 getOffSetX(){ return m_offSetX; }
	F32 getOffSetY(){ return m_offSetY; }

	S32 getAngleMouseToObject(GameObject * object);
};
