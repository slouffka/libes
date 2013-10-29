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
#ifndef ES_EVENT_HANDLER_H
#define ES_EVENT_HANDLER_H

#include "Entity.h"
#include "Event.h"

namespace es {

  /**
   * @brief The status of an event handler at the end.
   */
  enum class EventStatus {
    KEEP, /**< The handler must be kept */
    DIE,  /**< The handler can be removed */
  };

  /**
   * @brief An event handler.
   */
  class EventHandler {
  public:
    /**
     * @brief Destroy the handler.
     *
     * It is made virtual in order to prevent memory leaks.
     */
    virtual ~EventHandler();

    /**
     * @brief Handle an event.
     *
     * @param origin the entity that triggers the event
     * @param type the event type
     * @param event the event parameters
     * @return the status of the handler at the end
     */
    virtual EventStatus onEvent(Entity origin, EventType type, Event *event) = 0;
  };

}

#endif // ES_EVENT_HANDLER_H
