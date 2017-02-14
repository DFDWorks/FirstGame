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

const std::string Map[80] = {
	"mmmmmmmmmmmmmmmmmmmmmmmmm",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                        ",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m                       m",
	"m      m        s       m",
	"m      m     mmmmmm     m",
	"m      m    m           m",
	"m      ms   m s mmmmmm  m",
	"mmmmmmmmmmmmmmmmmmmmmmmmm"
};

////////////////////////////////////
const float kCockroachRotSpeed = 0.2f;
const float kCockroachColumns = 7.8125f;
const float kCockroachRows = 6.0f;

const sf::IntRect kCockroachImage = sf::IntRect( 0.0f *TILE_SIZE, 0.0f * TILE_SIZE, kCockroachColumns * TILE_SIZE, kCockroachRows * TILE_SIZE );
const sf::IntRect kDorImage = sf::IntRect( 0*TILE_SIZE, 0*TILE_SIZE, 464, 315 );
