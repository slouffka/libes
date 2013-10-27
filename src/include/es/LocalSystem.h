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
#ifndef ES_LOCAL_SYSTEM_H
#define ES_LOCAL_SYSTEM_H

#include <cassert>
#include <vector>

#include "System.h"
#include "Entity.h"

namespace es {

  class LocalSystem : public System {
  public:

    LocalSystem(int priority, std::set<ComponentType> needed, Manager *manager, int width, int height)
      : System(priority, needed, manager), m_width(width), m_height(height), m_x(0), m_y(0), m_entities(width * height)
    {
      assert(width > 0);
      assert(height > 0);
    }

    virtual void update(float delta);

    void reset(int width, int height);

    /**
     * @brief Set the focus for local systems.
     *
     * @param x the x-coordinate of the focus
     * @param y the y-coordinate of the focus
     */
    void setFocus(int x, int y) {
      m_x = x;
      m_y = y;
    }

    bool addLocalEntity(Entity e, int x, int y);

    bool removeLocalEntity(Entity e, int x, int y);

  protected:
    const std::set<Entity> getEntities() const;

  private:
    int getIndex(int x, int y) const {
      return y * m_width + x;
    }

    int m_width;
    int m_height;

    int m_x;
    int m_y;

    std::vector<std::set<Entity>> m_entities;
  };

}

#endif // ES_GLOBAL_SYSTEM_H