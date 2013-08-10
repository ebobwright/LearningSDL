#ifndef _POSITION_
#define _POSITION_ 
#pragma once
/*******************************************************
*File:		Position.h
*Author:	E. Bob Wright
*Date:		08/09/2013
*Notes:		
*******************************************************/
class Position : public Component
{
public:
	static const int familyId = 1;	
	glm::vec3 PositionVector;
};

#endif