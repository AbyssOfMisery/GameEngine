#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../Utility/Util.h"
#include "../RenderWindow/Window.h"

class SceneManager {
public:
	SceneManager(std::shared_ptr<Window> windowptr) : m_window(windowptr) {}
	virtual ~SceneManager() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RestartClock() = 0;

protected:
	std::shared_ptr<Window> m_window;
};

#endif // !SCENE_HPP
