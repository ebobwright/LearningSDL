#pragma once
class Camera: public Component
{
public:	
	static const int familyId = 3;	

	bool ActiveCamera;
	glm::vec3 CameraPosition;
};

