#include "ScriptComponent.h"
#include <iostream>


ScriptComponent::ScriptComponent(std::string _fileName, sol::state &_luaPlus, GameObject& obj) :
	BaseComponent(obj)
{
	componentName = "ScriptComponent";
	_luaPlus.script_file(_fileName);
}


ScriptComponent::~ScriptComponent()
{

}



void ScriptComponent::Update(float timeDelta)
{

}

