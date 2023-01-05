//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *               App Header             *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************----------------------------------*/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

  My Header Template


*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HEADER_HPP
#define HEADER_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "raylib.h"
#include "raymath.h"        // Required for: Vector2Clamp()

#include <iostream>		// For debugging purposes
#include <string>
#include <vector>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	        Global Variables          *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************----------------------------------*/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*------------------------------
 |                             |
 |  Instance state enumerator  |
 |                             |
 ------------------------------*/
const enum INST_TYPE { QUEST = 0, MONSTER, DIRECTION, PLACE, FIGHT, WON, MENU, EXIT_MENU };

/*--------------------------------
 |                               |
 |  Instance returns enumerator  |
 |                               |
 --------------------------------*/
const enum INST_RESULTS
{
	CONTINUE,
	RIGHT, LEFT,
	ACCEPT, REJECT,
	BTN1_PRESSED, BTN2_PRESSED,
	PLAYER_DEAD, MONSTER_DEAD,
	PLAYER_HITS, MONSTER_HITS,
	PLAYER_MISS, MONSTER_MISS,
};


/*------------------------------
 |                             |
 |  Player state enumerator    |
 |                             |
 ------------------------------*/
const enum PLAYER_STATE { HEALTH = 0, ARMOR, STRENGTH };

/*----------------------------
 |                           |
 |  Buttons type enumerator  |
 |                           |
 ----------------------------*/
const enum BTN_TYPE { CONTINUE_BTN = 0, FIGHT_BTN, RIGHT_BTN, LEFT_BTN, ROLL_BTN, ACCEPT_BTN, REJECT_BTN };

/*------------------------------
 |                             |
 |  Window size enumerator    |
 |                             |
 ------------------------------*/
const enum ORIGINAL_WINDOW_SIZE { O_WIN_WD = 1279, O_WIN_HT = 713 };


/*------------------------------
 |                             |
 |  Window size enumerator    |
 |                             |
 ------------------------------*/
const enum ORIGINAL_BTN_SIZE { O_BTN_WD = 1496, O_BTN_HT = 602 };


#endif
