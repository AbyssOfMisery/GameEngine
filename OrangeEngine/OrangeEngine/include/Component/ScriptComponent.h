#ifndef SCRIPT_COMPONENT_H
#define SCRIPT_COMPONENT_H

#include "../Manager/ComponentManager.h"
#include "../Utility/Util.h"
#include <luaPlus.h>

class ComponentManager;

using namespace LuaPlus;

class ScriptComponent 
{
public:
	ScriptComponent();
	~ScriptComponent();
	void loadScriptFile(std::string _path);
	void Update(ComponentManager& obj);
private:
	std::vector<ComponentManager*>* obj;
	LuaState* pLuaState;
};

#endif // !ScriptComponent_H