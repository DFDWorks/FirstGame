////////////////////////////////////
// Libraries
//
// Author: Triold
//
// 29.01.17
////////////////////////////////////



#pragma once

#include <clocale>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#define MAX_OBJ 1024

#define TILE_SIZE 64

#define ROWS 30
#define COLUMNS 52
#define LEVELS 3

#define WINDOW_X 800
#define WINDOW_Y 600

#define BAR_Y 1
#define MAX_BAR_BUTT 7

#define MAX_MENU_BUTT 4
#define BREAK_IF( condition ) if( condition ) { __asm { int 3 } }
#define STATIC_POINTER_CAST	std::tr1::static_pointer_cast
