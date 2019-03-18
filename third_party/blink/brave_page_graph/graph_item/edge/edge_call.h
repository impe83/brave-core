/* Copyright (c) 2019 The Brave Software Team. Distributed under the MPL2
 * license. This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_CALL_H_
#define BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_CALL_H_

#include <string>
#include <vector>
#include "brave/third_party/blink/brave_page_graph/graphml.h"
#include "brave/third_party/blink/brave_page_graph/graph_item/edge.h"
#include "brave/third_party/blink/brave_page_graph/types.h"

using ::std::string;
using ::std::vector;

namespace brave_page_graph {

class Node;
class NodeScript;
class NodeWebAPI;
class PageGraph;

class EdgeCall final : public virtual Edge {
friend class PageGraph;
 public:
  EdgeCall() = delete;
  ~EdgeCall() override;
  string ItemName() const override;
  const vector<const string>& Arguments() const;
  string ArgumentsString() const;

 protected:
  EdgeCall(const PageGraph* graph, const PageGraphId id,
    const NodeScript* const out_node, const NodeWebAPI* const in_node,
    const string& method, const vector<const string>& arguments);
  string ToStringBody() const override;
  GraphMLXMLGroup GraphMLAttributes() const override;

  const string method_;
  const vector<const string> arguments_;
};

}  // namespace brave_page_graph

#endif  // BRAVE_COMPONENTS_BRAVE_PAGE_GRAPH_GRAPH_ITEM_EDGE_EDGE_CALL_H_
