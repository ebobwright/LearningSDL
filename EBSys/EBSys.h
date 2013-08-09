// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ENTITYSYSTEM_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ENTITYSYSTEM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef EBSYS_EXPORTS
#define ENTITYSYSTEM_API __declspec(dllexport)
#else
#define ENTITYSYSTEM_API __declspec(dllimport)
#endif

#include <string>
#include <map>
#include <set>
#include <vector>

#include "BaseSystem.h"
#include "Component.h"
#include "Entity.h"
#include "EntitySystem.h"
