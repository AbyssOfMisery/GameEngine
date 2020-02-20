#include "ScriptComponent.h"
#include <iostream>


ScriptComponent::ScriptComponent(ComponentManager& obj) :
	BaseComponent(obj)
{
	pLuaState = LuaState::Create();

}

ScriptComponent::~ScriptComponent()
{
	LuaPlus::LuaState::Destroy(pLuaState);
	pLuaState = nullptr;
}

void ScriptComponent::loadScriptFile(char* _path)
{

	pLuaState -> DoFile(_path);
}

void ScriptComponent::Update(float timeDelta)
{

	/* use LuaCall */
	pLuaState->DoString("function Add(x, y) return x + y end");
	//LuaFunction<float> AddFunc(state, "Add");
	//printf("Add: %f\n", AddFunc(2, 7));
	LuaObject addObj = pLuaState->GetGlobal("Add");
	LuaCall addCall = addObj;
	LuaObject retAddObj = addCall << 2 << 7 << LuaRun();
	printf("Add:%d\n", retAddObj.GetInteger());

	pLuaState->DoString("function PrintImp(str) print(str) end");
	//LuaFunction<void> PrintFunc(state, "PrintImp");
	//PrintFunc("Hello World!");
	LuaObject printObj = pLuaState->GetGlobal("PrintImp");
	LuaCall printCall = printObj;
}

