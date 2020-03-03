#include "ScriptComponent.h"
#include <iostream>


ScriptComponent::ScriptComponent(GameObject& obj) :
	BaseComponent(obj)
{
	componentName = "ScriptComponent";

}


ScriptComponent::~ScriptComponent()
{

}



void ScriptComponent::loadScript(std::string _fileName, sol::state & _luaPlus)
{
	_luaPlus.script_file(_fileName);
}

void ScriptComponent::Update(float timeDelta)
{

}

