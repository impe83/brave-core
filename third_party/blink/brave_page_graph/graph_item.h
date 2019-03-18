/* Copyright (c) 2019 The Brave Software Team. Distributed under the MPL2
 * license. This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_H_
#define BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_H_

#include <string>
#include "brave/third_party/blink/brave_page_graph/graphml.h"
#include "brave/third_party/blink/brave_page_graph/types.h"

using ::std::string;

namespace brave_page_graph {

class PageGraph;

class GraphItem {
 public:
  GraphItem() = delete;
  virtual ~GraphItem();
  virtual string ToString() const;
  virtual string ItemName() const = 0;
  PageGraphId Id() const;

  virtual string GraphMLId() const = 0;
  virtual GraphMLXML GraphMLTag() const = 0;

 protected:
  GraphItem(const PageGraph* graph, const PageGraphId id);
  virtual string ToStringBody() const;
  virtual string ToStringPrefix() const = 0;
  virtual string ToStringSuffix() const = 0;
  virtual GraphMLXMLGroup GraphMLAttributes() const;

  const PageGraph* graph_;
  const PageGraphId id_; 
};

}

#endif  // BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_H_
