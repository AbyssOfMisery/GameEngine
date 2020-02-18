#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../Utility/Util.h"
#include "../RenderWindow/Window.h"

class SceneManager {
public:
	SceneManager(std::shared_ptr<Window> windowptr) : m_window(windowptr), m_changeScene(false), m_isDone(false) {}
	virtual ~SceneManager() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void RestartClock() = 0;

	bool IsChangeScene() { return m_changeScene; }
	void SetChangeScene(bool change) { m_changeScene = change; }

	bool IsDone() { return m_isDone || m_window->IsDone(); }
	void Exit() { m_isDone = true; }

protected:
	std::shared_ptr<Window> m_window;

	bool m_changeScene;
	bool m_isDone;

};

#endif // !SCENE_HPP
