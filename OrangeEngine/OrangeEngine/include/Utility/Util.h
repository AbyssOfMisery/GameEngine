#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Box2D/Box2D.h>


constexpr char* WINDOW_TITLE = { "OrangeEngine" };
constexpr unsigned int WINDOW_WIDTH = { 800 };
constexpr unsigned int WINDOW_HEIGHT = { 600 };

constexpr float FPS{ 60.0f };
constexpr float ANIMATION_SPEED{ 12.0f };

constexpr float WALK_ACCELERATION{ 500.0f };
constexpr int TEXT_SIZE_FOR_TILE{ 10 };

/************ Physics Settings ************/
constexpr float PIXEL_PER_METER{ 32.0f };
constexpr float32 TIME_STEP{ 1.0f / FPS }; //the length of time passed to simulate (seconds)
constexpr int32 VELOCITY_ITERATIONS{ 6 };   //how strongly to correct velocity
constexpr int32 POSITION_ITERATIONS{ 2 };   //how strongly to correct position


/* Collision body identifiers */
constexpr char* DOOR_LOCKED{ "DOOR_LOCKED" };
constexpr char* DOOR_UNLOCKED{ "DOOR_UNLOCKED" };

/* A quick function to create a physics body */
b2Body* CreatePhysicsBody(b2World& world,
	sf::Vector2f position,
	sf::Vector2f size = { 0.45f, 0.45f },
	b2BodyType type = b2_staticBody,
	sf::Vector2f offset = { 0,0 });

#endif // !UTIL_H
