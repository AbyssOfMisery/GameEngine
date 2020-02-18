#include "ScriptComponent.h"



ScriptComponent::ScriptComponent(ComponentManager& obj) : BaseComponent(obj)
{

}


ScriptComponent::~ScriptComponent()
{

}

void ScriptComponent::loadScriptFile(std::string _path)
{
	pLuaState->DoFile(_path.c_str());

}

void ScriptComponent::Update(float timeDelta)
{
	LuaObject table = pLuaState->GetGlobals().GetByName("ComponentManager");
	for (LuaTableIterator it(table); it; it.Next())
	{
		LuaObject key = it.GetKey();
		LuaObject value = it.GetValue();
	}
}

