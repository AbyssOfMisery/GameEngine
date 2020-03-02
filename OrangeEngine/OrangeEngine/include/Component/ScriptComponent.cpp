#include "ScriptComponent.h"
#include <iostream>


ScriptComponent::ScriptComponent(ComponentManager& obj) :
	BaseComponent(obj)
{
	pLuaState = LuaPlus::LuaState::Create(true);

}


ScriptComponent::~ScriptComponent()
{

}



void ScriptComponent::Update(float timeDelta)
{

}

