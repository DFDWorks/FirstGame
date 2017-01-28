////////////////////////////////////
// Levels
//
// Author: TRiOLD
//
// 29.01.17
////////////////////////////////////

#pragma once
 extern sf::Texture* TextureAtlas;

const int LevelsCount = LEVELS;
const int LevelLayers = 2;
const int LevelRows = ROWS;
const int LevelColumns = COLUMNS;

const unsigned char LevelsData[LevelsCount][LevelLayers][LevelRows][LevelColumns + 1] = { 0 };


////////////////////////////////////
const float kCockroachRotSpeed = 0.2;
const float kCockroachColumns = 7.8125;
const float kCockroachRows = 6;

const sf::IntRect kCockroachImage = sf::IntRect( 0*TILE_SIZE, 0*TILE_SIZE, kCockroachColumns*TILE_SIZE, kCockroachRows*TILE_SIZE );