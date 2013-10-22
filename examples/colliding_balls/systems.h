/*
 * Copyright (c) 2013, Julien Bernard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <es/GlobalSystem.h>
#include <es/Manager.h>

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include "components.h"

class Input : public es::GlobalSystem {
public:
  Input(es::Manager *manager, sf::RenderWindow *window, b2World *world)
    : GlobalSystem(1, {  }, manager)
    , m_window(window)
    , m_world(world)
  { }

  virtual void preUpdate() override;

private:
  sf::RenderWindow *m_window;
  b2World *m_world;
};

class Physics : public es::GlobalSystem {
public:
  Physics(es::Manager *manager, b2World *world)
    : GlobalSystem(2, { Body::type }, manager)
    , m_world(world)
  { }

  virtual void init() override;
  virtual void update(float delta) override;
  virtual void updateEntity(float delta, es::Entity e) override;

private:
  b2World *m_world;
};

class Graphics : public es::GlobalSystem {
public:
  Graphics(es::Manager *manager)
    : GlobalSystem(3, { Body::type, Coords::type }, manager)
  { }

  virtual void updateEntity(float delta, es::Entity e) override;

};

class Render : public es::GlobalSystem {
public:
  Render(es::Manager *manager, sf::RenderWindow *window)
    : GlobalSystem(4, { Coords::type, Look::type }, manager)
    , m_window(window)
  { }

  virtual void preUpdate() override;
  virtual void updateEntity(float delta, es::Entity e) override;
  virtual void postUpdate() override;

private:
  sf::RenderWindow *m_window;
};

#endif // SYSTEMS_H
