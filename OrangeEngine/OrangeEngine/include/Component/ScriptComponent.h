#ifndef SCRIPT_COMPONENT_H
#define SCRIPT_COMPONENT_H

#include "../Manager/ComponentManager.h"
#include "../Utility/Util.h"
#include "BaseComponent.h"
#include <luaPlus.h>
#include "../sol/sol.hpp"

class ComponentManager;
class BaseComponent;
using namespace LuaPlus;

class ScriptComponent : public BaseComponent
{
public:
	//ScriptComponent();
	ScriptComponent(ComponentManager& obj);
	~ScriptComponent(void);

	void loadScriptFile(std::string _fileName, sol::state &_lua);

	virtual void Update(float dt);
	bool fileLoaded = false;
	sol::state lua;
private:
	std::vector<ComponentManager*>* obj;
	LuaState* pLuaState;
};

#endif // !ScriptComponent_H