#include "Piece.h"

Piece::Piece(int texturePositionX, int texturePositionY, int value, bool color, 
			 bool movesDiagonaly, bool movesHorizonatly, bool movesVertically, int range)

	: mTextureFile {"C:/Users/Timmy/source/repos/ChessTwo/assets/pieces.png"}, 
	mTextureWidth {334}, mTextureHeight {334}, mTexturePositionX {texturePositionX}, 
	mTexturePositionY {texturePositionY}, mValue {value}, mColor {color}, movesDiagonaly {movesDiagonaly},
	movesHorizontaly {movesHorizonatly}, movesVertically {movesVertically}, mRange {range} {

}