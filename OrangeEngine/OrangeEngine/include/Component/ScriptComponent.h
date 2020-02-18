#ifndef SCRIPT_COMPONENT_H
#define SCRIPT_COMPONENT_H

#include "../Manager/ComponentManager.h"
#include "../Utility/Util.h"
#include "BaseComponent.h"
#include <luaPlus.h>

class ComponentManager;

using namespace LuaPlus;

class ScriptComponent : public BaseComponent
{
public:
	ScriptComponent(ComponentManager& obj);
	~ScriptComponent();
	void loadScriptFile(std::string _path);
	void Update(float timeDelta);
private:
	std::vector<ComponentManager*>* obj;
	LuaState* pLuaState;
};

#endif // !ScriptComponent_H