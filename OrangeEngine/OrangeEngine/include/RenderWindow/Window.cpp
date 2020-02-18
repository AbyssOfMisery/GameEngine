#include "Window.h"
#include "imgui.h"
#include "imgui-SFML.h"

Window::Window() { Setup(); }
Window::~Window() { Destroy(); }

void Window::Setup() {
	m_windowTitle = WINDOW_TITLE;
	m_windowSize = { WINDOW_WIDTH, WINDOW_HEIGHT };
	m_isFullscreen = false;
	m_isDone = false;
	m_isDebug = true;
	m_views[static_cast<int>(VIEW::MAIN)] = sf::View({ 0,0 }, { (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	m_views[static_cast<int>(VIEW::UI)] = sf::View({ 0,0 }, { (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	m_views[static_cast<int>(VIEW::DEBUG)] = sf::View({ 0,0 }, { (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	m_views[static_cast<int>(VIEW::DEBUG)].zoom(1.7f);
	m_currentView = VIEW::MAIN;
	SplashScreen();
}

void Window::SplashScreen() {
	sf::Texture logo;

	if (!logo.loadFromFile("resource/images/SplashScreen.png")) {
		exit(1);
	}

	sf::Sprite sp;
	sp.setTexture(logo);
	sp.scale(1, 1); // My logo is quite big in fact (1st google result btw)
	int logoWidth = sp.getGlobalBounds().width;
	int logoHeight = sp.getGlobalBounds().height;

	// With the logo loaded, I know its size, so i create the window accordingly
	sf::RenderWindow window(sf::VideoMode(logoWidth, logoHeight), "SFML", sf::Style::None); // <- Important!! Style=None removes title

	// To close splash window by timeout, I just suppose you want something like this, don't you?
	sf::Clock timer;
	sf::Time time = timer.restart();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// event loop is always needed
		}
		// Window closed by time
		time += timer.restart();
		if (time >= sf::seconds(2.f)) {
			window.close();
		}

		window.clear();
		window.draw(sp);
		window.display();
	}
	Create();
}

void Window::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
	m_window.setView(m_views[static_cast<int>(VIEW::MAIN)]);
}

void Window::Destroy() {
	m_window.close();
}

void Window::BeginDraw() { m_window.clear(sf::Color::Black); }
void Window::Draw(sf::Drawable &drawable) { m_window.draw(drawable); }
void Window::EndDraw() { m_window.display(); }

void Window::MoveView(sf::Vector2f position) {
	if (m_isDebug) m_currentView = VIEW::DEBUG;
	else m_currentView = VIEW::MAIN;
	m_views[static_cast<int>(m_currentView)].setCenter(position);
	m_window.setView(m_views[static_cast<int>(m_currentView)]);
}

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
bool Window::IsDebug() { return m_isDebug; }

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void Window::Update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		ImGui::SFML::ProcessEvent(event);
		if (event.type == sf::Event::Closed) { m_isDone = true; }
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { m_isDone = true; }
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) { ToggleFullscreen(); }
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) { m_isDebug = !m_isDebug; }
		else if (event.type == sf::Event::Resized) {
			m_views[static_cast<int>(m_currentView)].reset(sf::FloatRect(0.0f, 0.0f, event.size.width, event.size.height));
			m_window.setView(m_views[static_cast<int>(m_currentView)]);
		}
	}
}