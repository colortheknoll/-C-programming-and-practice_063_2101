#pragma once

#include "Block.h"
#include "Board.h"


int block_list[7][4][4][2] = {
	//O미노 : 1
	{ { {0,0},{1,0},{0,1},{1,1} }, 
	{ {0,0},{1,0},{0,1},{1,1} }, 
	{ {0,0},{1,0},{0,1},{1,1} }, 
	{ {0,0},{1,0},{0,1},{1,1} } },
	//I미노 : 2
	{ { {0,0},{1,0},{2,0},{3,0} }, 
	{ {0,0},{0,1},{0,2},{0,3} }, 
	{ {0,0},{1,0},{2,0},{3,0} }, 
	{ {0,0},{0,1},{0,2},{0,3} } },
	//Z미노 : 3
	{ { {0,0},{0,1},{1,1},{1,2} }, 
	{ {1,0},{0,1},{1,1},{2,0} }, 
	{ {0,0},{0,1},{1,1},{1,2} }, 
	{ {1,0},{0,1},{1,1},{2,0} } },
	//S미노 : 4
	{ { {0,1},{1,0},{1,1},{0,2} }, 
	{ {0,0},{1,0},{1,1},{2,1} }, 
	{ {0,1},{1,0},{1,1},{0,2} }, 
	{ {0,0},{1,0},{1,1},{2,1} } },
	//J미노 : 5
	{ { {0,1},{1,1},{2,1},{2,0} }, 
	{ {0,0},{1,0},{1,1},{1,2} }, 
	{ {0,0},{1,0},{0,1},{2,0} }, 
	{ {0,0},{0,1},{0,2},{1,2} } },
	//L미노 : 6
	{ { {0,0},{1,0},{2,0},{2,1} }, 
	{ {0,0},{0,1},{1,0},{0,2} }, 
	{ {0,0},{0,1},{1,1},{2,1} }, 
	{ {1,0},{1,1},{1,2},{0,2} } },
	//T미노 : 7
	{ { {1,0},{0,1},{1,1},{1,2} }, 
	{ {0,0},{1,0},{2,0},{1,1} }, 
	{ {0,0},{0,1},{0,2},{1,1} }, 
	{ {1,0},{0,1},{1,1},{2,1} } },
};

    
bool Block::can_place_on_board()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		if (0 != board->board_status(ny, nx)) return false;
	}
	
	return true;
}

void Block::draw_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->draw_board(ny, nx);
	}
}

void Block::erase_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->erase_board(ny, nx);
	}
}

void Block::move_down()
{	
	erase_block();
	this->y += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->y -= 1;
		Block::stop = true;
	}
}

void Block::move_left()
{
	erase_block();
	this->x -= 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x += 1;
		draw_block();
	}
}

void Block::move_right()
{
	erase_block();
	this->x += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x -= 1;
		draw_block();
	}
}
