#include "ScriptComponent.h"



ScriptComponent::ScriptComponent(ComponentManager& obj) : 
	BaseComponent(obj)
{
	pLuaState = LuaPlus::LuaState::Create(true);

}



ScriptComponent::~ScriptComponent()
{
	if (pLuaState)
	{
		LuaPlus::LuaState::Destroy(pLuaState);
		pLuaState = NULL;
	}
}

void ScriptComponent::loadScriptFile(std::string _fileName, sol::state &_lua)
{
	_lua.script_file(_fileName);
}

void ScriptComponent::Update(float timeDelta)
{

	
}

