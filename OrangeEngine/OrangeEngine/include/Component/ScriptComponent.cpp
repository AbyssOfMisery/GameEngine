#include "ScriptComponent.h"



ScriptComponent::ScriptComponent(ComponentManager& obj) : 
	BaseComponent(obj)
{
	
}


ScriptComponent::~ScriptComponent()
{

}

void ScriptComponent::loadScriptFile(char* _path)
{

	int iret = pLuaState->DoFile(_path);
}

void ScriptComponent::Update(float timeDelta)
{
	if (!IsActive()) return;
	LuaObject table = pLuaState->GetGlobals().GetByName("ScriptComponent");
	for (LuaTableIterator it(table); it; it.Next())
	{
		LuaObject key = it.GetKey();
		LuaObject value = it.GetValue();
	}
}

