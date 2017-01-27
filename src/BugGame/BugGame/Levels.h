////////////////////////////////////
// Levels
//
// Author: Triold
//
// **.01.17
////////////////////////////////////

#pragma once
 extern sf::Texture* TextureAtlas;

	const int LevelsCount = LEVELS;
	const int LevelLayers = 2;
	const int LevelRows = ROWS;
	const int LevelColumns = COLUMNS;

	const unsigned char LevelsData[LevelsCount][LevelLayers][LevelRows][LevelColumns + 1] = { 0 };

